#include "qbackground.h"

QBackGround::QBackGround(QWidget *parent)
    : QWidget{parent}
{
    tile=new QTile(this);
    info= new QInfo(this);
    talk=new QTalk(this);
    tile->initTile();
}
QBackGround::~QBackGround() {
}


void QBackGround::paintEvent(QPaintEvent *event)
{
    //绘制大小
    setFixedSize(MAX_WIDTH,MAX_HEIGHT);
    QPainter painter(this);
    //test_背景大小和宽度
    // QBrush brush(Qt::green);
    // painter.setBrush(brush);
    // painter.drawRect(0,0,MAX_WIDTH,MAX_HEIGHT);
    // //绘制背景
    int i, j;
    for(i = 0; i < MAX_WIDTH / TILE_WIDTH + 1; i++)
    {
        for(j = 0; j < MAX_HEIGHT / TILE_HEIGHT; j++)
        {
            tile->draw(painter, i * TILE_WIDTH, j * TILE_HEIGHT, TILE_BG);
        }
    }

    //背景图片导入:/bg.jpg
    //painter.drawPixmap(0,0,QPixmap(":/bg.jpg"));
    //painter.drawImage(MAX_WIDTH/2,MAX_HEIGHT/2,QImage(":/pictruetest.png"));
    tile->draw(painter,0,0,138);


    //qinfo 测试
    //初始化对象定义
    MainRect.setRect(250,50,MAP_WIDTH * 32,MAP_HEIGHT * 32);
    //painter.drawRect(MainRect);
    if (!info || !tile) {
        qWarning() << "info or tile is null";
        return;
    }
    info->drawBorder(painter,MainRect);
    //定义结构体
    ROLEINFO myStruct;
    InfoRect.setRect(32, 50, 5 * 32,MAP_HEIGHT * 32);
    info->onDraw(painter,InfoRect,myStruct,"TEST");

    //qtalk测试
    talk->draw(painter);
}
