#include "TileButton.h"
#include <QPen>
#include <QRect>
#include <QDebug>
int TileButton::serialID=0;
int TileButton::curSelectTileID=0;
int TileButton::defaultFloorID=2;
long TileButton::defaultSerialID=1;
NPCINFO TileButton::npcBuf[174];
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


