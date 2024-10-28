#include "TileButton.h"
#include <QPen>
#include <QRect>
#include <QDebug>
QString TileButton::tileURL[PIC_TOTEL]={
    ":/Image/Wall/Wall0001.png",
    ":/Image/Wall/Wall0002.png",
    ":/Image/Wall/Wall0003.png",
    ":/Image/Wall/Wall0004.png",
    ":/Image/Wall/Wall0005.png",
    ":/Image/Wall/Wall0006.png",
    ":/Image/Wall/Wall0007.png",
    ":/Image/Wall/Wall0008.png",
    ":/Image/Wall/Wall0009.png",
    ":/Image/Wall/Wall0010.png",
    ":/Image/Wall/Wall0011.png",
    ":/Image/Wall/Wall0012.png",
    ":/Image/Wall/Wall0013.png",
    ":/Image/Wall/Wall0014.png",
    ":/Image/Wall/Wall0015.png",
    ":/Image/Items/Other/other0001.png",
    ":/Image/Items/Other/other0002.png",
    ":/Image/Floor/Floor0001.png",
    ":/Image/Floor/Floor0002.png",
    ":/Image/Floor/Floor0003.png",
    ":/Image/Floor/Floor0004.png",
    ":/Image/Door/door0001.png",
    ":/Image/Door/door0002.png",
    ":/Image/Door/door0003.png",
    ":/Image/Door/door0004.png",
    ":/Image/Door/door0017.png",
    ":/Image/Door/door0018.png",
    ":/Image/Door/door0019.png",
    ":/Image/Door/door0020.png",
    ":/Image/Items/Blood/blood0001.png",
    ":/Image/Items/Blood/blood0002.png",
    ":/Image/Items/Blood/blood0003.png",
    ":/Image/Items/Blood/blood0004.png",
    ":/Image/Items/Blood/blood0005.png",
    ":/Image/Items/Blood/blood0006.png",
    ":/Image/Items/Blood/blood0007.png",
    ":/Image/Items/Blood/blood0008.png",
    ":/Image/Items/Blood/blood0009.png",
    ":/Image/Items/Blood/blood0010.png",
    ":/Image/Items/Blood/blood0011.png",
    ":/Image/Items/Blood/blood0012.png",
    ":/Image/Items/Blood/blood0013.png",
    ":/Image/Items/Blood/blood0014.png",
    ":/Image/Items/Blood/blood0015.png",
    ":/Image/Items/Blood/blood0016.png",
    ":/Image/Items/Blood/blood0017.png",
    ":/Image/Items/Blood/blood0018.png",
    ":/Image/Items/Blood/blood0019.png",
    ":/Image/Items/Blood/blood0020.png",
    ":/Image/Items/Blood/blood0021.png",
    ":/Image/Items/Blood/blood0022.png",
    ":/Image/Items/Blood/blood0023.png",
    ":/Image/Items/Blood/blood0024.png",
    ":/Image/Items/Blood/blood0025.png",
    ":/Image/Items/Blood/blood0026.png",
    ":/Image/Items/Blood/blood0027.png",
    ":/Image/Items/Blood/blood0028.png",
    ":/Image/Items/Blood/blood0029.png",
    ":/Image/Items/Blood/blood0030.png",
    ":/Image/Items/Blood/blood0031.png",
    ":/Image/Items/Blood/blood0032.png",
    ":/Image/Items/Blood/blood0033.png",
    ":/Image/Items/Money/money0001.png",
    ":/Image/Items/Money/money0002.png",
    ":/Image/Items/Money/money0003.png",
    ":/Image/Items/Money/money0004.png",
    ":/Image/Items/Money/money0005.png",
    ":/Image/Items/Money/money0006.png",
    ":/Image/Items/Money/money0007.png",
    ":/Image/Items/Money/money0008.png",
    ":/Image/Items/Money/money0009.png",
    ":/Image/Items/Tool/wuping0001.png",
    ":/Image/Items/Tool/wuping0002.png",
    ":/Image/Items/Tool/wuping0003.png",
    ":/Image/Items/Tool/wuping0004.png",
    ":/Image/Items/Tool/wuping0005.png",
    ":/Image/Items/Tool/wuping0006.png",
    ":/Image/Items/Tool/wuping0007.png",
    ":/Image/Items/Tool/wuping0008.png",
    ":/Image/Items/Tool/wuping0009.png",
    ":/Image/Items/Tool/wuping0010.png",
    ":/Image/Items/Tool/wuping0011.png",
    ":/Image/Items/Tool/wuping0012.png",
    ":/Image/Items/Tool/wuping0013.png",
    ":/Image/Items/Tool/wuping0014.png",
    ":/Image/Items/Tool/wuping0015.png",
    ":/Image/Items/Tool/wuping0016.png",
    ":/Image/Items/Tool/wuping0017.png",
    ":/Image/Items/Tool/wuping0018.png",
    ":/Image/Items/Tool/wuping0019.png",
    ":/Image/Items/Tool/wuping0020.png",
    ":/Image/Items/RoleX/role0001.png",
    ":/Image/Items/RoleX/role0002.png",
    ":/Image/Items/RoleX/role0003.png",
    ":/Image/Items/RoleX/role0004.png",
    ":/Image/Items/RoleX/role0005.png",
    ":/Image/Items/RoleX/role0006.png",
    ":/Image/Items/RoleX/role0007.png",
    ":/Image/Items/RoleX/role0008.png",
    ":/Image/Items/RoleX/role0009.png",
    ":/Image/Items/RoleX/role0010.png",
    ":/Image/Items/RoleX/role0011.png",
    ":/Image/Items/RoleX/role0012.png",
    ":/Image/Items/RoleX/role0013.png",
    ":/Image/Items/RoleX/role0014.png",
    ":/Image/Items/RoleX/role0015.png",
    ":/Image/Items/RoleX/role0016.png",
    ":/Image/Items/RoleX/role0017.png",
    ":/Image/Items/RoleX/role0018.png",
    ":/Image/Items/RoleX/role0019.png",
    ":/Image/Items/RoleX/role0020.png",
    ":/Image/Items/RoleX/role0021.png",
    ":/Image/Items/RoleX/role0022.png",
    ":/Image/Items/RoleX/role0023.png",
    ":/Image/Items/RoleX/role0024.png",
    ":/Image/Role/WuKong0001.png",
    ":/Image/NPC/Guidener0001.png",
    ":/Image/NPC/JiuWenLeft0001.png",
    ":/Image/NPC/JiuWenRight0001.png",
    ":/Image/NPC/NanGuaLeft0001.png",
    ":/Image/NPC/NanGuaRight0001.png",
    ":/Image/NPC/RobberLeft0001.png",
    ":/Image/NPC/RobberRight0001.png",
    ":/Image/NPC/TaiBaiLeft0001.png",
    ":/Image/NPC/TaiBaiRight0001.png",
    ":/Image/NPC/Trader0001.png",
    ":/Image/Boss/BossChiGuoTianWanLeft0001.png",
    ":/Image/Boss/BossChiGuoTianWanRight0001.png",
    ":/Image/Boss/BossDuoWenTianWanLeft0001.png",
    ":/Image/Boss/BossDuoWenTianWanRight0001.png",
    ":/Image/Boss/BossGuangMuTianWanLeft0001.png",
    ":/Image/Boss/BossGuangMuTianWanRight0001.png",
    ":/Image/Boss/BossJuLingShenLeft0001.png",
    ":/Image/Boss/BossJuLingShenRight0001.png",
    ":/Image/Boss/BossTuoTowerLeft0001.png",
    ":/Image/Boss/BossTuoTowerRight0001.png",
    ":/Image/Boss/BossYuanHongLeft0001.png",
    ":/Image/Boss/BossYuanHongRight0001.png",
    ":/Image/Boss/BossZenZhangTianWangLeft0001.png",
    ":/Image/Boss/BossZenZhangTianWanRight0001.png",
    ":/Image/Boss/BossZhuZiZhenLeft0001.png",
    ":/Image/Boss/BossZhuZiZhenRight0001.png",
    ":/Image/Boss/YangJianLeft0001.png",
    ":/Image/Boss/YangJianRight0001.png",
    ":/Image/Guard/GuardAxeLeft0001.png",
    ":/Image/Guard/GuardAxeRight0001.png",
    ":/Image/Guard/GuardBirdLeft0001.png",
    ":/Image/Guard/GuardBirdRight0001.png",
    ":/Image/Guard/GuardBlackTigerLeft0001.png",
    ":/Image/Guard/GuardBlackTigerRight0001.png",
    ":/Image/Guard/GuardBowLeft0001.png",
    ":/Image/Guard/GuardBowRight0001.png",
    ":/Image/Guard/GuardCowLeft0001.png",
    ":/Image/Guard/GuardCowRight0001.png",
    ":/Image/Guard/GuardDogLeft0001.png",
    ":/Image/Guard/GuardDogRight0001.png",
    ":/Image/Guard/GuardEarLeft0001.png",
    ":/Image/Guard/GuardEarRight0001.png",
    ":/Image/Guard/GuardEyeLeft0001.png",
    ":/Image/Guard/GuardEyeRight0001.png",
    ":/Image/Guard/GuardGoatLeftc0001.png",
    ":/Image/Guard/GuardGoatRight0001.png",
    ":/Image/Guard/GuardHammerLeft0001.png",
    ":/Image/Guard/GuardHammerRight0001.png",
    ":/Image/Guard/GuardKnifeLeft0001.png",
    ":/Image/Guard/GuardKnifeRight0001.png",
    ":/Image/Guard/GuardLunLeft0001.png",
    ":/Image/Guard/GuardLunRight0001.png",
    ":/Image/Guard/GuardLunZhuanWanLeft0001.png",
    ":/Image/Guard/GuardLunZhuanWanRight0001.png",
    ":/Image/Guard/GuardMiHouLeft0001.png",
    ":/Image/Guard/GuardMiHouRight0001.png",
    ":/Image/Guard/GuardRedEagleLeft0001.png",
    ":/Image/Guard/GuardRedEagleRight0001.png",
    ":/Image/Guard/GuardSnakeLeft0001.png",
    ":/Image/Guard/GuardSnakeRight0001.png",
    ":/Image/Guard/GuardSpearLeft0001.png",
    ":/Image/Guard/GuardSpearRight0001.png",
    ":/Image/Guard/GuardStoneLeft0001.png",
    ":/Image/Guard/GuardStoneRight0001.png",
    ":/Image/Guard/GuardTortoiseLeft0001.png",
    ":/Image/Guard/GuardTortoiseRight0001.png",
    ":/Image/Guard/GuardWuGonLeft0001.png",
    ":/Image/Guard/GuardWuGonRight0001.png",
    ":/Image/Guard/GuardYingDaoLeft0001.png",
    ":/Image/Guard/GuardYingDaoRight0001.png",
};
QImage TileButton::tilePNG[PIC_TOTEL];
int TileButton::serialID=0;
int TileButton::curSelectTileID=6;
int TileButton::defaultFloorID=18;
long TileButton::defaultSerialID=1;
NPCINFO TileButton::npcBuf[PIC_ABLE];
TileButton::TileButton(QWidget *parent):QPushButton(parent)
{
    // this->setCheckable(true);
    this->m_nID=TileButton::serialID++;
    if(this->m_nID==TileButton::defaultFloorID)
    {
        this->m_isDefault=TileButton::defaultSerialID;
    }else{
        this->m_isDefault=0;
    }
}
void TileButton::m_setStyleSheet(QString normalImg,QString checkedImg)
{
    this->normalImgPath=normalImg;
    this->checkedImgPath=checkedImg;

    //设置不规则图片样式
    this->setStyleSheet("QPushButton{"
                        "margin:8px;"
                        "border-image:url("+normalImg+") ;"
                        "border-width:1px;"
                        "border-style:solid;"
                        "border-color:black;"
                        "padding:0px;"
                        "background-color:transparent;}"

                        "QPushButton:hover{"
                        "margin:2px;"
                        "border-image:url("+checkedImg+");}"
                        "QPushButton:checked{"
                        "margin:2px;"
                         "border-image:url("+checkedImg+");}");

}

// NPCINFO TileButton::getNpcInfo()
// {
//     return this->m_npcInfo;
// }

// void TileButton::setNpcInfo(NPCINFO info)
// {
//     this->m_npcInfo=info;
// }

void TileButton::paintEvent(QPaintEvent *e)
{
    if( this->isChecked())
    {
        QPainter painter(this);
        QPen pen(Qt::blue);
        pen.setWidth(2);
        painter.setPen(pen);
        QRect rect=this->rect().adjusted(1,1,-1,-1);
        painter.drawRect(rect);
    }
    if(this->m_isDefault==TileButton::defaultSerialID)
    {
        QPainter painter(this);
        QPen pen(Qt::black);
        pen.setWidth(2);
        painter.setPen(pen);
        QRect rect=this->rect().adjusted(1,1,-1,-1);
        painter.drawRect(rect);
    }
    QPushButton::paintEvent(e);
}

void TileButton::mousePressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::RightButton)
    {
        TileButton::defaultFloorID=this->m_nID;
        this->m_isDefault=++TileButton::defaultSerialID;
        // qDebug()<<TileButton::defaultFloorID;
        emit this->updateDefaltTile();
    }else{
        QPushButton::mousePressEvent(e);
    }

}


