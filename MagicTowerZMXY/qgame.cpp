#include "qgame.h"



QGame::QGame(QWidget *parent)
    : QWidget{parent}
{
    // Init All Global Data
    QTile::initTile();
    QNpc::initNpc();
    QScene::initMap();
    QScript::initScript();



    // connect(this->fight,&QFight::timerFight,[=](){

    // });
    // connect(this->scene,&QScene::timerScene,[=](){

    // });

    // npc->initNpc();;
    Sound = new QSoundEffect(this);
    story= new QStory(this);

    // tile=new QTile(this);
    background=new QBackGround(this);
    info=new QInfo(this);


    // npc=new QNpc(this);

    scene=new QScene(this);
    fight=new QFight(this);
    talk=new QTalk(this);
    // this->scene->show();
    scene->initScene();


    connect(this->story,&QStory::storyEnd,[=](){
        // qDebug()<<"2";

        background->setActive(true);
        info->setActive(true);

        emit scene->startAnimation();

        Sound->setSource(QUrl::fromLocalFile(SOUND_BG_FILE));
        Sound->play();
        Sound->setLoopCount(QSoundEffect::Infinite);
        delete story;
        // qDebug()<<"1";

        gameState = GS_WALK;
    });

    connect(this->talk,&QTalk::talkEnd,[=](){
        gameState = GS_WALK;
    });

    connect(this->fight,&QFight::fightEnd,[=](){


            scene->hideNpc(ptCurNpcPos);
            Sound->setSource(QUrl::fromLocalFile(SOUND_BG_FILE));
            Sound->play();
            Sound->setLoopCount(QSoundEffect::Infinite);
            gameState = GS_WALK;



                scene->setRoleInfo(fight->getResult());
                  if (fight->getResult().nHealth <= 0)//如果健康值小于等于0，游戏状态切换到GS_OVER
                {                           //检查角色健康状态roleInfo.nHealth：
                    gameState = GS_OVER;
                }

    });
    // Game Const
    gameState = GS_INIT;
    gameClientSize = QSize(MAX_WIDTH, MAX_HEIGHT);
    //info内容
    infoRect = QRect(32, 50, 5 * 32, MAP_HEIGHT * 32);
    mainRect = QRect(250, 50, MAP_WIDTH * 32, MAP_HEIGHT * 32);

    running = false;

    // Set Game Window Properties
    setGeometry(0, 0, gameClientSize.width(), gameClientSize.height());

    story->init();
}

QGame::~QGame()
{
}


//绘图事件
void QGame::paintEvent(QPaintEvent *event)
{

    setFixedSize(MAX_WIDTH,MAX_HEIGHT);
    QPainter painter(this);
    // painter.drawImage(0, 0, cacheImage);
    // if(story->STORY_KEY==2 ){
    //     initkeyFocus();
    // }
    switch (gameState)
    {
    case GS_INIT:
        //改留给qstory painter事件的触发条件
        // story->init();
        // story->STORY_DRAW=1;
        // story->STORY_KEY=1;

        //story.OnDraw(painter);
        break;
    case GS_OVER:
        painter.fillRect(rect(), Qt::white);
        painter.setPen(Qt::black);
        painter.drawText(100, 100, "胜败乃兵家常事, ");
        painter.drawText(150, 130, "大侠重新来过吧! ");
        break;
    default:
        // scene->paintEvent(event);
        drawGameScene(painter);
        break;
    }
    update();
}

//scence，fight
void QGame::drawGameScene(QPainter &painter)
{    
    emit info->infoUpdated(scene->getRoleInfo(),scene->getSceneName());
    scene->SCENE_DRAW=1;

    if (gameState == GS_FIGHT)
    {
        //fight绘图事件的触发条件
    }
}

//“S”保存，“A"读取，“R”重新开始未实现
void QGame::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Q:
        exit(0);
        break;
    case Qt::Key_R:
        // 还未实现
        return;
    default:  
        handleGameKey(event);
        break;
    }
    update();
}

