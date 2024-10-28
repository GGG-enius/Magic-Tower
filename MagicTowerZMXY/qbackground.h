/**
* @file         QBackGround.h
* @brief       背景类的头文件
* @author      ?
* @date     ?
* @version  1.0
* @par ...
*/
#ifndef QBACKGROUND_H
#define QBACKGROUND_H

#include "qinfo.h"  //info——test
#include <QWidget>
//#include <QImage>
#include <QPainter>
#include <QPaintEvent>
#include <QRect>//info——test
#include "Global.h"
#include "qtile.h"
#include "qrole.h"
#include "qtalk.h"
class QBackGround : public QWidget
{
    Q_OBJECT
public:
    QBackGround();
    virtual ~QBackGround();
    explicit QBackGround(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event)override ;
    int BG_DRAW;//出发绘图事件
    //void timerEvent(QTimerEvent *event) override;
private:
    QTile *tile;
    //QInfo *info;//info——test
    //QRect MainRect;//info——test
    //QRect InfoRect;//info——test
    //QTalk *talk;
};

#endif // QBACKGROUND_H
