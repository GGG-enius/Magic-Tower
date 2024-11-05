#include "qfight.h"

QFight::QFight(QWidget *parent)
    : QWidget{parent}
{
    this->isActive=false;
    nTileIndex = 0;
    bAttack = true;
    fightTimer = new QTimer(this);
    scenceTimer = new QTimer(this);
    tile = new QTile(this);

    this->fightSound = new QSoundEffect(this);


    connect(fightTimer, &QTimer::timeout, [=](){
        this->fightOnTimer();
    });
    connect(scenceTimer, &QTimer::timeout, this, &QFight::scenceOnTimer);
    connect(this,&QFight::fightEnd,[=](){
        this->hide();
        // qDebug()<<"|||||||||||||||||";
        this->isActive=false;
        this->fightSound->stop();
    });
}

void QFight::load(INDEX idTile[], NPCINFO npcInfo, ROLEINFO roleInfo)
{
    for(int i=0;i<MAX_NPC_TILE;i++)
    {
        m_idTile[i] = idTile[i];
    }
    m_RoleInfo = roleInfo;
    m_NpcInfo = npcInfo;
    this->show();
    this->startFightTimer();
    this->startSceneTimer();
    this->isActive=true;
    this->fightSound->setSource(QUrl::fromLocalFile(SOUND_FIGHT_FILE));
    this->fightSound->play();
    this->fightSound->setLoopCount(QSoundEffect::Infinite);
}

//战斗计时，更改生命数值，实现战斗
bool QFight::fightOnTimer()
{
    //对于扣血逻辑，只有当攻击力大于对方的防御力时，才对对方的生命值产生影响

    if(bAttack==true)
    {
        // qDebug()<<"主角攻击回合：";
        // qDebug()<<"主角攻击值:"<<m_RoleInfo.nAttack;
        // qDebug()<<"npc防御值:"<<m_NpcInfo.nDefense;
        //如果角色的攻击力大于怪物的防御力，将差值从怪物的生命值中扣除
        if(m_RoleInfo.nAttack - m_NpcInfo.nDefense > 0)
        {
            m_NpcInfo.nHealth -= (m_RoleInfo.nAttack - m_NpcInfo.nDefense);
            // qDebug()<<"npc剩余血量："<<m_NpcInfo.nHealth;
        }
    }
    else//类似地，怪物作为攻击者时使用其攻击和角色的防御力进行比较和计算
    {
        // qDebug()<<"npc攻击回合：";
        // qDebug()<<"npc攻击值："<<m_NpcInfo.nAttack;
        // qDebug()<<"主角防御值："<<m_RoleInfo.nDefense;
        if(m_NpcInfo.nAttack - m_RoleInfo.nDefense > 0)
        {
            m_RoleInfo.nHealth -= (m_NpcInfo.nAttack - m_RoleInfo.nDefense);
            // qDebug()<<"主角剩余血量："<<m_RoleInfo.nHealth;
        }
    }
    bAttack = !bAttack;//每次攻击后，切换到另一方进行攻击
    if(m_RoleInfo.nHealth<=0||m_NpcInfo.nHealth<=0)//如果一方生命值小于等于零，则停止战斗定时器
    {
        bAttack = true;
        this->stopFightTimer();
        this->stopSceneTimer();
        // qDebug()<<"--------------------------";f
        emit this->fightEnd();
        return false;//战斗结束
    }
    return true;//战斗未结束
}

//场景计时, 更改TILE索引, 实现动画
bool QFight::scenceOnTimer()
{
    nTileIndex = (nTileIndex + 1) % MAX_NPC_TILE;
    return true;
}

//处理按键事件的逻辑，目前总是返回 TRUE，意味着按键会被处理
bool QFight::handleKeyPressEvent(QKeyEvent *)
{
    if(this->isActive==false){
        return false;
    }
    return true;
}

