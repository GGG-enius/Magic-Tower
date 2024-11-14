#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPen>
#include <QFont>
#include <QDebug>
#include <QPaintEvent>
#include <QPainter>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->mainSound= new QSoundEffect(this);
    // game = new QGame(this);
    // this->statusBarRoleInfo=new QLabel;
    // this->statusBarRoleInfo->setAlignment(Qt::AlignCenter);
    this->mainSound->setSource(QUrl::fromLocalFile(SOUND_START));
    this->mainSound->play();
    this->mainSound->setLoopCount(QSoundEffect::Infinite);
    this->endSound= new QSoundEffect(this);
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
            connect(game,&QGame::victory,[=](){
                this->installEventFilter(this);
                this->end = new End(this);
                this->end->show();
                // this->end->hide();
                game->hide();
                update();

                this->endSound->setSource(QUrl::fromLocalFile(SOUND_BG_FILE7));
                this->endSound->play();
                this->endSound->setLoopCount(QSoundEffect::Infinite);
                QTimer::singleShot(1500,this,[=](){
                    this->end->playEndVideo();
                });

                QTimer::singleShot(20000,this,[=](){
                    delete this->game;
                    // qDebug()<<"??";
                });
            });
            //qgame和主窗口连接更新状态栏
            connect(game, &QGame::updateStatusBar, this, &MainWindow::handleStatusBarUpdate);
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
                connect(game,&QGame::victory,[=](){
                    this->installEventFilter(this);
                    this->end = new End(this);
                    this->end->show();
                    // this->end->hide();
                    game->hide();
                    update();

                    this->endSound->setSource(QUrl::fromLocalFile(SOUND_BG_FILE7));
                    this->endSound->play();
                    this->endSound->setLoopCount(QSoundEffect::Infinite);
                    QTimer::singleShot(1500,this,[=](){
                        this->end->playEndVideo();
                    });

                    QTimer::singleShot(20000,this,[=](){
                        delete this->game;
                        // qDebug()<<"??";
                    });
                });
            //qgame和主窗口连接更新状态栏
            connect(game, &QGame::updateStatusBar, this, &MainWindow::handleStatusBarUpdate);
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
    QPainter painter(this);
    QPixmap pixmap;
    if(this->end&&this->end->isActiving())
    {
        painter.fillRect(this->rect(), Qt::black);
    }else{
        pixmap.load(":/res/Image/BG/startBG.png");
        painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
    }
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
                connect(game,&QGame::victory,[=](){
                    this->installEventFilter(this);
                    this->end = new End(this);
                    this->end->show();
                    // this->end->hide();
                    game->hide();
                    update();

                    this->endSound->setSource(QUrl::fromLocalFile(SOUND_BG_FILE7));
                    this->endSound->play();
                    this->endSound->setLoopCount(QSoundEffect::Infinite);
                    QTimer::singleShot(1500,this,[=](){
                        this->end->playEndVideo();
                    });

                    QTimer::singleShot(20000,this,[=](){
                        delete this->game;
                        // qDebug()<<"??";
                    });
                });
                //qgame和主窗口连接更新状态栏
                connect(game, &QGame::updateStatusBar, this, &MainWindow::handleStatusBarUpdate);
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
                this->handleStatusBarUpdate("存档成功!");
                // qDebug()<<"保存成功";
                exit(0);
                break;
            case Qt::Key_S:
                QFileUtil::saveGame(*game,GAMEDATA_FILE_NAME);
                // qDebug()<<"保存成功";
                this->handleStatusBarUpdate("存档成功!");
                break;
            case Qt::Key_A:
                if(this->isFileEmpty(GAMEDATA_FILE_NAME)){
                    this->handleStatusBarUpdate("没有存档,读取失败!");
                    return;
                }
                delete game;
                game = new QGame(this);
                QFileUtil::loadGame(*game,GAMEDATA_FILE_NAME);
                game->initGame(false);
                connect(game,&QGame::victory,[=](){
                    this->installEventFilter(this);
                    this->end = new End(this);
                    this->end->show();
                    // this->end->hide();
                    game->hide();
                    update();

                    this->endSound->setSource(QUrl::fromLocalFile(SOUND_BG_FILE7));
                    this->endSound->play();
                    this->endSound->setLoopCount(QSoundEffect::Infinite);
                    QTimer::singleShot(1500,this,[=](){
                        this->end->playEndVideo();
                    });

                    QTimer::singleShot(20000,this,[=](){
                        delete this->game;
                        // qDebug()<<"??";
                    });
                });
                //qgame和主窗口连接更新状态栏
                connect(game, &QGame::updateStatusBar, this, &MainWindow::handleStatusBarUpdate);
                game->show();
                this->handleStatusBarUpdate("读档成功!");
                // qDebug()<<"读取成功";
                break;
            default:
                if(!game->m_keyPressEvent(event))
                {
                    delete game;
                    game = new QGame(this);
                    game->initGame(true);
                    connect(game,&QGame::victory,[=](){
                        this->installEventFilter(this);
                        this->end = new End(this);
                        this->end->show();
                        // this->end->hide();
                        game->hide();
                        update();

                        this->endSound->setSource(QUrl::fromLocalFile(SOUND_BG_FILE7));
                        this->endSound->play();
                        this->endSound->setLoopCount(QSoundEffect::Infinite);
                        QTimer::singleShot(1500,this,[=](){
                            this->end->playEndVideo();
                        });

                        QTimer::singleShot(20000,this,[=](){
                            delete this->game;
                            // qDebug()<<"??";
                        });
                    });
                    //qgame和主窗口连接更新状态栏
                    connect(game, &QGame::updateStatusBar, this, &MainWindow::handleStatusBarUpdate);
                    game->show();
                }
                break;
            }
        }
    }
    else{

    }
}

void MainWindow::handleStatusBarUpdate(const QString &message)
{
    if(this->statusBarRoleInfo){
        ui->statusbar->removeWidget(this->statusBarRoleInfo);
        delete this->statusBarRoleInfo;
        this->statusBarRoleInfo=nullptr;
    }
    this->statusBarRoleInfo =new QLabel(message);
    // this->statusBarRoleInfo->setText(message);
    // ui->statusbar->showMessage(message, 5000);

    QFont font("Algerian");
    // font.setPointSize(10);
    font.setBold(true);
    this->statusBarRoleInfo->setFont(font);
    this->statusBarRoleInfo->setAlignment(Qt::AlignCenter);
    ui->statusbar->addWidget(this->statusBarRoleInfo,1);
    QTimer::singleShot(5000,[=](){
        ui->statusbar->removeWidget(this->statusBarRoleInfo);
        delete this->statusBarRoleInfo;
        this->statusBarRoleInfo=nullptr;
    });
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if(event->type()==QEvent::KeyPress||event->type()==QEvent::KeyRelease)
    {
        return true;
    }
    return QWidget::eventFilter(obj,event);
}

bool MainWindow::isFileEmpty(const QString &filePath)
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


