#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPen>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QBackgound直接头文件声明+此处引用
    story=new QStory(this);
    //story->init();
    bg=new QBackGround(this);
    info=new QInfo(this);
    talk= new QTalk(this);
    //game=new QGame(this);
    //story->STORY_DRAW=1;
    bg->BG_DRAW=1;
    talk->TALK_DRAW=1;
    info->INFO_DRAW=1;
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    //控制原生窗口大小
    setFixedSize(MAX_WIDTH,MAX_HEIGHT);
}
