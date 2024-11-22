#include "end.h"

#include <QPixmap>
#include <QPainter>
#include <QFont>
End::End(QWidget *parent)
    : QWidget{parent}
{
    this->setGeometry(0,0,640,480);
    this->setStyleSheet("background-color: rgb(0, 0, 0);");
    this->setFixedSize(640,480);
    this->endAnimation=new QMediaPlayer(this);
    this->endAnimation->setSource(QUrl::fromLocalFile(XIEMU_FILE));
    this->videowidget=new QVideoWidget(this);
    this->timerAnimation=new QTimer(this);
    this->timerRole=new QTimer(this);
    this->floatAnimation=false;
    this->isActive=false;
    this->changed=false;
    // this->show();
    // this->update();
    this->endAnimation->setVideoOutput(this->videowidget);
    this->videowidget->resize(640,480);
    this->videowidget->show();
    // qDebug()<<this->endAnimation->mediaStatus();
    // this->videowidget->setGeometry(0,0,640,480);

    // qDebug()<<this->endAnimation->mediaStatus();

    // connect(endAnimation, &QMediaPlayer::mediaStatusChanged, this, [=](QMediaPlayer::MediaStatus status) {
    //     if (status == QMediaPlayer::LoadedMedia) {
    //         // 媒体加载完成
    //         // this->endAnimation->play();
    //     } else if (status == QMediaPlayer::BufferingMedia || status == QMediaPlayer::BufferedMedia) {
    //         // 媒体正在缓冲或已缓冲
    //         qDebug()<<"buffer";
    //     } else if (status == QMediaPlayer::LoadingMedia) {
    //         qDebug()<<"loading";
    //         // 媒体正在加载
    //     }
    // });


    // 连接mediaStatusChanged信号
    connect(endAnimation, &QMediaPlayer::mediaStatusChanged, [=](QMediaPlayer::MediaStatus status){
        if (status == QMediaPlayer::EndOfMedia) {
            // qDebug()<<"ok";
            this->timerAnimation->start(1000);
            this->timerRole->start(700);

            this->isActive=true;
            update();

            QTimer::singleShot(1000,this,[=](){

                this->videowidget->hide();
                // delete this->videowidget;
                // this->show();
                // this->update();
            });
        }
    });

    connect(this->timerAnimation,&QTimer::timeout,[=](){
        // qDebug()<<"---";
        this->changed=!(this->changed);
        this->update();
    });
    connect(this->timerRole,&QTimer::timeout,[=](){
        // qDebug()<<"---";
        this->floatAnimation=!(this->floatAnimation);
        this->update();
    });


    // endAnimation->connect(endAnimation, &QMediaPlayer::errorOccurred, this, &End::handleError);


    // if(this->endAnimation->isPlaying())
    // {
    //     // qDebug()<<"nb";
    // }
    // this->videowidget->show();
}

// void End::handleError(QMediaPlayer::Error error, const QString &errorString) {
//     // 处理错误
//     qDebug() << "Error occurred:" << errorString;
//     // 可以根据错误类型执行不同的操作
//     switch (error) {
//     case QMediaPlayer::ResourceError:
//         // 处理资源错误
//         break;
//     case QMediaPlayer::FormatError:
//         // 处理格式错误
//         break;
//     case QMediaPlayer::NetworkError:
//         // 处理网络错误
//         break;
//     case QMediaPlayer::AccessDeniedError:
//         // 处理权限错误
//         break;
//     default:
//         // 其他错误处理
//         break;
//     }
// }

void End::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    // painter.setBrush(QBrush(Qt::black));
    // painter.drawRect(this->rect());

    if(this->isActive)
    {
        painter.fillRect(this->videowidget->rect(), Qt::black);
        QPixmap icon(":/res/Icon/Icon0001.png");
        if(this->floatAnimation)
        {
            painter.drawPixmap((int)(this->width()*0.5-250),(int)(this->height()*0.5-94),(int)(icon.width()*0.8),(int)(icon.height()*0.8),icon);
        }else{
            painter.drawPixmap((int)(this->width()*0.5-250),(int)(this->height()*0.5-90),(int)(icon.width()*0.8),(int)(icon.height()*0.8),icon);
        }

            painter.setPen(Qt::white);
            QFont font("Algerian", 35);

            painter.setFont(font);
            painter.drawText((int)(this->width()*0.4-18), (int)(this->height()*0.4+12), "MAGICTOWER");
            font.setPointSize(70);
            painter.setFont(font);
            if(this->changed)
            {
                painter.setPen(Qt::red);

            }else
            {
                painter.setPen(Qt::white);

            }
            painter.drawText((int)(this->width()*0.5-18), (int)(this->height()*0.55+4), "ZMXY");
    }
}

void End::playEndVideo()
{
    this->endAnimation->play();
    this->isActive=true;
}

bool End::isActiving()
{
    return this->isActive;
}
