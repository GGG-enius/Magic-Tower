#include "qtalk.h"
#include <QFont>
#include <QDebug>
#include <QKeyEvent>
#include <QTimer>

QVector<TALK> QTalk::talkData = {
    {{175,176,177,178}, "太上老君:", "魔塔共有24层", "一路小心！"},
    {{TILE_FLOOR, TILE_FLOOR,TILE_FLOOR,TILE_FLOOR}, "", "", ""}
};

QTalk::QTalk(QWidget *parent)
    : QWidget{parent}, tileIndex(0), currentIdTalk(0), changeColor(true)
{
    this->isActive=false;
    this->timerTalk=new QTimer(this);

    connect(this->timerTalk,&QTimer::timeout,[=](){
        // qDebug()<<"------------------";
        OnTimer();
        changeColor = !changeColor;
        update();
    });

    connect(this,&QTalk::talking,[=](){
        this->show();
        this->isActive=true;
        this->timerTalk->start(100);
        // qDebug()<<"|||||||||||||||||||||||";
    });

}
QTalk::~QTalk() {
}

void QTalk::load(IDTALK idTalk) {
    currentIdTalk = idTalk;
    tileIndex = 0;
}

void QTalk::draw(QPainter &painter) {
    QRect rect(250, 50+7*TILE_HEIGHT, MAP_WIDTH * TILE_WIDTH, 4*TILE_HEIGHT);

    // 绘制边框
    for (int i = 0; i < rect.width() / TILE_WIDTH; i++) {
        for (int j = 0; j < rect.height() / TILE_HEIGHT; j++) {
            tile->draw(painter, rect.left() + i * TILE_WIDTH, rect.top() + j * TILE_HEIGHT, TILE_FLOOR);
        }
    }
    //BORDER_COLOR QColor(200,100,0)
    QPen pen(QColor(200,100,0));
    pen.setWidth(3);
    painter.setPen(pen);
    painter.drawRect(rect.adjusted(-1,-2,1,1));

    // 设置显示字体
    QFont font("Arial", 12);
    painter.setFont(font);
    painter.setPen(QColor(255, 180, 0));
    painter.setBackgroundMode(Qt::TransparentMode);

    tile->draw(painter, rect.left() + TILE_WIDTH / 4, rect.top() + TILE_HEIGHT / 4, talkData[currentIdTalk].idTile[tileIndex]);
    painter.drawText(rect.left() + TILE_WIDTH + TILE_WIDTH / 2, rect.top() + TILE_HEIGHT / 2+10, talkData[currentIdTalk].npcName);
    painter.drawText(rect.left() + TILE_WIDTH + TILE_WIDTH / 2 + 120-80, rect.top() + TILE_HEIGHT*2 +10, talkData[currentIdTalk].npcSentence1);
    painter.drawText(rect.left() + TILE_WIDTH + TILE_WIDTH / 2 + 120-80, rect.top() + TILE_HEIGHT*2 + 24+10, talkData[currentIdTalk].npcSentence2);

     // 显示闪烁space
    QFont spaceFont("Arial", 10);
    painter.setFont(spaceFont);
    //qDebug()<<"调用颜色";
    painter.setPen(changeColor ? QColor(102, 102, 102) : QColor(255, 255, 255));
    painter.drawText(rect.right() - TILE_WIDTH-25, rect.bottom() - 20, "space");
}


void QTalk::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space){
        currentIdTalk++;
        // qDebug() << "Space pressed. Current ID Talk:" << currentIdTalk;
        if (currentIdTalk >= talkData.size()||talkData[currentIdTalk].idTile[tileIndex] == TILE_FLOOR) {
            this->timerTalk->stop();
            this->isActive=false;
            emit this->talkEnd();
            this->hide();
            return;
        }
        else {
            load(currentIdTalk);
            // qDebug() << "Loaded new talk data.";
        }
    }

    QWidget::keyPressEvent(event);


}

void QTalk::OnTimer() {
    tileIndex = (tileIndex + 1) % MAX_NPC_TILE;
}

void QTalk::paintEvent(QPaintEvent *event)
{
    if(this->isActive)
    {
        setFixedSize(MAX_WIDTH,MAX_HEIGHT);
        QPainter painter(this);
        draw(painter);
    }
    QWidget::paintEvent(event);
}
bool QTalk::handleKeyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space){
        return false;
    }
    return true;
}

