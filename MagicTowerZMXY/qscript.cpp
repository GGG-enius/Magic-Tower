#include "qscript.h"
#include "QMessageBox"
#include "Global.h"
#include <QDebug>

QScript::QScript(QWidget *parent)
    : QWidget{parent}
{
    m_nCommandIndex = 0;
}


//Script 采用两层结构, 外层表示脚本编号, 里层为命令序列

SCRIPTS QScript::Script[MAX_SCRIPT] =
{
    {
     SI_NULL,
     {//无
         {SC_NULL, 0, 0, 0},
         {0,0,0,0},
         {0,0,0,0},
         },
     },
    //SceneScript
    {
     SI_SCENE,
     {//场景
         {SC_NULL, 0, 0, 0},
         {0,0,0,0},
         {0,0,0,0},
         },
     },
    //Role Script
    {
     SI_ROLE,
     {//角色
         {SC_NULL,0,0,0},
         {0,0,0,0},
         {0,0,0,0},
         },
     },
    //Wall
    {
     SI_WALL,
     {//墙
         {SC_NULL,0,0,0},
         {0,0,0,0},
         },
     },
    //Entry
    {
     SI_ENTRY,
     {//入口
         {SC_SCENEFORWARD, 0, 0, 0},
         {0,0,0,0},
         {0,0,0,0},
         },
     },
    //Exit
    {
     SI_EXIT,
     {//出门
         {SC_SCENEBACKWARD, 0, 0, 0},
         {0,0,0,0},
         {0,0,0,0},
         },
     },
    //npc
    {
     SI_NPC,
     {//NPC
         {SC_NPC, 0, 0, 0},
         {0,0,0,0},
         {0,0,0,0},
         },
     },
    //FIGHT
    {
     SI_MONSTER,
     {//战斗
         {SC_FIGHT, 0, 0, 0},
         {0,0,0,0},
         {0,0,0,0},
         },
     },
    //Celestial
    {
     SI_CELESTIAL,
     {//仙子
         {SC_TALK, 0, 50, 100},
         {SC_SETNPCPOS,0,4,8},
         {0,0,0,0},
         {0,0,0,0},
         },
     },
    //Shop
    {
     SI_SHOP,
     {//商店
         {0,0,0,0},
         {0,0,0,0},
         },
     },
    //Secret
    {
     SI_SECRET,
     {//机关
         {0,0,0,0},
         {0,0,0,0},
         },
     },
    };

void QScript::initScript()
{

}

 void QScript::loadScript(IDSCRIPT idScript)
{
     m_nScriptIndex = -1;//该变量用于存储当前正在使用的脚本在 Script 数组中的索引
     int i;
     for(i = 0; i < MAX_SCRIPT; i++)
     {
         if(Script[i].idScript == idScript)
         {
             m_nScriptIndex = i;
             break;
         }
     }
     if (m_nScriptIndex != -1) {
         m_nCommandIndex = 0;
         m_Script = Script[m_nScriptIndex].script[m_nCommandIndex];
     } else {
         qWarning() << "Script ID not found!";
     }
}

void QScript::loadNextScript()
{
    if (m_nScriptIndex == -1) return;

    ++m_nCommandIndex;
    // qDebug()<<m_nCommandIndex;
    if (m_nCommandIndex < 4) {
        m_Script = Script[m_nScriptIndex].script[m_nCommandIndex];
    } else {
        qWarning() << "No more commands in script!";
        m_nCommandIndex =  - 1;  // 保持在最后一个有效命令上
    }
}

// 获取当前脚本信息
SCRIPT QScript::getScriptInfo() {
    return m_Script;
}


