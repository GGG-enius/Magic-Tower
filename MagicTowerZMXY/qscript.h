/**
* @file             QScript.h
* @brief            脚本类的头文件
* @author      ?
* @date     ?
* @version 1.0
* @par ...
*/
#ifndef QSCRIPT_H
#define QSCRIPT_H

#include <QObject>
#include "Global.h"
/**
* @struct SCRIPT
* @brief 定义一个结构体，用于存储脚本相关的信息，包括函数ID、参数1、参数2和参数3。
*/
struct SCRIPT
{
    IDFUN idFun;///<一个函数ID，用于标识脚本中要执行的函数。
    SCRIPTPARAM param1;///<参数1，用于传递ID号
    SCRIPTPARAM param2;///<参数2，用于传递X坐标
    SCRIPTPARAM param3;///<参数3，用于传递Y坐标
};

/**
* @struct SCRIPTS
* @brief 定义一个结构体，用于存储脚本相关的信息，包括脚本ID和SCRIPT结构体数组。
*/
struct SCRIPTS
{
    IDSCRIPT idScript;///<一个脚本ID，用于标识脚本。
    SCRIPT script[MAX_COMMAND];///<一个SCRIPT结构体数组，用于存储脚本中要执行的命令。
};


class QScript : public QObject
{
    Q_OBJECT
public:
    explicit QScript(QObject *parent = nullptr);

signals:
};

#endif // QSCRIPT_H
