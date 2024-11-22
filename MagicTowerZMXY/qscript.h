/**
* @file             QScript.h
* @brief            脚本类的头文件
* @author
* @date
* @version 1.0
* @par ...
*/
#ifndef QSCRIPT_H
#define QSCRIPT_H

#include <QObject>
#include "Global.h"
#include <QWidget>

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


class QScript : public QWidget
{
    Q_OBJECT
public:
    explicit QScript(QWidget *parent = nullptr);

    // 静态方法：初始化所有脚本数据
    static void initScript();

    // 根据 idScript 加载对应的脚本
    void loadScript(IDSCRIPT idScript);

    //获取或加载下一个脚本的命令，可用于遍历脚本的顺序执行
    void loadNextScript();

    // 返回当前脚本命令的信息
    SCRIPT getScriptInfo();

private:

    static SCRIPTS Script[MAX_SCRIPT];// 存储所有的脚本
    SCRIPT m_Script;//当前加载的脚本命令
    int m_nScriptIndex;//当前脚本在 Script 数组中的索引
    int m_nCommandIndex;//当前正在执行的命令在 m_Script.Script 数组中的索引

signals:
};

#endif // QSCRIPT_H

