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
#include "qstory.h"
#include "qscript.h"
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
    void paintEvent(QPaintEvent *event);

private:
    Ui::MainWindow *ui;
    QStory* story;

};
#endif // MAINWINDOW_H