//scence
void QGame::handleGameKey(QKeyEvent *event)
{

    switch (gameState)
    {
    case GS_INIT:
        story->keyPressEvent(event);
        break;
    case GS_WALK:
        //使用Scene.GetRoleNextPoint(key)获取角色下一步的位置。

        ptCurNpcPos = scene->getRoleNextPoint(event);

        // 检查该位置是否有脚本事件（Scene.GetScriptID(ptCurNpcPos)）
         if (IDSCRIPT idScript = scene->getScriptID(ptCurNpcPos))
         {
        // 如果存在脚本事件，则加载并执行脚本
           script.loadScript(idScript);
            recurScript();
         }
         else
         {
        // 如果没有脚本事件，则角色移动到新位置
            scene->setRolePos(ptCurNpcPos);
         }
        break;
    case GS_TALK:
        talk->keyPressEvent(event);
        // recurScript();
        break;
    case GS_FIGHT:
        //调用fight.OnKeyDown(key)处理战斗中的按键

        //如果返回false，表示战斗结束，状态切换回GS_WALK，并执行脚本
            gameState = GS_WALK;
            recurScript();

        break;
    case GS_OVER:
        break;
    }
}

//scence
// void QGame::timerEvent(QTimerEvent *event)
// {
//     scene->startSceneTimer();

// //     scene.OnTimer(event->timerId());
//       //不论当前游戏状态是什么，首先调用scene.OnTimer()处理场景相关的定时器事件。
//      // 这可能用于更新场景动画、计时器或其他持续性事件。
//     switch (gameState)
//     {
//     // case GS_INIT:
//     //     //调用story->OnTimer(event->timerId())处理故事相关的定时器事件
//     //     if(story->IsStoryEnd())
//     //     {
//     //         qDebug()<<"2";
//     //         gameState = GS_WALK;
//     //         Sound->setSource(QUrl::fromLocalFile(SOUND_BG_FILE));
//     //         Sound->play();
//     //         Sound->setLoopCount(QSoundEffect::Infinite);
//     //         delete story;
//     //         // qDebug()<<"1";
//     //         // qDebug()<<"timerEvent::GS_INIT";
//     //     }

//     //     break;
//     case GS_TALK:
//         talk->TALK_DRAW=1;
//         //调用talk->OnTimer(event->timerId())处理对话相关的定时器事件
//         talk->OnTimer(event->timerId());
//         break;
//     case GS_FIGHT:

//
//     default:

//         break;
//     }

//     update();//调用update()刷新游戏界面。
// }


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
    INDEX tmp[MAX_NPC_TILE]{0};
      switch (idFun)
      {
      case SC_NULL:
        running = false;
        break;
     case SC_SCENEFORWARD:
        scene->forward();
        break;
     case SC_SCENEBACKWARD:
        scene->backward();
        break;
     case SC_FIGHT:
        running = false;
        gameState = GS_FIGHT;
        scene->getNpcTile(ptCurNpcPos,tmp);
        fight->load(tmp, scene->getNpcInfo(ptCurNpcPos), scene->getRoleInfo());
        break;
     case SC_TALK:
        running = false;
        emit talk->talking();
        gameState = GS_TALK;
        talk->load(Param1);
        break;
     case SC_NPC:
        handleNpcInteraction();
        break;
     case SC_SETNPCPOS:
        scene->setNpcPos(ptCurNpcPos, QPoint(Param2, Param3));
        break;
     default:
        break;
    }
    update();
}

//scene
void QGame::handleNpcInteraction()
{
   ROLEINFO roleInfo = scene->getRoleInfo();
   NPCINFO npcInfo = scene->getNpcInfo(ptCurNpcPos);
    bool npcValid = true;

    for (int i = 0; i < sizeof(roleInfo) / sizeof(int); ++i)
    {
        int *pRole = reinterpret_cast<int *>(&roleInfo) + i;
        int *pNpc = reinterpret_cast<int *>(&npcInfo) + i;
        if ((*pRole) + (*pNpc) < 0)
        {
            npcValid = false;
            break;
        }
    }

    if (npcValid)
    {
        for (int i = 0; i < sizeof(roleInfo) / sizeof(int); ++i)
        {

            int *pRole = reinterpret_cast<int *>(&roleInfo) + i;
            int *pNpc = reinterpret_cast<int *>(&npcInfo) + i;
            *pRole += *pNpc;
        }
        scene->setRoleInfo(roleInfo);
        scene->hideNpc(ptCurNpcPos);
    }
}
