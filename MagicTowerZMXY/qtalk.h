/**
* @file         QTalk.h
* @brief         Talk类的头文件
* @author       ?
* @date     ?
* @version  1.0
* @par ...
*/
#ifndef QTALK_H
#define QTALK_H

#include <QObject>
#include <QString>
#include <QVector>
#include <QWidget>
#include <QTimerEvent>
#include "Global.h"
#include "qtile.h"
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>
#include "Global.h"
/**
 *  @struct TALK
 *
 *  @brief 定义一个结构体，用于存储对话相关的信息，包括NPC的ID、角色名称和对话句子。
 */
struct TALK
{
    IDTILE idTile[MAX_NPC_TILE];///<一个最多包含MAX_NPC_TILE个图块ID的数组，用于标识与对话相关的图块。
    QString npcName;			    ///<用于存储角色的名称
    QString npcSentence1;
    QString npcSentence2;///<用于存储对话
};

class QTalk : public QWidget
{
    Q_OBJECT
public:
    explicit QTalk(QWidget *parent = nullptr);
    virtual ~QTalk();
    void load(IDTALK idTalk);
    void draw(QPainter &painter);
    void paintEvent(QPaintEvent *event)override ;
    void timerEvent(QTimerEvent *event) override;
<<<<<<< HEAD
    int TALK_DRAW;//触发绘图事件
=======

>>>>>>> 82c74027f78f98f2c68210fa659114b947f112b3
public slots:
    void onKeyPressed(int key);
private:
    static QVector<TALK> talkData;
    QTile * tile;
    int tileIndex;
    IDTALK currentIdTalk;
    bool changeColor;
    int timerId;
};

#endif // QTALK_H
