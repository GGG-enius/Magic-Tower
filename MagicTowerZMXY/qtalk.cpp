#include "qtalk.h"
#include <QFont>
#include <QDebug>

QVector<TALK> QTalk::talkData = {
    {{139, 140}, "仙女：", "魔塔共有20层", "一路小心！"},
    {{TILE_FLOOR, TILE_FLOOR}, "", "", ""}
};

QTalk::QTalk(QWidget *parent)
    : QWidget{parent}, tileIndex(0), currentIdTalk(0), changeColor(true)
{
<<<<<<< HEAD
    TALK_DRAW=0;
=======


>>>>>>> 82c74027f78f98f2c68210fa659114b947f112b3
    timerId = startTimer(100); // 500ms定时器
}
QTalk::~QTalk() {
    killTimer(timerId);
}


void QTalk::load(IDTALK idTalk) {
    currentIdTalk = idTalk;
    tileIndex = 0;
}


void QTalk::draw(QPainter &painter) {
    QRect rect(300, 200, 6 * TILE_WIDTH, 2 * TILE_HEIGHT);

    // 绘制边框
    for (int i = 0; i < rect.width() / TILE_WIDTH; i++) {
        for (int j = 0; j < rect.height() / TILE_HEIGHT; j++) {
            tile->draw(painter, rect.left() + i * TILE_WIDTH, rect.top() + j * TILE_HEIGHT, TILE_FLOOR);
        }
    }
    //BORDER_COLOR QColor(200,100,0)
    painter.setPen(BORDER_COLOR);
    painter.setBrush(Qt::NoBrush);
    for (int i = 0; i < 5; i++) {
        rect.adjust(-1, -1, 1, 1);
        painter.drawRect(rect);
    }

    // 设置显示字体
    QFont font("Arial", 12);
    painter.setFont(font);
    painter.setPen(QColor(255, 180, 0));
    painter.setBackgroundMode(Qt::TransparentMode);

    tile->draw(painter, rect.left() + TILE_WIDTH / 4, rect.top() + TILE_HEIGHT / 4, talkData[currentIdTalk].idTile[tileIndex]);
    painter.drawText(rect.left() + TILE_WIDTH + TILE_WIDTH / 2, rect.top() + TILE_HEIGHT / 2+10, talkData[currentIdTalk].npcName);
    painter.drawText(rect.left() + TILE_WIDTH + TILE_WIDTH / 2 + 120-80, rect.top() + TILE_HEIGHT / 2+10, talkData[currentIdTalk].npcSentence1);
    painter.drawText(rect.left() + TILE_WIDTH / 2, rect.top() + TILE_HEIGHT / 2 + 24+10, talkData[currentIdTalk].npcSentence2);

     // 显示闪烁space
    QFont spaceFont("Arial", 10);
    painter.setFont(spaceFont);
    qDebug()<<"调用颜色";
    painter.setPen(changeColor ? QColor(102, 102, 102) : QColor(255, 255, 255));
    painter.drawText(rect.right() - TILE_WIDTH-25, rect.bottom() - 20, "space");
}

void QTalk::paintEvent(QPaintEvent *event)
{
<<<<<<< HEAD
    if(TALK_DRAW==0){
        return;
    }
=======
>>>>>>> 82c74027f78f98f2c68210fa659114b947f112b3
    setFixedSize(MAX_WIDTH,MAX_HEIGHT);
    QPainter painter(this);
    draw(painter);
}

void QTalk::timerEvent(QTimerEvent *event) {
    if (event->timerId() == timerId) {
        changeColor = !changeColor;

        update();
        qDebug()<<"触发了timer";
<<<<<<< HEAD
        update();
=======
>>>>>>> 82c74027f78f98f2c68210fa659114b947f112b3
    }
}


void QTalk::onKeyPressed(int key) {
    if (key == Qt::Key_Space) {
        currentIdTalk++;
        if (talkData[currentIdTalk].idTile[tileIndex] == TILE_FLOOR) {
            return;
        } else {
            load(currentIdTalk);
        }
    }
}
