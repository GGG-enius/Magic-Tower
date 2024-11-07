#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPen>
#include <QDebug>
#include <QPaintEvent>
#include <QPainter>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->mainSound= new QSoundEffect(this);
    this->mainSound->setSource(QUrl::fromLocalFile(SOUND_START));
    this->mainSound->play();
    this->mainSound->setLoopCount(QSoundEffect::Infinite);
    this->startMenu=new StartMenu(this);
    this->startMenu->show();

    connect(this->startMenu,&StartMenu::newStart,[=](){
        this->mainSound->stop();

        //延时进入到游戏主场景场景
        QTimer::singleShot(200,this,[=](){
            game=new QGame(this);
            game->initGame(true);
            this->startMenu->hide();
            delete this->startMenu;
            game->show();
        });
    });
    connect(this->startMenu,&StartMenu::continueGame,[=](){
        this->mainSound->stop();
        //延时进入到游戏主场景场景
        QTimer::singleShot(200,this,[=](){
            game=new QGame(this);
            QFileUtil::loadGame(*game,GAMEDATA_FILE_NAME);
            game->initGame(false);
            QTimer::singleShot(100,this,[=](){
            this->startMenu->hide();
            delete this->startMenu;
            game->show();
            });
        });
    });
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    //控制原生窗口大小
    setFixedSize(MAX_WIDTH,MAX_HEIGHT);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(!this->startMenu->isStartMenuActive())
    {
        if(this->game&&this->game->isStorying())
        {
            // qDebug()<<"???";
            switch(event->key())
            {
            case Qt::Key_Space:
                // qDebug()<<"sapce";
                game->m_keyPressEvent(event);
                break;
            }
        }else if(this->game&&this->game->isGameOver())
        {
            switch(event->key())
            {
            case Qt::Key_R:
                delete game;
                game = new QGame(this);
                game->initGame(true);
                game->show();
                break;
            case Qt::Key_Q:
                exit(0);
            }
        }
        else{
            // qDebug()<<"\\\\\\\\\\]";
            switch(event->key())
            {
            case Qt::Key_Q:
                //保存游戏
                QFileUtil::saveGame(*game,GAMEDATA_FILE_NAME);
                qDebug()<<"保存成功";
                exit(0);
                break;
            case Qt::Key_S:
                QFileUtil::saveGame(*game,GAMEDATA_FILE_NAME);
                qDebug()<<"保存成功";
                break;
            case Qt::Key_A:
                delete game;
                game = new QGame(this);
                QFileUtil::loadGame(*game,GAMEDATA_FILE_NAME);
                game->initGame(false);
                game->show();
                qDebug()<<"读取成功";
                break;
            default:
                if(!game->m_keyPressEvent(event))
                {
                    delete game;
                    game = new QGame(this);
                    game->initGame(true);
                    game->show();
                }
                break;
            }
        }
    }
    else{

    }
}
