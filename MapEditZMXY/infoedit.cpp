#include "infoedit.h"
#include "ui_infoedit.h"
#include <QPen>
#include <QRect>
// #include <QFile>
InfoEdit::InfoEdit(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::InfoEdit)
{
    ui->setupUi(this);

    connect(ui->horizontalSlider,&QSlider::valueChanged,[=](){
        ui->spinBox->setValue(ui->horizontalSlider->value());
    });
    connect(ui->spinBox,&QSpinBox::valueChanged,[=](){
        ui->horizontalSlider->setValue(ui->spinBox->value());
        emit this->updateNpcInfo();
    });
}

InfoEdit::~InfoEdit()
{
    delete ui;
}



void InfoEdit::setInfoName(QString infoName)
{
    ui->label->setText(infoName);
}

void InfoEdit::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPen pen(Qt::black);
    pen.setWidth(2);
    painter.setPen(pen);
    QRect rect=this->rect().adjusted(1,1,-1,-1);
    painter.drawRect(rect);
    QWidget::paintEvent(e);
}

int InfoEdit::getNpcInfo()
{
    return ui->spinBox->value();
}

void InfoEdit::setNpcInfo(int info)
{
    ui->spinBox->setValue(info);
}

void InfoEdit::setMinNum(int value)
{
    ui->spinBox->setMinimum(value);
    ui->horizontalSlider->setMinimum(value);
}
