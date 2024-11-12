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
#include <QDataStream>
#include "qscene.h"
#include "qnpc.h"
#include "qbackground.h"
#include "qinfo.h"
#include "qscript.h"
#include <QSize>
#include <QStatusBar>
#include <QLabel>
#include <QFont>
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

    void drawGameScene(QPainter &painter);

    void handleGameKey(QKeyEvent *event);

    bool handleObjectInteraction();

    friend QDataStream &operator<<(QDataStream &out, const QGame &obj) {
        out << obj.gameState<<false<<obj.running<<obj.ptCurNpcPos<<(*obj.scene)<<(*obj.background)<<(*obj.info);
        return out;
    }

    friend QDataStream &operator>>(QDataStream &in, QGame &obj) {
        in >> obj.gameState >>obj.scriptFlag>> obj.running>>obj.ptCurNpcPos>>(*obj.scene)>>(*obj.background)>>(*obj.info);
        return in;
    }

    Q_ENUM(GAMESTATE)

    bool m_keyPressEvent(QKeyEvent *event);
    bool isStorying();
    bool isGameOver();
    void initGame(bool value);
protected:

    void paintEvent(QPaintEvent *event) override;

    void procScript();

    void recurScript();

    bool isScripting();
private:
    GAMESTATE gameState;
    bool running;
    bool scriptFlag;
    bool storyFlag;
    bool gameOver;
    QSize gameClientSize;
    //info
    QRect mainRect;
    QRect infoRect;

    QPoint ptCurNpcPos;


    ROLEINFO temp;

    // QTile *tile;
    QBackGround * background;

    QScene* scene;
    QFight* fight;
    QTalk * talk;
    QInfo  * info;
    QScript script;
    QStory * story;
    QSoundEffect *mainSound;
    QSoundEffect *soundObject;
    QSoundEffect *soundVictory;
    QSoundEffect *soundDefeated;

    //状态栏槽函数
    void onFightEnd(int healthDeta);//战斗结束更新状态栏
signals:
    //发送状态栏更新信号
    void updateStatusBar(const QString &message);
};
#endif // QGAME_H
