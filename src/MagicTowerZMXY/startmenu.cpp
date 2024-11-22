#include "startmenu.h"
#include "ui_startmenu.h"
#include <QButtonGroup>
#include <QPixmap>
#include <QPropertyAnimation>
#include <QDebug>
#include <QFile>
StartMenu::StartMenu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StartMenu)
{
    ui->setupUi(this);
    this->isActive=true;

    QButtonGroup* group=new QButtonGroup(this);
    group->setExclusive(true);
    group->addButton(ui->selBtn1);
    group->addButton(ui->selBtn2);
    connect(ui->selBtn1,&QPushButton::clicked,[=](){
        this->zoomDown(ui->selBtn1);
        this->zoomUp(ui->selBtn1);
        emit this->newStart();
        this->isActive=false;
        // ui->selBtn1->installEventFilter(this);
        // ui->selBtn2->installEventFilter(this);
    });
    connect(ui->selBtn2,&QPushButton::clicked,[=](){
        this->zoomDown(ui->selBtn2);
        this->zoomUp(ui->selBtn2);
        emit this->continueGame();
        this->isActive=false;
        // ui->selBtn1->installEventFilter(this);
        // ui->selBtn2->installEventFilter(this);
    });
    if(isFileEmpty(GAMEDATA_FILE_NAME)){
        ui->selBtn2->setDisabled(true);
    }
}



void StartMenu::zoomDown(QAbstractButton* SelBtn)
{
    //创建动画对象
    QPropertyAnimation *animation=new QPropertyAnimation(SelBtn,"geometry");

    //设置动画时间间隔
    animation->setDuration(200);

    //起始位置
    animation->setStartValue(QRect(SelBtn->x(),SelBtn->y(),SelBtn->width(),SelBtn->height()));

    //结束位置
    animation->setEndValue(QRect(SelBtn->x(),SelBtn->y()+3,SelBtn->width(),SelBtn->height()));

    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);

    //执行动画
    animation->start();
}
void StartMenu::zoomUp(QAbstractButton* SelBtn)
{
    //创建动画对象
    QPropertyAnimation *animation=new QPropertyAnimation(SelBtn,"geometry");

    //设置动画时间间隔
    animation->setDuration(200);

    //起始位置
    animation->setStartValue(QRect(SelBtn->x(),SelBtn->y()+3,SelBtn->width(),SelBtn->height()));

    //结束位置
    animation->setEndValue(QRect(SelBtn->x(),SelBtn->y(),SelBtn->width(),SelBtn->height()));

    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);

    //执行动画
    animation->start();
}

bool StartMenu::isFileEmpty(const QString &filePath)
{
    QFile file(filePath);
    if(!file.exists()){
        qDebug()<<"文件不存在";
        return false;
    }

    if(!file.open(QIODevice::ReadOnly)){
        qDebug()<<"文件打开失败";
        return false;
    }

    bool isEmpty=(file.size()==0);
    file.close();
    return isEmpty;
}

bool StartMenu::isStartMenuActive()
{
    return this->isActive;
}

void StartMenu::setActive(bool value)
{
    this->isActive=value;
}

bool StartMenu::eventFilter(QObject *watched, QEvent *event)
{
    if(watched==ui->selBtn1||watched==ui->selBtn2)
    {
        if(event->type()==QEvent::KeyPress||event->type()==QEvent::KeyRelease){
            return true;
        }
    }
    return QWidget::eventFilter(watched,event);
}




StartMenu::~StartMenu()
{
    delete ui;
}

void StartMenu::paintEvent(QPaintEvent *)
{
    if(this->isActive)
    {
        QPainter painter(this);
        QPixmap pixmap;
        pixmap.load(":/res/Image/BG/startBG.png");
        painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
    }
}
