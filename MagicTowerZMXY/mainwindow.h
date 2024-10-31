/**
* @file         MainWindow.h
* @brief        主窗口
* @author       ?
* @date     ?
* @version  1.0
* @par ...
*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Global.h"
#include "qtile.h"
#include "qbackground.h"
#include <QPainter>
#include <QPaintEvent>
#include "qstory.h"
#include "qgame.h"
#include "qrole.h"
#include <QKeyEvent>
#include <QPoint>
#include <QDebug>
#include "qnpc.h"
#include "qfight.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *event)override ;
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
    QBackGround *bg;
    QInfo *info;
    QTalk * talk;
    QStory *story;
    QGame *game;
    QRole *role;
    QTile *tile;
    QNpc *npc;
    QFight *fight;
};
#endif // MAINWINDOW_H