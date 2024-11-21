#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qselectbutton.h"
#include "mainmap.h"
// #include <QDir>

/**这一步险棋 很危险但很变态 */
//#include "qselectarea.h"
//#include "ui_qselectarea.h"
/**后续 决定不用了这会增加后期维护难度
 * 改为 连续信号和槽机制，多信号连接*/


#include <QVBoxLayout>
#include <QButtonGroup>
#include <QPainter>
#include <QScrollBar>
#include <QDebug>
#include <QScrollArea>
#include <QRect>
#include <QFont>
#include <QLabel>
#include <QList>
#include <QFile>
// #include <QTimer>
#include <QStatusBar>
// NPCINFO MainWindow::npcBuf[174];
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFont font("Algerian");
    font.setPointSize(10);
    font.setBold(true);
    QLabel* authorInfo=new QLabel;
    authorInfo->setFont(font);
    authorInfo->setText("Editor: @Sam");
    ui->statusbar->addPermanentWidget(authorInfo);

    if(MainWindow::readNpcFile())
    {
        ui->statusbar->showMessage("[system]load npc_data succeed",5000);
        // qDebug()<<"OK";
    }else
    {
        ui->statusbar->showMessage("[system]load npc_data failed",5000);
        // qDebug()<<"error";
    }
    if(MainMap::readMapFile())
    {
        ui->statusbar->showMessage("[system]load map_data succeed",5000);
        // qDebug()<<"OKm";
    }else
    {
        ui->statusbar->showMessage("[system]load map_data failed",5000);
        // qDebug()<<"error";
    }
    if(MainMap::readImageFile())
    {
        ui->statusbar->showMessage("[system]load tile_data succeed",5000);
        // qDebug()<<"OKt";
    }else
    {
        ui->statusbar->showMessage("[system]load tile_data failed",5000);
        // qDebug()<<"error";
    }
    if(MainMap::readStairFile())
    {
        ui->statusbar->showMessage("[system]load stair_data succeed",5000);
        // qDebug()<<"OKt";
    }else
    {
        ui->statusbar->showMessage("[system]load stair_data failed",5000);
        // qDebug()<<"error";
    }
    // if(MainWindow::writeNpcFile())
    // {
    //     qDebug()<<"wwOK";
    // }else
    // {
    //     qDebug()<<"wwerror";
    // }
    // this->setSelectedTileID(1);
    QButtonGroup* group= new QButtonGroup(this);


    group->setExclusive(true);//互斥
    group->addButton(ui->layer0->getSelBtn(),0);
    group->addButton(ui->layer1->getSelBtn(),1);
    group->addButton(ui->layer2->getSelBtn(),2);
    group->addButton(ui->layer3->getSelBtn(),3);
    group->addButton(ui->layer4->getSelBtn(),4);
    group->addButton(ui->layer5->getSelBtn(),5);
    group->addButton(ui->layer6->getSelBtn(),6);
    group->addButton(ui->layer7->getSelBtn(),7);
    group->addButton(ui->layer8->getSelBtn(),8);
    group->addButton(ui->layer9->getSelBtn(),9);
    group->addButton(ui->layer10->getSelBtn(),10);
    group->addButton(ui->layer11->getSelBtn(),11);
    group->addButton(ui->layer12->getSelBtn(),12);
    group->addButton(ui->layer13->getSelBtn(),13);
    group->addButton(ui->layer14->getSelBtn(),14);
    group->addButton(ui->layer15->getSelBtn(),15);
    group->addButton(ui->layer16->getSelBtn(),16);
    group->addButton(ui->layer17->getSelBtn(),17);
    group->addButton(ui->layer18->getSelBtn(),18);
    group->addButton(ui->layer19->getSelBtn(),19);
    group->addButton(ui->layer20->getSelBtn(),20);
    group->addButton(ui->layer21->getSelBtn(),21);
    group->addButton(ui->layer22->getSelBtn(),22);
    group->addButton(ui->layer23->getSelBtn(),23);

    group->button(0)->setChecked(true);



    font.setPointSize(22);

    QLabel* layerlabel=new QLabel;
    layerlabel->setParent(ui->LayerBG);
    layerlabel->setFixedSize(ui->LayerBG->width(),ui->LayerBG->height());

    //设置 label文字对齐方式 水平垂直居中
    layerlabel->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

    //设置 鼠标穿透属性
    layerlabel->setAttribute(Qt::WA_TransparentForMouseEvents);

    layerlabel->setFont(font);
    layerlabel->setText("第 0 层");
    connect(group,&QButtonGroup::buttonClicked,[=](){
        layerlabel->setText("第 "+QString::number(group->checkedId())+" 层");
        MainMap::curLayer=group->checkedId();
        emit ui->Map->updateMap();
        // emit ui->Map->updateSelectLayer(group->checkedId());
    });


    ui->scrollArea->verticalScrollBar()->setSingleStep(80);
    ui->Info01->setInfoName("LEVEL");
    ui->Info01->setNpcInfo(TileButton::npcBuf[6].nLevel);
    ui->Info02->setInfoName("HP");
    ui->Info02->setNpcInfo(TileButton::npcBuf[6].nHealth);
    ui->Info03->setInfoName("ATT");
    ui->Info03->setNpcInfo(TileButton::npcBuf[6].nAttack);
    ui->Info04->setInfoName("DEF");
    ui->Info04->setNpcInfo(TileButton::npcBuf[6].nDefense);
    ui->Info05->setInfoName("MONEY");
    ui->Info05->setMinNum(-666);
    ui->Info05->setNpcInfo(TileButton::npcBuf[6].nMoney);
    ui->Info06->setInfoName("EXP");
    ui->Info06->setNpcInfo(TileButton::npcBuf[6].Experi);
    ui->Info07->setInfoName("RKEY");
    ui->Info07->setMinNum(-1);
    ui->Info07->setNpcInfo(TileButton::npcBuf[6].RedKey);
    ui->Info08->setInfoName("BKEY");
    ui->Info08->setMinNum(-1);
    ui->Info08->setNpcInfo(TileButton::npcBuf[6].BlueKey);
    ui->Info09->setInfoName("YKEY");
    ui->Info09->setMinNum(-1);
    ui->Info09->setNpcInfo(TileButton::npcBuf[6].YelKey);

    void (QSelectArea:: *DefaultTileupdated)(void)=&QSelectArea::updateDefault;
    connect(ui->TileArea,DefaultTileupdated,[=](){
        QString str=QString("[系统提示] 选中鼠标右键图块序列号[  %1  ]").arg(TileButton::defaultFloorID);
        ui->statusbar->showMessage(str,5000);
    });

    void (QSelectArea:: *TileInfoupdated)(void)=&QSelectArea::updateInfo;
    connect(ui->TileArea,TileInfoupdated,[=](){
        QString str=QString("[系统提示] 选中鼠标左键图块序列号[  %1  ]").arg(TileButton::curSelectTileID);
        ui->statusbar->showMessage(str,5000);

        NPCINFO tmp=(TileButton::npcBuf[TileButton::curSelectTileID]);
        ui->Info01->setNpcInfo(tmp.nLevel);
        ui->Info02->setNpcInfo(tmp.nHealth);
        ui->Info03->setNpcInfo(tmp.nAttack);
        ui->Info04->setNpcInfo(tmp.nDefense);
        ui->Info05->setNpcInfo(tmp.nMoney);
        ui->Info06->setNpcInfo(tmp.Experi);
        ui->Info07->setNpcInfo(tmp.RedKey);
        ui->Info08->setNpcInfo(tmp.BlueKey);
        ui->Info09->setNpcInfo(tmp.YelKey);


        // ui->Info01->setNpcInfo(info.nLevel);
        // ui->Info02->setNpcInfo(info.nHealth);
        // ui->Info03->setNpcInfo(info.nAttack);
        // ui->Info04->setNpcInfo(info.nDefense);
        // ui->Info05->setNpcInfo(info.nMoney);
        // ui->Info06->setNpcInfo(info.Experi);
        // ui->Info07->setNpcInfo(info.RedKey);
        // ui->Info08->setNpcInfo(info.BlueKey);
        // ui->Info09->setNpcInfo(info.YelKey);
    });
    // void (QSelectArea:: *SelectTileupdated)(int id)=&QSelectArea::updateSelectTile;
    // connect(ui->TileArea,SelectTileupdated,[=](int id){
    //     emit ui->Map->updateSelectTile(id);
    //     this->setSelectedTileID(id);
    // });
    QList<InfoEdit*> infos=this->findChildren<InfoEdit*>();
    foreach (InfoEdit* info, infos) {
        void (InfoEdit:: *infoUpdated)(void)=&InfoEdit::updateNpcInfo;
        connect(info,infoUpdated,[=](){


            // emit ui->TileArea->updateNpcInfo(curNpcInfo);
            TileButton::npcBuf[TileButton::curSelectTileID]= NPCINFO{
                ui->Info01->getNpcInfo(),
                ui->Info02->getNpcInfo(),
                ui->Info03->getNpcInfo(),
                ui->Info04->getNpcInfo(),
                ui->Info05->getNpcInfo(),
                ui->Info06->getNpcInfo(),
                ui->Info07->getNpcInfo(),
                ui->Info08->getNpcInfo(),
                ui->Info09->getNpcInfo()
            };
        });
    }


    //测试动画
    // QTimer* timer1=new QTimer;

    // connect(timer1,&QTimer::timeout,[=](){
    //     ui->Map->update();
    // });

    // timer1->start(300);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::readNpcFile()
{
    // qDebug()<<QDir::currentPath();
    QFile npcFile(NPC_FILE_NAME);
    if(!npcFile.open(QIODeviceBase::ReadOnly)){
        return false;
    }
    QDataStream in(&npcFile);
    in.setVersion(QDataStream::Qt_6_7);
    quint32 size;
    in>>size;//读取结构体数量
    for(quint32 i=0;i<size;i++)
    {
        in>>(TileButton::npcBuf[i].nLevel)
            >>(TileButton::npcBuf[i].nHealth)
            >>(TileButton::npcBuf[i].nAttack)
            >>(TileButton::npcBuf[i].nDefense)
            >>(TileButton::npcBuf[i].nMoney)
            >>(TileButton::npcBuf[i].Experi)
            >>(TileButton::npcBuf[i].RedKey)
            >>(TileButton::npcBuf[i].BlueKey)
            >>(TileButton::npcBuf[i].YelKey);
    }
    npcFile.close();
    return true;
}

