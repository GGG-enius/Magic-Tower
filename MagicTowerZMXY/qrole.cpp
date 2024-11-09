 #include "qrole.h"

//定义并初始化一个静态数组用于存储角色TILE信息
//站立，行走1,2, 在战中被打
INDEX QRole::idTiles[MAX_ROLE_TILE] = {
    131, 132, 133, 134,			//左
    127, 128, 129, 130,			//上
    135, 136, 137, 138,			//右
    139, 140, 141, 142,			//下
    423, 424, 425, 426,         //待机右
    427, 428, 429, 430,         //待机左
    431, 432, 433, 434,         //上左
    435, 436, 437, 438          //下左

};

QRole::QRole(QWidget *parent)
    : QWidget{parent}
{
    m_ptPos = QPoint(5, 9);//Role最开始被载入时的坐标信息
    m_rtWalk.setRect(0, 0, MAP_WIDTH, MAP_HEIGHT);
    m_nTileIndex = 4;//初始化玩家角色最初站立状态
    //初始化角色属性结构体成员
    RoleInfo.nLevel = 1;
    RoleInfo.nHealth = 1;
    RoleInfo.nAttack = 1111;
    RoleInfo.nDefense = 0;
    RoleInfo.nMoney = 0;
    RoleInfo.nExperience = 0;
    RoleInfo.nYellowKey = 31;
    RoleInfo.nBlueKey = 1;
    RoleInfo.nRedKey = 1;
    this->isleft=false;
    timer_role = new QTimer(this);
    animationTimer=new QTimer(this);
    connect(animationTimer,&QTimer::timeout,[=](){
        int tmp = (m_nTileIndex)%3;
        // qDebug()<<m_nTileIndex;
        if(isleft)
        {
            m_nTileIndex=(tmp+19);
            // qDebug()<<m_nTileIndex;
        }else{
            m_nTileIndex=(tmp+16);
            // qDebug()<<m_nTileIndex;
        }
        m_nTileIndex++;
    });
    connect(timer_role, &QTimer::timeout, this, &QRole::roleOnTimer);
    m_nTileIndex=16;
    this->setFocusPolicy(Qt::StrongFocus); // 设置窗口可以获取焦点
    this->setFocus(); // 尝试在构造时设置焦点
}

ROLEINFO QRole::getRoleInfo()
{
    return RoleInfo;
}

void QRole::SetRoleInfo(ROLEINFO Info)
{
    RoleInfo = Info;
}

QPoint QRole::getPos()
{
    return m_ptPos;
}

//用于楼梯切换时, 保持出去时与进来时的TILE方向正好相反, bTurn为真表示, 切换, 为假表示不切换
//ptPos表示新的位置。当调用本函数时，这个参数决定角色新的坐标
//idTile表示角色的当前图块索引类型
//bTurn表示是否在楼梯切换时改变角色朝向
void QRole::setPos(QPoint ptPos, INDEX index, bool bTurn)
{
    //获取对应于idTile的图块索引nTileIndex
    int nTileIndex = getTileIndex(index);
    //如果bTurn为true，切换方向，计算m_nTileIndex新值如下
    if(bTurn)
    {
        m_nTileIndex = ((nTileIndex / 4) * 4  + 2 + MAX_ROLE_TILE / 2) % MAX_ROLE_TILE;
    }
    else
    {
        m_nTileIndex = ((nTileIndex / 4) * 4  + 2 + MAX_ROLE_TILE / 2) % MAX_ROLE_TILE;
    }
    //更新角色位置
    m_ptPos = ptPos;
}

INDEX QRole::getRoleTileID()
{
    return idTiles[m_nTileIndex];
}

bool QRole::isRoleTileID(IDTILE idTile)
{

    if(TILE_ROLE==idTile)
    {
        return true;
    }
    return false;
}

//当定时器被触发时，调用此函数，更改图块索引，实现行走效果
void QRole::roleOnTimer()
{
    m_nTileIndex--;
    // qDebug()<<"定时器被调用";
    // qDebug()<<m_nTileIndex;
    //如果图块索引能被 4 整除，则停止定时器，即角色停止行走
    if(m_nTileIndex%4==0)
    {
        timer_role->stop();
        if(m_nTileIndex==0){
            this->isleft=true;
            m_nTileIndex=21;
        }else if(m_nTileIndex==8){
            this->isleft=false;
            m_nTileIndex=16;
        }
        this->startRoleTimer();
    }
}

QPoint QRole::getNextPoint(QKeyEvent *event)
{
    //初始化一个新的QPoint变量，初值设为当前角色位置m_ptPos
    QPoint r_ptPos = m_ptPos;
    switch(event->key()){
        case Qt::Key_Up:
            r_ptPos.setY(r_ptPos.y()-1);
            if(this->isleft)
            {
                m_nTileIndex=25;
            }else
            m_nTileIndex = 6;
            break;
        case Qt::Key_Down:
            r_ptPos.setY(r_ptPos.y() + 1);
            if(this->isleft)
            {
                m_nTileIndex=29;
            }else
            m_nTileIndex = 14;
            break;
        case Qt::Key_Left:
            r_ptPos.setX(r_ptPos.x() - 1);
            m_nTileIndex = 2;
            break;
        case Qt::Key_Right:
            r_ptPos.setX(r_ptPos.x() + 1);
            m_nTileIndex = 10;
            break;
        default:
            return m_ptPos;//按键不匹配任何方向键
    }
    this->stopRoleTimer();
    //触发行走定时器
    timer_role->start(200);
    //检查新坐标r_ptPos是否在m_rtWalk区域内
    if(m_rtWalk.contains(r_ptPos))
    {
        return r_ptPos;
    }
    else
    {
        return m_ptPos;//超范围
    }
}

void QRole::moveTo(QPoint ptPos)
{
    m_ptPos = ptPos;
}

void QRole::startRoleTimer()
{
    this->animationTimer->start(150);
}

void QRole::stopRoleTimer()
{
    this->animationTimer->stop();
}

//获取角色图块ID在idTiles数组中的索引
//如果存在返回索引 如果不存在返回默认值4
int QRole::getTileIndex(INDEX index)
{
    for(int i=0;i<MAX_ROLE_TILE;i++)
    {
        if(idTiles[i]==index)
        {
            return i;
        }
    }
    return 4;
}
