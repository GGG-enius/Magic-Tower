#include "qinfo.h"
#include <QDebug>

QInfo::QInfo(QWidget *parent)
    :  QWidget{parent},borderColor(Qt::darkGray), borderWidth(5)
{
    this->isActive=false;

    connect(this,&QInfo::infoUpdated,[=](ROLEINFO info,QString name){
        this->setRoleInfo(info);
        this->setSceneName(name);
    });
    InfoRect.setRect(32, 50, 5 * 32,MAP_HEIGHT * 32);
    MainRect.setRect(250,50,MAP_WIDTH * 32,MAP_HEIGHT * 32);
}
QInfo::~QInfo()
{
}
void QInfo::drawBorder(QPainter &painter, const QRect &rect)
{
    QRect tiledRect = rect;
    for (int i = 0; i < rect.width() / TILE_WIDTH; ++i) {
        for (int j = 0; j < rect.height() / TILE_HEIGHT; ++j) {
            tile->draw(painter, tiledRect.left()+i * TILE_WIDTH, tiledRect.top()+ j * TILE_HEIGHT, TILE_FLOOR);
        }
    }
    if(rect.contains(this->MainRect))
    {
        QPen pen(Qt::white);
        pen.setWidth(2);
        painter.setPen(pen);
        painter.drawRect(rect.adjusted(-2,-2,1,1));
    }else{
    QPen pen(borderColor);
    pen.setWidth(borderWidth);
    painter.setPen(pen);
    painter.drawRect(rect);
    }
}

void QInfo::onDraw(QPainter &painter, const QRect &rect, const ROLEINFO &roleInfo, const QString &sceneName)
{
    QRect infoRects[4] = {
        QRect(32, 45, 32 * 5, 32 * 4),
        QRect(32, 180, 32 * 5, 32 * 3),
        QRect(32, 280, 32 * 5, 32),
        QRect(32, 333, 32 * 5, 32 * 2)
    };

    for (const QRect &infoRect : infoRects) {
        drawBorder(painter, infoRect);
    }

    QFont font("幼圆", 12);
    painter.setFont(font);
    painter.setPen(Qt::white);
    painter.setBackgroundMode(Qt::TransparentMode);


    int nInfoLeft = 32;
    int nInfoStart = 40;
    int nInfoInterval = 16;

    // Info Rect 1
    painter.drawRect(infoRects[0]);
    tile->draw(painter, infoRects[0].left() + nInfoLeft, infoRects[0].top() + 4, 127);
    painter.drawText(infoRects[0].left() + nInfoLeft, infoRects[0].top() + 26, QString("      %1 级").arg(roleInfo.nLevel));
    painter.drawText(infoRects[0].left() + nInfoLeft, infoRects[0].top() +14+ nInfoStart + nInfoInterval * 0, QString("生命   %1").arg(roleInfo.nHealth));
    painter.drawText(infoRects[0].left() + nInfoLeft, infoRects[0].top() +14+ nInfoStart + nInfoInterval * 1, QString("攻击   %1").arg(roleInfo.nAttack));
    painter.drawText(infoRects[0].left() + nInfoLeft, infoRects[0].top() +14+ nInfoStart + nInfoInterval * 2, QString("防御   %1").arg(roleInfo.nDefense));
    painter.drawText(infoRects[0].left() + nInfoLeft, infoRects[0].top() +14+ nInfoStart + nInfoInterval * 3, QString("金币   %1").arg(roleInfo.nMoney));
    painter.drawText(infoRects[0].left() + nInfoLeft, infoRects[0].top() +14+ nInfoStart + nInfoInterval * 4, QString("经验   %1").arg(roleInfo.nExperience));

    // Info Rect 2
    painter.drawRect(infoRects[1]);
    tile->draw(painter, infoRects[1].left() + nInfoLeft-10, infoRects[1].top() +5+ 0, 37);
    tile->draw(painter, infoRects[1].left() + nInfoLeft-10, infoRects[1].top() + 32, 38);
    tile->draw(painter, infoRects[1].left() + nInfoLeft-10, infoRects[1].top() -5+ 64, 39);
    painter.drawText(infoRects[1].left() + nInfoLeft * 3-20, infoRects[1].top()+14+8, QString("%1 个").arg(roleInfo.nYellowKey));
    painter.drawText(infoRects[1].left() + nInfoLeft * 3-20, infoRects[1].top() +14+ 40, QString("%1 个").arg(roleInfo.nBlueKey));
    painter.drawText(infoRects[1].left() + nInfoLeft * 3-20, infoRects[1].top() +14+ 72, QString("%1 个").arg(roleInfo.nRedKey));

    // Info Rect 3
    painter.drawRect(infoRects[2]);
    painter.drawText(infoRects[2].left() + nInfoLeft + 25, infoRects[2].top() +14+ 8, sceneName);

    // Info Rect 4
    painter.drawRect(infoRects[3]);
    painter.drawText(infoRects[3].left() + 12, infoRects[3].top() + 18, "S 保存");
    painter.drawText(infoRects[3].left() + nInfoLeft * 2 + 12, infoRects[3].top() + 18, "Q 退出程序");
    painter.drawText(infoRects[3].left() + 12, infoRects[3].top() + 50, "A 读取");
    painter.drawText(infoRects[3].left() + nInfoLeft * 2 + 12, infoRects[3].top() + 50, "R 重新开始");
}

// ROLEINFO QInfo::getRoleInfo() const
// {
//     return roleInfo;
// }

void QInfo::setRoleInfo(const ROLEINFO &newRoleInfo)
{
    roleInfo = newRoleInfo;
}

void QInfo::setSceneName(const QString &newSceneName)
{
    sceneName = newSceneName;
}

void QInfo::setActive(bool value)
{
    this->isActive=value;
}
void QInfo::paintEvent(QPaintEvent *event)
{
    if(this->isActive)
    {
        setFixedSize(MAX_WIDTH,MAX_HEIGHT);
        QPainter painter(this);
        drawBorder(painter,MainRect);
        onDraw(painter,InfoRect,this->roleInfo,this->sceneName);
    }
    QWidget::paintEvent(event);
}
