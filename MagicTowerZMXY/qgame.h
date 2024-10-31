/**
* @file       QGame.h
* @brief       游戏类的头文件
* @author       ?
* @date     ?
* @version  1.0
* @par ...
*/
#ifndef QGAME_H
#define QGAME_H

#include <QWidget>
#include <QKeyEvent>
#include <QTimer>
#include <QTimerEvent>
#include <QPainter>
#include <QRect>
#include <QPoint>
#include <QObject>
#include <QSoundEffect>
//#include <<QtGlobal>

#include "Global.h"
#include "qstory.h"
#include "qtalk.h"
#include "qrole.h"
#include "qfight.h"
#include "qscene.h"
#include "qnpc.h"
#include "qbackground.h"
#include "qinfo.h"
#include "qscript.h"


/**
 * @enum GAMESTATE
 *
 * @brief 游戏状态枚举类型。
 *
 * @note  用于表示游戏的不同状态。
 */
enum GAMESTATE
{
    GS_INIT,///<初始化状态
    GS_WALK,///<行走状态
    GS_TALK,///<对话状态
    GS_FIGHT,///<战斗状态
    GS_OVER///<结束状态
};
class QGame : public QWidget
{
    Q_OBJECT
public:
    explicit QGame(QWidget *parent = nullptr);
    ~QGame();
    void initkeyFocus();
    void drawGameScene(QPainter &painter);
    void handleGameKey(int key);
    void handleNpcInteraction();
protected:
    void keyPressEvent(QKeyEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void timerEvent(QTimerEvent *event) override;
    void procScript();
    void recurScript();

private:
    GAMESTATE gameState;
    bool running;

    QSize gameClientSize;
    //info
    QRect mainRect;
    QRect infoRect;

    QPoint currentNpcPosition;

    QImage cacheImage;
    QImage mapImage;

    QTile *tile;
    QBackGround * background;
    QNpc *npc;
    QScene scene;
    QFight* fight;
    QTalk * talk;
    QInfo  * info;
    QScript script;
    QStory * story;
    QSoundEffect *Sound;
};
#endif // QGAME_H