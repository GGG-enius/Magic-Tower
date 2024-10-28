#include "selecttile.h"
#include "ui_selecttile.h"

#include <QButtonGroup>
#include <QList>
SelectTile::SelectTile(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SelectTile)
{
    ui->setupUi(this);

    QButtonGroup* TileGroup= new QButtonGroup(this);
    TileGroup->setExclusive(true);//互斥
    QList<QPushButton*> buttons= this->findChildren<QPushButton*>();
    for(int i=0;i<PIC_TOTEL;i++){
        TileGroup->addButton(buttons[i],i);
        ((TileButton*)buttons[i])->setCheckable(true);
        if(i<PIC_ABLE)
        {((TileButton*)buttons[i])->m_setStyleSheet(TileButton::tileURL[i],TileButton::tileURL[i]);}
        else{
            ((TileButton*)buttons[i])->m_setStyleSheet(":/Image/Background/etc.png",":/Image/Background/etc.png");
            ((TileButton*)buttons[i])->setDisabled(true);
        }
        connect(((TileButton*)buttons[i]),&TileButton::updateDefaltTile,[=](){
            this->update();
            emit this->updateDefault();
        });
    }

    TileGroup->button(6)->setChecked(true);
    // ui->Tile0002->m_setStyleSheet(":/Wall/Wall0007.png",":/Wall/Wall0007.png");
    // ui->Tile0003->m_setStyleSheet(":/Floor/Floor0002.png",":/Floor/Floor0002.png");
    // ui->Tile0001->setNpcInfo({99,99,99,99,99,99,99,99,99});
    connect(TileGroup,&QButtonGroup::buttonClicked,[=](){
        // emit this->Init(((TileButton*)(TileGroup->checkedButton()))->getNpcInfo());
        // emit this->updateSelectTile(TileGroup->checkedId());
        TileButton::curSelectTileID=TileGroup->checkedId();
        emit this->updateInfo();
    });

    // void (SelectTile:: *infoUpdated)(NPCINFO info)=&SelectTile::updateNpcInfo;
    // connect(this,infoUpdated,[=](NPCINFO info){
    //     ((TileButton*)(TileGroup->checkedButton()))->setNpcInfo(info);
    // });
    //TileGroup->button(1)->setChecked(true);
    // ui->Tile0001->m_setStyleSheet(":/Guard/GuardBow0001.png",":/Guard/GuardBow0001.png");
}

SelectTile::~SelectTile()
{
    delete ui;
}
