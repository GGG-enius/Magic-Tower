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
#include <QPainter>
#include <QPaintEvent>
#include "qfileutil.h"
#include "qgame.h"
#include "startmenu.h"
#include <QKeyEvent>
#include <QPoint>
#include <QDebug>
#include <QLabel>
#include "end.h"

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
    //状态栏更新槽函数
    void handleStatusBarUpdate(const QString &message); // 状态栏更新槽函数
    bool eventFilter(QObject* obj,QEvent* event);
    bool isFileEmpty(const QString &filePath);
private:
    Ui::MainWindow *ui;
    QGame *game;
    End* end;
    StartMenu* startMenu;
    QSoundEffect* mainSound;
    QLabel* statusBarRoleInfo;
    QSoundEffect* endSound;

};
#endif // MAINWINDOW_H
