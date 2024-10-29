#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPen>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QBackgound直接头文件声明+此处引用

    //该处改变焦点会覆盖上一个声明的焦点ps：qtalk
    talk= new QTalk(this);
    story=new QStory(this);

    story->init();
    talk->initkey();
    bg=new QBackGround(this);
    info=new QInfo(this);

    //game=new QGame(this);
    //story->STORY_DRAW=1;
    //story->STORY_KEY=1;
     //bg->BG_DRAW=1;
    talk->TALK_DRAW=1;
    talk->TALK_KEY=1;
    //info->INFO_DRAW=1;
    //role = new QRole(this);
    //tile = new QTile(this);
    tile->initTile();
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    //控制原生窗口大小
    setFixedSize(MAX_WIDTH,MAX_HEIGHT);
    //qrole测试
    // IDTILE idRoleTile = role->getRoleTileID();
    // //qDebug()<<idRoleTile;
    // QPoint ptRolePos = role->getPos();
    // //qDebug()<<ptRolePos;
    // QPainter painter(this);
    // tile->draw(painter, ptRolePos.x()*TILE_WIDTH, ptRolePos.y()*TILE_HEIGHT, idRoleTile);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    //qrole测试
    // // 使用 static_cast 将 int 转换为 Qt::Key
    // Qt::Key key = static_cast<Qt::Key>(event->key());
    // QPoint newPoint = role->getNextPoint(key);
    // qDebug() << "New position:" << newPoint;
    // //qDebug()<<role->getTileIndex(role->getRoleTileID());
    // role->moveTo(newPoint);
    // QWidget::keyPressEvent(event);
}
