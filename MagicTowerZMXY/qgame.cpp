#include "qgame.h"



QGame::QGame(QWidget *parent)
    : QWidget{parent}
{
    // Init All Global Data
    QTile::initTile();
    QNpc::initNpc();
    QScene::initMap();
    QScript::initScript();

    this->scriptFlag=false;

    Sound = new QSoundEffect(this);
    story= new QStory(this);

    background=new QBackGround(this);
    info=new QInfo(this);

    scene=new QScene(this);
    fight=new QFight(this);
    talk=new QTalk(this);

    scene->initScene();
    connect(this->scene,&QScene::stopDoorAnimation,[=](){
        this->scriptFlag=false;
    });

    connect(this->story,&QStory::storyEnd,[=](){
        // qDebug()<<"2";

        background->setActive(true);
        info->setActive(true);

        emit scene->startAnimation();

        Sound->setSource(QUrl::fromLocalFile(SOUND_BG_FILE1));
        Sound->play();
        Sound->setLoopCount(QSoundEffect::Infinite);
        delete story;
        // qDebug()<<"1";

        gameState = GS_WALK;
        this->update();
    });

    connect(this->talk,&QTalk::talkEnd,[=](){
        gameState = GS_WALK;
        this->update();
    });

    connect(this->fight,&QFight::fightEnd,[=](){ 
        scene->hideNpc(ptCurNpcPos);
        Sound->setSource(QUrl::fromLocalFile(SOUND_BG_FILE1));
        Sound->play();
        Sound->setLoopCount(QSoundEffect::Infinite);
        gameState = GS_WALK;

        scene->setRoleInfo(fight->getResult());
        if (fight->getResult().nHealth <= 0)//如果健康值小于等于0，游戏状态切换到GS_OVER
        {                           //检查角色健康状态roleInfo.nHealth：
            gameState = GS_OVER;
        }
        this->update();
        this->Sound->play();
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

    switch (gameState)
    {
    case GS_INIT:
        break;
    case GS_OVER:
        painter.fillRect(rect(), Qt::white);
        painter.setPen(Qt::black);
        painter.drawText(100, 100, "胜败乃兵家常事, ");
        painter.drawText(150, 130, "大侠重新来过吧! ");
        background->setActive(false);
        info->setActive(false);
        emit scene->stopAnimation();
        break;
    default:
        emit info->infoUpdated(scene->getRoleInfo(),scene->getSceneName());
        break;
    }
    update();
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
        if(isScripting())
            return;
        else
        {
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
        }
        break;
    case GS_TALK:
        talk->keyPressEvent(event);
        if(talk->handleKeyPressEvent(event)==false){
        recurScript();
        }
        break;
    case GS_FIGHT:
        //调用fight.OnKeyDown(key)处理战斗中的按键

        //如果返回false，表示战斗结束，状态切换回GS_WALK，并执行脚本
        if(fight->handleKeyPressEvent(event)==false){
            gameState = GS_WALK;
            recurScript();
        }
        break;
    case GS_OVER:
        break;
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

bool QGame::isScripting()
{
    return this->scriptFlag;
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
        this->Sound->stop();
        scene->getNpcTile(ptCurNpcPos,tmp);
        fight->load(tmp, scene->getNpcInfo(ptCurNpcPos), scene->getRoleInfo());
        break;
     case SC_TALK:
        running = false;
        emit talk->talking();
        gameState = GS_TALK;
        talk->load(Param1);
        break;
     case SC_OBJECT:
        if(handleObjectInteraction())
        {
            scene->hideNpc(ptCurNpcPos);
        }
        break;
     case SC_DOOR:
         this->scriptFlag=true;
         if(handleObjectInteraction())
         {
             scene->startPtPosAnimation(scene->getSceneID(),ptCurNpcPos.y(),ptCurNpcPos.x());
         }else{
             this->scriptFlag=false;
         }
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
bool QGame::handleObjectInteraction()
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
    }
    return npcValid;
}
