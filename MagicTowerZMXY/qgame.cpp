#include "qgame.h"


//qnpc
QGame::QGame(QWidget *parent)
    : QWidget{parent}
{

    Sound = new QSoundEffect(this);

    tile=new QTile(this);
    background=new QBackGround(this);
    info=new QInfo(this);
    talk=new QTalk(this);
    story= new QStory(this);

    // Init All Global Data
    QTile::initTile();
    //QNpc::InitNpc();
    QScript::initScript();
    //控制键盘焦点
    initkeyFocus();
    // Game Const
    gameState = GS_INIT;
    gameClientSize = QSize(MAX_WIDTH, MAX_HEIGHT);
    //info内容
    infoRect = QRect(32, 50, 5 * 32, MAP_HEIGHT * 32);
    mainRect = QRect(250, 50, MAP_WIDTH * 32, MAP_HEIGHT * 32);
    //
    running = false;

    // Create Cache Images
    cacheImage = QImage(gameClientSize, QImage::Format_RGB32);
    mapImage = QImage(MAP_WIDTH * TILE_WIDTH, MAP_HEIGHT * TILE_HEIGHT, QImage::Format_RGB32);

    // Set Game Window Properties
    setGeometry(70, 50, gameClientSize.width(), gameClientSize.height());
    story->init();

    // Set up a timer for game updates
    startTimer(1000 / 60); // 60 FPS timer
}

QGame::~QGame()
{
}

//改变键盘焦点
void QGame::initkeyFocus(){

    this->setFocusPolicy(Qt::StrongFocus); // 设置窗口可以获取焦点
    this->setFocus(); // 尝试在构造时设置焦点
}


void QGame::paintEvent(QPaintEvent *)
{
    setFixedSize(MAX_WIDTH,MAX_HEIGHT);
    QPainter painter(this);
    painter.drawImage(0, 0, cacheImage);

    switch (gameState)
    {
    case GS_INIT:
        //改留给qstory painter事件的触发条件
        story->STORY_DRAW=1;
        story->STORY_KEY=1;
        //story.OnDraw(painter);
        break;
    case GS_OVER:
        painter.fillRect(rect(), Qt::white);
        painter.setPen(Qt::black);
        painter.drawText(100, 100, "胜败乃兵家常事, ");
        painter.drawText(150, 130, "大侠重新来过吧! ");
        break;
    default:
        drawGameScene(painter);
        break;
    }
}

//scence，fight
void QGame::drawGameScene(QPainter &painter)
{
    QPainter cachePainter(&cacheImage);


    //改留给bg painter事件的触发条件
    background->BG_DRAW=1;
    //background->OnDraw(cachePainter);
    info->drawBorder(cachePainter, mainRect);
    //改留给info painter事件的触发条件
    info->INFO_DRAW=1;
    //info->onDraw(cachePainter, infoRect, scene.GetRoleInfo(), scene.GetSceneName());
    QPainter mapPainter(&mapImage);

    //scence绘图事件的触发条件
    //scene.OnDraw(mapPainter);
    cachePainter.drawImage(mainRect.topLeft(), mapImage);

    if (gameState == GS_TALK)
    {
        talk->draw(cachePainter);
    }
    else if (gameState == GS_FIGHT)
    {
        //fight绘图事件的触发条件
        //fight.OnDraw(cachePainter);
    }

    painter.drawImage(0, 0, cacheImage);
}

//“S”保存，“A"读取，“R”重新开始未实现
void QGame::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Q:
        close();
        break;
    case Qt::Key_R:
        // 还未实现
        return;
    default:
        handleGameKey(event->key());

        //把键盘事件拉回game
        initkeyFocus();
        break;
    }
    update();
}


//scence,fight
void QGame::handleGameKey(int key)
{
    switch (gameState)
    {
    case GS_INIT:
        //调用story->OnKeyDown(key)来处理按键。如果返回false，表示初始化阶段结束
        if (story->STORY_KEY == 2)
        {
            gameState = GS_WALK;

            Sound->setSource(QUrl::fromLocalFile(SOUND_BG_FILE));
            Sound->play();
            Sound->setLoopCount(QSoundEffect::Infinite);
        }
        break;
    case GS_WALK:
        //使用Scene.GetRoleNextPoint(key)获取角色下一步的位置。

        // ptCurNpcPos = Scene.GetRoleNextPoint(key);

        //检查该位置是否有脚本事件（Scene.GetScriptID(ptCurNpcPos)）
        //  if (IDSCRIPT idScript = scene.GetScriptID(ptCurNpcPos))
        //  {
        //如果存在脚本事件，则加载并执行脚本
        //    script.loadScript(idScript);
        //     RecurScript();
        //  }
        //  else
        //  {
        //如果没有脚本事件，则角色移动到新位置
        //     Scene.SetRolePos(ptCurNpcPos);
        //  }
        break;
    case GS_TALK:
        if (talk->TALK_KEY == 2)
        {
            gameState = GS_WALK;
            recurScript();
        }
        break;
    case GS_FIGHT:
        //调用fight.OnKeyDown(key)处理战斗中的按键
        // if (fight.OnKeyDown(key) == false)
        // {
        //     //如果返回false，表示战斗结束，状态切换回GS_WALK，并执行脚本
        //     gameState = GS_WALK;
        //     recurScript();
        // }
        break;
    case GS_OVER:
        break;
    }
}

