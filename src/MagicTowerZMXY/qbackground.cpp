#include "qbackground.h"
#include <QDebug>
QBackGround::QBackGround(QWidget *parent)
    : QWidget{parent}
{
    this->isActive=false;
    tile=new QTile(this);

}


void QBackGround::paintEvent(QPaintEvent *event)
{
    if(this->isActive)
    {
        //绘制大小
        setFixedSize(MAX_WIDTH,460);
        QPainter painter(this);
        // //绘制背景
        int i, j;
        for(i = 0; i < MAX_WIDTH / TILE_WIDTH + 1; i++)
        {
            for(j = 0; j < MAX_HEIGHT / TILE_HEIGHT; j++)
            {
                tile->draw(painter, i * TILE_WIDTH, j * TILE_HEIGHT, TILE_BG);
            }
        }
    }
    QWidget::paintEvent(event);
}

void QBackGround::setActive(bool value)
{
    this->isActive=value;
}







/*paintEvent————————test
    //背景图片导入:/bg.jpg
    //painter.drawPixmap(0,0,QPixmap(":/bg.jpg"));
    //painter.drawImage(MAX_WIDTH/2,MAX_HEIGHT/2,QImage(":/pictruetest.png"));
    //tile->draw(painter,0,0,138);


    //qinfo 测试
    //初始化对象定义
<<<<<<< Updated upstream
    // MainRect.setRect(250,50,MAP_WIDTH * 32,MAP_HEIGHT * 32);
    // //painter.drawRect(MainRect);
    // if (!info || !tile) {
    //     qWarning() << "info or tile is null";
    //     return;
    // }
    // info->drawBorder(painter,MainRect);
    // //定义结构体
    // ROLEINFO myStruct;
    // InfoRect.setRect(32, 50, 5 * 32,MAP_HEIGHT * 32);
    // info->onDraw(painter,InfoRect,myStruct,"TEST");

=======
    MainRect.setRect(250,50,MAP_WIDTH * 32,MAP_HEIGHT * 32);
    //painter.drawRect(MainRect);
    if (!info || !tile) {
        qWarning() << "info or tile is null";
        return;
    }
    info->drawBorder(painter,MainRect);
    //定义结构体
    // ROLEINFO mystruct;
    // mystruct.nLevel = 1000;
    InfoRect.setRect(32, 50, 5 * 32,MAP_HEIGHT * 32);
    //role->SetRoleInfo(mystruct);
    info->onDraw(painter,InfoRect,role->getRoleInfo(),"TEST");
    //qrole测试
    // qDebug()<<role->GetPos();
    // role->setPos(QPoint(6, 6), 152, true);
    // qDebug()<<role->GetPos()<<role->GetRoleTileID();
>>>>>>> Stashed changes
    //qtalk测试
    //talk->draw(painter);
<<<<<<< HEAD
*/



