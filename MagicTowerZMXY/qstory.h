/**
* @file           QStory.h
* @brief     故事类的头文件
* @author       ?
* @date    ?
* @version  1.0
* @par ?
*/
#ifndef QSTORY_H
#define QSTORY_H

#include <QObject>
#include "Global.h"
class QStory : public QObject
{
    Q_OBJECT
public:
    explicit QStory(QObject *parent = nullptr);

signals:
};

#endif // QSTORY_H
