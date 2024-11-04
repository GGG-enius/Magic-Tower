#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPen>
#include <QDebug>
#include <QPaintEvent>
#include <QPainter>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QBackgound直接头文件声明+此处引用

    //该处改变焦点会覆盖上一个声明的焦点ps：qtalk
    //talk= new QTalk(this);
    //story=new QStory(this);

    //story->init();
    //talk->initkey();
    //bg=new QBackGround(this);
    //info=new QInfo(this);

    game=new QGame(this);
    // game->initkeyFocus();
    //story->STORY_DRAW=1;
    //story->STORY_KEY=1;
     //bg->BG_DRAW=1;
    //talk->TALK_DRAW=1;
    //talk->TALK_KEY=1;
    //info->INFO_DRAW=1;
    //role = new QRole(this);
    //tile = new QTile(this);

    // tile->initTile();

    //QNpc测试
    //npc = new QNpc(this);
    //npc->initNpc();
    //qDebug()<<npc->m_nTileIndex;
    // for(int i=0;i<76;i++)
    // {
    //         qDebug()<<npc->NpcData[i].npcInfo.nHealth;

    // }
    // npc->load(83);
    // qDebug()<<npc->m_idTile[0]<<npc->m_idTile[1];
    // qDebug()<<npc->m_idScript;
    // qDebug()<<npc->m_bShow;
    // qDebug()<<npc->m_npcInfo.nDefense;

    // npc->m_nTileIndex = 0;
    // npc->m_bShow = false;
    // npc->m_idTile[0] = 56;
    // qDebug()<<npc->getTileID();

    // npc->m_idTile[0] = 48;
    // npc->m_idTile[1] = 171;
    // IDTILE id[MAX_NPC_TILE];
    // npc->getNpcTile(id);
    // qDebug()<<id[0]<<id[1];

    //QFight测试
    // IDTILE idTile[MAX_NPC_TILE] = {83, 84};
    // NPCINFO npcInfo = {1, 45, 20, 2, 0, 0, 0, 0, 0};
    // ROLEINFO roleInfo = {1, 976, 10, 10, 0, 0, 1, 1, 1};

   // fight = new QFight(this);
    // fight->load(idTile, npcInfo, roleInfo);

    //qgame

}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{

    //控制原生窗口大小
    setFixedSize(MAX_WIDTH,MAX_HEIGHT);
    // QPainter painter(this);
    // game->drawGameScene(painter);
    //qrole测试
    // IDTILE idRoleTile = role->getRoleTileID();
    // //qDebug()<<idRoleTile;
    // QPoint ptRolePos = role->getPos();
    // //qDebug()<<ptRolePos;
    // QPainter painter(this);
    // tile->draw(painter, ptRolePos.x()*TILE_WIDTH, ptRolePos.y()*TILE_HEIGHT, idRoleTile);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    game->keyPressEvent(event);

    //qrole测试
    // // 使用 static_cast 将 int 转换为 Qt::Key
    // Qt::Key key = static_cast<Qt::Key>(event->key());
    // QPoint newPoint = role->getNextPoint(key);
    // qDebug() << "New position:" << newPoint;
    // //qDebug()<<role->getTileIndex(role->getRoleTileID());
    // role->moveTo(newPoint);
    // QWidget::keyPressEvent(event);
}
