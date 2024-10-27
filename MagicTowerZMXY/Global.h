/**
* @file       Global.h
* @brief        全局变量的头文件
* @author       ?
* @date     ?
* @version  1.0
* @par ?
*/
#ifndef GLOBAL_H
#define GLOBAL_H


//ID
typedef  int		IDTILE;					///<TILE 就是图块, 图元, 表示图形的最小单位, 如地图就是由图块拼成的
typedef  int		IDSCENE;                ///<场景ID
typedef  int		IDSCRIPT;               ///<脚本ID
typedef  int		            IDFUN;                  ///<函数ID
typedef  int		IDTALK;                 ///<对话ID
//Script
typedef  int        SCRIPTPARAM;            ///<脚本参数包括相应的ID号，(x,y)坐标
//Game Const
#ifdef _DEBUG
#define TILE_FILE_NAME			"..\\Tile.txt"              ///<图块文件
#define MAP_FILE_NAME			"..\\Map.txt"               ///<地图文件
#define NPC_FILE_NAME			"..\\Npc.txt"               ///<NPC文件
#define STORY_FILE				":\\res\\story.txt"           ///<故事情节文件
#define SOUND_INIT_FILE			":\\res\\Sound_830.wav"			///<游戏开头动画背景音乐
#define SOUND_BG_FILE			"..\\Sound_874.wav"			///<背景音乐
#define SOUND_FIGHT_FILE		"..\\Sound_13.wav"			///<攻击音乐
#else
#define TILE_FILE_NAME			"Tile.txt"
#define MAP_FILE_NAME			"Map.txt"
#define NPC_FILE_NAME			"Npc.txt"
#define STORY_FILE				":/res/story.txt"
#define SOUND_INIT_FILE			":/res/Sound_830.wav"
#define SOUND_BG_FILE			"Sound_874.wav"
#define SOUND_FIGHT_FILE		"Sound_13.wav"

#endif

#define BORDER_COLOR		QColor((200, 100, 0))             ///<边框颜色
#define STORY_BG_COLOR		QColor(0, 0 ,0)                   ///<故事情节背景颜色
#define STORY_FT_COLOR		QColor(255, 255, 255)             ///<故事情节字体颜色

#define MAX_WIDTH			640				///<游戏对话框的宽度
#define MAX_HEIGHT			480				///<游戏对话框的高度
#define MAX_SCENE			24				///<魔塔层数, 也是场景个数
#define MAP_WIDTH			11				///<每层地图宽11个TILE
#define MAP_HEIGHT			11				///<每层地图高11个TILE
#define MAX_TILE			174				///<共计174个TILE
#define MAX_NPC				MAX_TILE		///<游戏最多共有174种NPC, Ps:实际好像100左右
#define TILE_WIDTH			32				///<每个TILE宽32像索
#define TILE_HEIGHT			32				///<每个TILE高32像索
#define MAX_ROLE_TILE		16				///<主角共16个TILE
#define MAX_NPC_TILE		2				///<每个NPC动画共2TILE
#define MAX_SCRIPT			100				///<最多100个脚本
#define MAX_COMMAND			20				///<每个脚本中最多20条命令, 实际好像2条, -_-!
#define MAX_TALK			16				///<最多16条对话
#define MAX_WORDS			64				///<每个对话中最多64个字符
#define	MAX_NAME			16				///<名字中最多16个字符, 如场景名
#define MAX_BUFFER			450				///<故事情节缓冲区大小

//TILE
#define TILE_BG				156         ///<背景Tile的ID
#define TILE_FLOOR			68          ///<地板Tile的ID
#define TILE_CELESTIAL		139			///<仙子Tile的ID
#define TILE_ROLE			138			///<主角Tile的ID
#define TILE_ROLE_ENTRY		138			///<主角进入场景时的默认图块
#define TILE_ROLE_EXIT		138			///<主角退出场景后的默认图块

//Timer

#define TIMER_INIT			1			///<游戏开场动画
#define TIMER_SCENE			2			///<场景定时
#define TIMER_ROLE			3			///<主角定时
#define TIMER_FIGHT			4			///<战斗定时
//#define TIMER_TALK			5
//#define TIMER_DELAY			6


//Script ID
#define SI_NULL				0			///<无
#define	SI_SCENE			1			///<场景
#define SI_ROLE				2			///<主角
#define SI_NPC				3			///<NPC
#define SI_FLOOR			SI_NULL		///<地板
#define SI_WALL				4			///<墙
#define SI_ENTRY			5			///<入口
#define SI_EXIT				6			///<出口
#define SI_MONSTER			7			///<怪物
#define SI_CELESTIAL		8			///<仙子
#define SI_SHOP				9			///<商店
#define SI_SECRET			10			///<机关


//Game Script Command
#define SC_NULL				0			///<无, 用于停止脚本循环
#define SC_SCENEFORWARD		7			///<切换到前一场景
#define SC_SCENEBACKWARD	8			///<切换到后一场景
#define SC_NPC				11			///<NPC
#define SC_SETNPCPOS		2			///<仙子
#define SC_FIGHT			12			///<战斗
#define SC_TALK				-1			///<对话


//暂定脚本，后续可能还有存档读档脚本
#define SC_LOADSCENE		4
#define SC_HIDENPC			5
#define SC_HIDECURNPC		6


#endif // GLOBAL_H