void QFight::paintEvent(QPaintEvent *event)
{
    if(this->isActive)
    {
        QPainter painter(this);
        //CRect：定义绘制区域，起始点为 (100, 100)，区域大小为 15 * TILE_WIDTH 和 8 * TILE_HEIGHT
        QRect rect(QPoint(100, 100), QSize(15 * TILE_WIDTH, 8 * TILE_HEIGHT));
        setFixedSize(MAX_WIDTH,MAX_HEIGHT);
        //循环遍历整个区域，用 Tile.Draw 绘制地板图块 TILE_FLOOR，绘制成一个区域
        for(int i=0;i<rect.width()/TILE_WIDTH;i++)
        {
            for(int j=0;j<rect.height()/TILE_HEIGHT;j++)
            {
                tile->draw(painter, rect.left() + i * TILE_WIDTH, rect.top() + j * TILE_HEIGHT, TILE_FLOOR);
            }
        }
        //画边框
        QPen pen(QColor(BORDER_COLOR));
        painter.setPen(pen);
        int nBorderWidth = 5;//边框厚度
        for(int i=0;i<nBorderWidth;i++)
        {
            rect.adjust(1, 1, -1, -1);
            painter.drawRect(rect);
        }
        tile->draw(painter,rect.left() + TILE_WIDTH, rect.top() + TILE_HEIGHT / 2, 127);//画左上角那个主角标
        tile->draw(painter,rect.right() - TILE_WIDTH * 2, rect.top() + TILE_HEIGHT / 2, m_idTile[nTileIndex]);//画右上角那个怪物标
        //设置字体
        int nFontSize = 16;
        QFont font("仿宋体", nFontSize);
        painter.setFont(font);
        QColor textColor(255, 180, 0);
        painter.setPen(textColor);

        //主角
        //写字
        painter.drawText(rect.left() + 2.5 * TILE_WIDTH, rect.top() + TILE_HEIGHT * 1.5, "孙悟空");
        painter.drawText(rect.left() + 1 * TILE_WIDTH, 100 + TILE_HEIGHT * 2.5, "生命值");
        painter.drawText(rect.left() + 1 * TILE_WIDTH, 100 + TILE_HEIGHT * 4.5, "攻击力");
        painter.drawText(rect.left() + 1 * TILE_WIDTH, 100 + TILE_HEIGHT * 6.5,"防御力");

        painter.drawText(rect.left() + 4.5 * TILE_WIDTH, 100 + TILE_HEIGHT * 3.5, QString::number(m_RoleInfo.nHealth));
        painter.drawText(rect.left() + 4.5 * TILE_WIDTH, 100 + TILE_HEIGHT * 5.5, QString::number(m_RoleInfo.nAttack));
        painter.drawText(rect.left() + 4.5 * TILE_WIDTH, 100 + TILE_HEIGHT * 7.5, QString::number(m_RoleInfo.nDefense));

        //分割线
        painter.setPen(QPen(QColor(160, 160, 160), 3));
        painter.drawLine(rect.left() + 1 * TILE_WIDTH, 100 + TILE_HEIGHT * 3 - 4, rect.left() + 6 * TILE_WIDTH, 100 + TILE_HEIGHT * 3 - 4);
        painter.drawLine(rect.left() + 1 * TILE_WIDTH, 100 + TILE_HEIGHT * 5 - 4, rect.left() + 6 * TILE_WIDTH, 100 + TILE_HEIGHT * 5 - 4);
        painter.drawLine(rect.left() + 1 * TILE_WIDTH, 100 + TILE_HEIGHT * 7 - 4, rect.left() + 6 * TILE_WIDTH, 100 + TILE_HEIGHT * 7 - 4);

        //敌人
        //写字
        painter.setPen(textColor);
        painter.drawText(rect.right() - 3.5 * TILE_WIDTH, rect.top() + TILE_HEIGHT * 1.5, "怪物");
        painter.drawText(rect.right() - 3 * TILE_WIDTH, 100 + TILE_HEIGHT * 2.5, "生命值");
        painter.drawText(rect.right() - 3 * TILE_WIDTH, 100 + TILE_HEIGHT * 4.5, "攻击力");
        painter.drawText(rect.right() - 3 * TILE_WIDTH, 100 + TILE_HEIGHT * 6.5, "防御力");

        painter.drawText(rect.right() - 4.5 * TILE_WIDTH, 100 + TILE_HEIGHT * 3.5, QString::number(m_NpcInfo.nHealth));
        painter.drawText(rect.right() - 4.5 * TILE_WIDTH, 100 + TILE_HEIGHT * 5.5, QString::number(m_NpcInfo.nAttack));
        painter.drawText(rect.right() - 4.5 * TILE_WIDTH, 100 + TILE_HEIGHT * 7.5, QString::number(m_NpcInfo.nDefense));

        //分割线
        painter.setPen(QPen(QColor(160, 160, 160), 3));
        painter.drawLine(rect.right() - 1 * TILE_WIDTH, 100 + TILE_HEIGHT * 3 - 4, rect.right() - 6 * TILE_WIDTH, 100 + TILE_HEIGHT * 3 - 4);
        painter.drawLine(rect.right() - 1 * TILE_WIDTH, 100 + TILE_HEIGHT * 5 - 4, rect.right() - 6 * TILE_WIDTH, 100 + TILE_HEIGHT * 5 - 4);
        painter.drawLine(rect.right() - 1 * TILE_WIDTH, 100 + TILE_HEIGHT * 7 - 4, rect.right() - 6 * TILE_WIDTH, 100 + TILE_HEIGHT * 7 - 4);
    }
    QWidget::paintEvent(event);
}

ROLEINFO QFight::getResult()
{
    return m_RoleInfo;
}

void QFight::startFightTimer()
{
    fightTimer->start(300);
}

void QFight::stopFightTimer()
{
    this->fightTimer->stop();

}

void QFight::startSceneTimer()
{
    this->scenceTimer->start(300);
}

void QFight::stopSceneTimer()
{
    this->scenceTimer->stop();
}




