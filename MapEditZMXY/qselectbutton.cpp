#include "qselectbutton.h"
#include "ui_qselectbutton.h"
#include <QDebug>
#include <QPropertyAnimation>
#include <QLabel>
#include <QFont>
int QSelectButton::serialID=0;
// int QSelectButton::nSelect=0;
QString QSelectButton::normalImgPath=":/Button/SelectButton0001.png";
QString QSelectButton::pressedImgPath=":/Button/SelectButton0002.png";
QSelectButton::QSelectButton(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QSelectButton)
{
    ui->setupUi(this);
    this->m_nID=QSelectButton::serialID++;
    ui->SelBtn->setText(QString::number(this->m_nID));
    connect(ui->SelBtn,&QPushButton::clicked,[=](){
        this->zoomDown();
        this->zoomUp();
    });
}

QSelectButton::~QSelectButton()
{
    delete ui;
}

QAbstractButton* QSelectButton::getSelBtn()
{
    return ui->SelBtn;
}



// SelectButton::SelectButton()
// {
//     this->m_nID=SelectButton::serialID++;

//     QPixmap pix;
//     bool ret = pix.load(SelectButton::normalImgPath);
//     if(!ret)
//     {
//         qDebug()<<"图片加载失败";
//         return;
//     }
//     //设置图片固定大小
//     this->setFixedSize(pix.width(),pix.height());

//     //设置不规则图片样式
//     this->setStyleSheet("QPushButton{border:0px;}"
//                         "QPushButton{background-image:url("+SelectButton::normalImgPath+");}"
//                         "QPushButton:checked{background-image:url("+SelectButton::pressedImgPath+");}");
//     //他真的我哭死｡°(°¯᷄◠¯᷅°)°｡


//     QLabel* label=new QLabel;
//     label->setParent(this);
//     label->setFixedSize(pix.width(),pix.height());
//     QFont font;
//     font.setFamily("Ravie 常规");
//     font.setPointSize(14);
//     font.setBold(true);
//     label->setFont(font);
//     label->setText(QString::number(this->m_nID));

//     //设置 label文字对齐方式 水平垂直居中
//     label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

//     //设置 鼠标穿透属性
//     label->setAttribute(Qt::WA_TransparentForMouseEvents);

//     this->setCheckable(true);//方便后续按钮组管理单选
// }

void QSelectButton::zoomDown()
{
    //创建动画对象
    QPropertyAnimation *animation=new QPropertyAnimation(ui->SelBtn,"geometry");

    //设置动画时间间隔
    animation->setDuration(200);

    //起始位置
    animation->setStartValue(QRect(ui->SelBtn->x(),ui->SelBtn->y(),ui->SelBtn->width(),ui->SelBtn->height()));

    //结束位置
    animation->setEndValue(QRect(ui->SelBtn->x(),ui->SelBtn->y()+3,ui->SelBtn->width(),ui->SelBtn->height()));

    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);

    //执行动画
    animation->start();


}
void QSelectButton::zoomUp()
{
    //创建动画对象
    QPropertyAnimation *animation=new QPropertyAnimation(ui->SelBtn,"geometry");

    //设置动画时间间隔
    animation->setDuration(200);

    //起始位置
    animation->setStartValue(QRect(ui->SelBtn->x(),ui->SelBtn->y()+3,ui->SelBtn->width(),ui->SelBtn->height()));

    //结束位置
    animation->setEndValue(QRect(ui->SelBtn->x(),ui->SelBtn->y(),ui->SelBtn->width(),ui->SelBtn->height()));

    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);

    //执行动画
    animation->start();
}
// SelectButton::~SelectButton()
// {
//     delete ui;
// }












// void QSelectButton::mousePressEvent(QMouseEvent *e)
// {
//     // QSelectButton::nSelect=this->m_nID;
//     // QPixmap pix;
//     // bool ret = pix.load(QSelectButton::pressedImgPath);
//     // if(!ret)
//     // {
//     //     qDebug()<<"图片加载失败";
//     //     return;
//     // }
//     // //设置图片固定大小
//     // this->setFixedSize(pix.width(),pix.height());

//     // //设置不规则图片样式
//     // this->setStyleSheet("QPushButton{border:0px;}");

//     // //设置图标
//     // this->setIcon(pix);

//     // //设置图标大小
//     // this->setIconSize(QSize(pix.width(),pix.height()));
// }

// void QSelectButton::mouseReleaseEvent(QMouseEvent *e)
// {

// }



// void QSelectButton::setNormalImgPath(QString normalImgPath)
// {
//     this->normalImgPath=normalImgPath;
// }

// QString QSelectButton::getNormalImgPath()
// {
//     return this->normalImgPath;
// }

// void QSelectButton::setPressedImgPath(QString pressedImgPath)
// {
//     this->pressedImgPath=pressedImgPath;
// }

// QString QSelectButton::getPressedImgPath()
// {
//     return this->pressedImgPath;
// }
