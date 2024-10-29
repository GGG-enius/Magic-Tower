#include "qtalk.h"
#include <QFont>
#include <QDebug>
#include <QKeyEvent>
#include <QTimer>

QVector<TALK> QTalk::talkData = {
    {{139, 140}, "仙女：", "魔塔共有20层", "一路小心！"},
    {{TILE_FLOOR, TILE_FLOOR}, "", "", ""}
};

QTalk::QTalk(QWidget *parent)
    : QWidget{parent}, tileIndex(0), currentIdTalk(0), changeColor(true)
{
    //默认
    TALK_KEY=0;
    TALK_DRAW=0;

    // this->setFocusPolicy(Qt::StrongFocus); // 设置窗口可以获取焦点
    // this->setFocus(); // 尝试在构造时设置焦点
    timerId = startTimer(100); // 500ms定时器
    // //玩偶震动
    // QTimer *timer = new QTimer(this);
    // connect(timer, &QTimer::timeout, this, &QTalk::OnTimer);
    // timer->start(100);
}
QTalk::~QTalk() {
    killTimer(timerId);
}

//改变键盘焦点
void QTalk::initkey(){
    this->setFocusPolicy(Qt::StrongFocus); // 设置窗口可以获取焦点
    this->setFocus(); // 尝试在构造时设置焦点
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
    //qDebug()<<"调用颜色";
    painter.setPen(changeColor ? QColor(102, 102, 102) : QColor(255, 255, 255));
    painter.drawText(rect.right() - TILE_WIDTH-25, rect.bottom() - 20, "space");
}


//原本TALK_KEY=0，关闭
//执行是TALK_KEY=1;打开
//结束TALK_KEY=2；结束参数
void QTalk::keyPressEvent(QKeyEvent *event)
{
    if(TALK_KEY==0){
        return;
    }
    if (event->key() == Qt::Key_Space){
        currentIdTalk++;
        qDebug() << "Space pressed. Current ID Talk:" << currentIdTalk;
        if (currentIdTalk >= talkData.size()) {
            qDebug() << "Index out of bounds!";
            this->hide();
            return;
        }
        if (talkData[currentIdTalk].idTile[tileIndex] == TILE_FLOOR) {
            TALK_KEY=2;
            qDebug() << "Tile floor detected. Closing."<<TALK_KEY;
            this->hide();
        } else {
            load(currentIdTalk);
            qDebug() << "Loaded new talk data.";
        }
    }
    else
    {
        QWidget::keyPressEvent(event);
    }
}

void QTalk::OnTimer(int timerId) {
    if (timerId == TIMER_SCENE) {
        tileIndex = (tileIndex + 1) % MAX_NPC_TILE;
    }
}

void QTalk::paintEvent(QPaintEvent *event)
{
    if(TALK_DRAW==0){
        return;
    }
    setFixedSize(MAX_WIDTH,MAX_HEIGHT);
    QPainter painter(this);
    draw(painter);
}

void QTalk::timerEvent(QTimerEvent *event) {

    if(TALK_TIMER==0){
        return ;
    }

    if (event->timerId() == timerId) {
        OnTimer(timerId);
        changeColor = !changeColor;
        update();
        //qDebug()<<"触发了timer";
    }

}


// void QTalk::onKeyPressed(int key) {
//     if (key == Qt::Key_Space) {
//        currentIdTalk++;
//         if (talkData[currentIdTalk].idTile[tileIndex] == TILE_FLOOR) {
//             return ;
//         } else {
//             load(currentIdTalk);
//         }
//     }
// }
