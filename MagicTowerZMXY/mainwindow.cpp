#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPen>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QBackgound直接头文件声明+此处引用
    bg=new QBackGround(this);
    talk= new QTalk(this);
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
