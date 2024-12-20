/**
* @file           QStory.h
* @brief     故事类的头文件
* @author
* @date    2024-10-17
* @version  1.0
* @par ?
*/
#ifndef QSTORY_H
#define QSTORY_H

#include <QObject>
#include "Global.h"
#include <QTimer>
#include <QKeyEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QWidget>
#include <QSoundEffect>
#include "qbackground.h"
// #include "mainwindow.h"
class QStory : public QWidget
{
    Q_OBJECT
public:
    explicit QStory(QWidget *parent = nullptr);//构造函数
    void init();//初始化函数
    void storyOnTimer();//定时器事件处理槽
    void keyPressEvent(QKeyEvent *event);//键盘事件
    void paintEvent(QPaintEvent *event);//绘画事件

private:
    QTimer *timer;
    QSoundEffect *startSound;
    QString storyBuf;

    int storyBufIndex;//故事情节缓冲索引


    bool changeColor;

signals:
    void storyEnd();
};



#endif // QSTORY_H