bool MainWindow::writeNpcFile()
{
    QFile npcFile(NPC_FILE_NAME);
    if(!npcFile.open(QIODeviceBase::WriteOnly)){
        qDebug()<<npcFile.errorString();
        return false;
    }
    // qDebug()<<"empty";
    QDataStream out(&npcFile);
    out.setVersion(QDataStream::Qt_6_7);
    out << PIC_ABLE;//结构体数量
    for(int i=0;i<PIC_ABLE;i++)
    {    out<<TileButton::npcBuf[i].nLevel
            <<TileButton::npcBuf[i].nHealth
            <<TileButton::npcBuf[i].nAttack
            <<TileButton::npcBuf[i].nDefense
            <<TileButton::npcBuf[i].nMoney
            <<TileButton::npcBuf[i].Experi
            <<TileButton::npcBuf[i].RedKey
            <<TileButton::npcBuf[i].BlueKey
            <<TileButton::npcBuf[i].YelKey;
    }
    npcFile.close();
    return true;
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QPixmap pix;
    pix.load(":/Image/Background/MainBG.png");
    QPainter painter(this);
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    pix.load(":/Image/Background/SelectBorder.png");
    painter.setCompositionMode(QPainter::CompositionMode_SourceAtop);
    painter.drawPixmap(ui->LayerFrame->x()-10,ui->LayerFrame->y()-20,ui->LayerFrame->width()+20,ui->LayerFrame->height()+70,pix);
    QMainWindow::paintEvent(e);

    // painter.drawImage(QRect(ui->LayerFrame->x()-40,ui->LayerFrame->y(),32,32),MainMap::tilePNG[1]);
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if(e->key()==Qt::Key_S)
    {
        if(MainWindow::writeNpcFile())
        {
            // qDebug()<<"npc";
        }else
        {
            // qDebug()<<"error";
        }
        if(MainMap::writeMapFile())
        {
            // qDebug()<<"map";
        }else
        {
            // qDebug()<<"error";
        }
        if(MainMap::writeImageFile())
        {
            // qDebug()<<"tile";
        }else
        {
            // qDebug()<<"error";
        }
        if(MainMap::writeStairFile())
        {
            // qDebug()<<"stair";
        }else
        {
            // qDebug()<<"error";
        }
        ui->statusbar->showMessage("[系统提示] 保存成功",5000);
        // qDebug()<<"Save";
    }else
    {
        QWidget::keyPressEvent(e);
    }
}

// int MainWindow::getSelectedTileID()
// {
//     return this->selectedTileId;
// }

// void MainWindow::setSelectedTileID(int id)
// {
//     this->selectedTileId=id;
// }


