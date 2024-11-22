#include "qselectarea.h"
#include "ui_qselectarea.h"
#include <QDebug>
QSelectArea::QSelectArea(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QSelectArea)
{
    ui->setupUi(this);
    ui->scrollArea->setWidget(ui->scrollAreaWidgetContents);
   // ui->scrollArea->setVerticalScrollBar(ui->ScrollBar);

    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    connect(ui->ScrollBar,&QScrollBar::valueChanged,[=](){
        ui->scrollArea->verticalScrollBar()->setValue(ui->ScrollBar->value());
        // qDebug()<<"Exten  "<<ui->scrollArea->verticalScrollBar()->value();
    });
    connect(ui->scrollArea->verticalScrollBar(),&QScrollBar::valueChanged,[=](){
        ui->ScrollBar->setValue(ui->scrollArea->verticalScrollBar()->value());
        // qDebug()<<"Area  "<<ui->scrollArea->verticalScrollBar()->value();
    });

    //bug
    // ui->ScrollBar->setMaximum(ui->scrollArea->verticalScrollBar()->maximum());//这条语句有点bug因为外部的QScrollBar已经在ui中建好并且初始化最大值为99，也就是说滚动条的形状大小已固定好，而这条语句是在后面加上的修改外部QScrollBar的属性，只修改了最大值但是步长和页长没有修改导出滚动与画面不同步
    // ui->ScrollBar->setPageStep(30);
    // ui->ScrollBar->setSingleStep(50);
    //ui->scrollArea->verticalScrollBar()->setMaximum(ui->ScrollBar->maximum());
    void (SelectTile:: *DefaultTileupdated)(void)=&SelectTile::updateDefault;
    connect(ui->scrollAreaWidgetContents,DefaultTileupdated,[=](){
        emit this->updateDefault();
    });

    void (SelectTile:: *TileInfoupdated)(void)=&SelectTile::updateInfo;
    connect(ui->scrollAreaWidgetContents,TileInfoupdated,[=](){
        emit this->updateInfo();
    });
    // void (SelectTile:: *TileInfoInit)(NPCINFO info)=&SelectTile::Init;
    // connect(ui->scrollAreaWidgetContents,TileInfoInit,[=](NPCINFO info){
    //     emit this->Init(info);
    // });
    // void (SelectTile:: *SelectTileupdated)(int id)=&SelectTile::updateSelectTile;
    // connect(ui->scrollAreaWidgetContents,SelectTileupdated,[=](int id){
    //     emit this->updateSelectTile(id);
    // });
    // void (QSelectArea:: *infoUpdated)(NPCINFO info)=&QSelectArea::updateNpcInfo;
    // connect(this,infoUpdated,[=](NPCINFO info){
    //     emit ui->scrollAreaWidgetContents->updateNpcInfo(info);
    // });

}

QSelectArea::~QSelectArea()
{
    delete ui;
}

Ui::QSelectArea *QSelectArea::getUI()
{
    return ui;
}
