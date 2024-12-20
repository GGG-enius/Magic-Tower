/**
* @file       QFight.h
* @brief       战斗类的头文件
* @author       ?
* @date     ?
* @version  1.0
* @par ...
*/
#ifndef QFIGHT_H
#define QFIGHT_H

#include <QWidget>
#include "Global.h"
#include "qtile.h"
#include "qnpc.h"
#include "qrole.h"
#include <QTimer>
#include <QDebug>
#include <QKeyEvent>
#include <QPainter>
#include <QRect>
#include <QPoint>
#include <QSize>
#include <QSoundEffect>
class QFight : public QWidget
{
    Q_OBJECT
public:
    //构造方法
    explicit QFight(QWidget *parent = nullptr);

    //初始化函数,加载必要数据进行战斗
    //       idTile数组用于保存怪物的 Tile 信息
    void load(INDEX idTile[], NPCINFO npcInfo, ROLEINFO roleInfo);
    //                         npc相关信息        主角相关信息

    //信号处理函数
    bool fightOnTimer();//定时器事件槽函数,自动执行战斗步骤
    bool scenceOnTimer();//场景计时槽函数
    virtual bool handleKeyPressEvent(QKeyEvent *event);//键盘事件处理函数
    void paintEvent(QPaintEvent *event);//用于绘制战斗场景
    ROLEINFO getResult();//在战斗结束时可能用于返回一些结果信息

    void startFightTimer();
    void stopFightTimer();
    void startSceneTimer();
    void stopSceneTimer();

private:
    bool bAttack;//主角攻击还是怪物攻击
    QSoundEffect * fightSound;
    //地图相关变量（Tile）
    QTile *tile;//用于处理地图块，可能用于定义战斗场景的不同区域
    INDEX m_idTile[MAX_NPC_TILE];//怪物图块信息
    int nTileIndex;//当前操作的怪物索引

    //角色与怪物信息
    ROLEINFO m_RoleInfo;
    NPCINFO m_NpcInfo;

    //定时器
    QTimer *fightTimer;
    QTimer *scenceTimer;
    bool isActive;
    int originalHealth;//战斗开始时主角生命值
signals:
    void fightEnd();
    void fightHealthChanged(int healthDeta);
};

#endif // QFIGHT_H
