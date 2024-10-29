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
    void OnTimer(int timerId);
    void keyPressEvent(QKeyEvent *event);//键盘事件
    void paintEvent(QPaintEvent *event)override ;
    void timerEvent(QTimerEvent *event) override;
    void initkey();//改变键盘焦点
    int TALK_TIMER=1;
    int TALK_DRAW;//触发绘图事件，，0关闭，1打开
    int TALK_KEY;//触发键盘事件，//原本TALK_KEY=0，关闭
                                //执行是TALK_KEY=1;打开
                                //结束TALK_KEY=2；结束参数

// signals:
//     void dialogEnded(); // 定义一个信号来表示对话结束
private:
    static QVector<TALK> talkData;
    QTile * tile;
    int tileIndex;
    IDTALK currentIdTalk;
    bool changeColor;
    int timerId;
};

#endif // QTALK_H