//scence，story，sound，talk，fight，
void QGame::timerEvent(QTimerEvent *event)
{
//     scene.OnTimer(event->timerId());
      //不论当前游戏状态是什么，首先调用scene.OnTimer()处理场景相关的定时器事件。
     // 这可能用于更新场景动画、计时器或其他持续性事件。
    switch (gameState)
    {
    case GS_INIT:
         //调用story->OnTimer(event->timerId())处理故事相关的定时器事件
        if (story->STORY_KEY==2)
        {
            gameState = GS_WALK;
            Sound->setSource(QUrl::fromLocalFile(SOUND_BG_FILE));
            Sound->play();
            Sound->setLoopCount(QSoundEffect::Infinite);
        }
        break;
    case GS_TALK:
        //调用talk->OnTimer(event->timerId())处理对话相关的定时器事件
        talk->OnTimer(event->timerId());
        break;
    case GS_FIGHT:
        //调用fight.OnTimer(event->timerId())处理战斗中的定时器事件
//         if (fight.OnTimer(event->timerId()) == false)
//         {
/*
隐藏当前NPC (scene.HideNpc(ptCurNpcPos))。
播放背景音乐SOUND_BG_FILE。
切换状态回GS_WALK。
执行依赖于脚本的逻辑。
*/
//             scene.HideNpc(ptCurNpcPos);
//             QSound::play(SOUND_BG_FILE);
//             gameState = GS_WALK;
//             recurScript();
//         }
//获取并设置角色战斗结果ROLEINFO roleInfo = fight.GetResult()
//         ROLEINFO roleInfo = fight.GetResult();
//更新角色信息scene.SetRoleInfo(roleInfo)
//         scene.SetRoleInfo(roleInfo);
//检查角色健康状态roleInfo.nHealth：
//如果健康值小于等于0，游戏状态切换到GS_OVER
    //      if (roleInfo.nHealth <= 0)
    //      {
    //         gameState = GS_OVER;
    //      }
         break;
    // }
//调用update()刷新游戏界面。
    update();
}
}

void QGame::recurScript()
{
    running = true;
    while (running)
    {
        procScript();
        script.loadNextScript();
    }
}

//scene,fight
void QGame::procScript()
{
    IDFUN idFun = script.getScriptInfo().idFun;
    SCRIPTPARAM Param1 = script.getScriptInfo().param1;
    SCRIPTPARAM Param2 = script.getScriptInfo().param2;
    SCRIPTPARAM Param3 = script.getScriptInfo().param3;

      switch (idFun)
      {
      case SC_NULL:
        running = false;
        break;
     case SC_SCENEFORWARD:
        //scene.Forward();
        break;
     case SC_SCENEBACKWARD:
        //scene.Backward();
        break;
     case SC_FIGHT:
        running = false;
        gameState = GS_FIGHT;
        //fight.Load(Scene.GetNpcTile(ptCurNpcPos), Scene.GetNpcInfo(ptCurNpcPos), Scene.GetRoleInfo());
        break;
     case SC_TALK:
        running = false;
        gameState = GS_TALK;
        talk->load(Param1);
        break;
     case SC_NPC:
        handleNpcInteraction();
        break;
     case SC_SETNPCPOS:
        //scene.SetNpcPos(ptCurNpcPos, QPoint(Param2, Param3));
        break;
     default:
        break;
    }
    update();
}

//scene
void QGame::handleNpcInteraction()
{
//    ROLEINFO roleInfo = scene.GetRoleInfo();
//    NPCINFO npcInfo = scene.GetNpcInfo(ptCurNpcPos);
//    bool npcValid = true;

//     for (int i = 0; i < sizeof(roleInfo) / sizeof(int); ++i)
//     {
//         int *pRole = reinterpret_cast<int *>(&roleInfo) + i;
//         int *pNpc = reinterpret_cast<int *>(&npcInfo) + i;
//         if ((*pRole) + (*pNpc) < 0)
//         {
//             npcValid = false;
//             break;
//         }
//     }

//     if (npcValid)
//     {
//         for (int i = 0; i < sizeof(roleInfo) / sizeof(int); ++i)
//         {
//             int *pRole = reinterpret_cast<int *>(&roleInfo) + i;
//             int *pNpc = reinterpret_cast<int *>(&npcInfo) + i;
//             *pRole += *pNpc;
//         }
//         scene.SetRoleInfo(roleInfo);
//         scene.HideNpc(ptCurNpcPos);
//     }
}
