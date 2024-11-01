#include "qstory.h"
// #include "mainwindow.h"
#include <QFile>
#include <QMessageBox>
#include <QTimer>
#include <QPainter>
#include <QKeyEvent>
#include <QDebug>
QStory::QStory(QWidget *parent)
    : QWidget{parent},storyBufIndex(0)
{
    //hhz:触发事件暂时不触发
    STORY_DRAW=0;//1执行，0无法执行
    STORY_KEY=0;

    this->setFixedSize(MAX_WIDTH, MAX_HEIGHT);

    // //该处改变焦点会覆盖上一个声明的焦点ps：qtalk
    // this->setFocusPolicy(Qt::StrongFocus); // 设置窗口可以获取焦点
    // this->setFocus(); // 尝试在构造时设置焦点

    //将缓冲区初始化为0
    //memset(storyBuf, 0, MAX_BUFFER * sizeof(QChar));

    //尝试打开故事文件
    QFile storyFile(STORY_FILE);
    //                                        以文本模式打开
    if(storyFile.open(QIODeviceBase::ReadOnly|QIODeviceBase::Text))
    {
        //qDebug()<<"成功打开";
        QByteArray array =  storyFile.readAll();//字节数组返回值接受读取到的全部内容
        this->storyBuf = QString::fromUtf8(array);
        storyFile.close();
    }
    else
    {
        QMessageBox::warning(nullptr, "Error", "无法打开数据文件");
    }
}

void QStory::init()
{
    //hhz:改变键盘焦点
    //该处改变焦点会覆盖上一个声明的焦点ps：qtalk
    // this->setFocusPolicy(Qt::StrongFocus); // 设置窗口可以获取焦点
    // this->setFocus(); // 尝试在构造时设置焦点
    //播放音效
    startSound = new QSoundEffect(this);
    startSound->setSource(QUrl::fromLocalFile(SOUND_INIT_FILE));
    startSound->play();
    startSound->setLoopCount(QSoundEffect::Infinite);

    //设置定时器 每50毫秒触发一次，用于逐步显示文本
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &QStory::storyOnTimer);
    timer->start(50);
}

void QStory::storyOnTimer()
{
    storyBufIndex += 1;
    if(storyBufIndex>=MAX_BUFFER)
    {
        timer->stop();
        //qDebug()<<"定时器停止";
    }
    else
    {
        update();
    }

}

//重载键盘事件
void QStory::keyPressEvent(QKeyEvent *event)
{
    if(STORY_KEY==0){
        return;
    }
    if (event->key() == Qt::Key_Space)
    {
        qDebug()<<"按下了空格";
        // 停止定时器响应空格键
        timer->stop();
        startSound->stop();
        this->hide();
        STORY_KEY=2;
        STORY_DRAW=0;
        // qDebug()<<STORY_KEY;
    }
    else
    {
        // 默认处理其他按键
        QWidget::keyPressEvent(event);
    }
}

void QStory::paintEvent(QPaintEvent *event)
{
    //hhz:添加
    if(STORY_DRAW==0){
        return ;
    }
    setFixedSize(MAX_WIDTH,MAX_HEIGHT);


    //创建画家
    QPainter painter(this);

    int nFontSize = 12;//指定字体大小
    QRect rect(0, 0, MAX_WIDTH, MAX_HEIGHT);
    QBrush brush(STORY_BG_COLOR);//创建一个刷子设置为指定的背景颜色
    painter.setBrush(brush);//设置刷子为当前刷子
    painter.drawRect(rect);

    //缩小绘制区域
    rect.adjust(50, 50, -25, -25);

    //设置背景模式为透明
    //painter.setBackgroundMode(Qt::TransparentMode);

    //设置文本颜色
    painter.setPen(STORY_FT_COLOR);

    //设置字体
    QFont font("仿宋体", nFontSize);
    painter.setFont(font);

    //绘制故事文本
    painter.drawText(rect, Qt::AlignLeft | Qt::AlignTop, storyBuf.left(storyBufIndex));

    // 在指定位置绘制“按空格跳过”提示文本
    painter.drawText(MAX_WIDTH - 100, MAX_HEIGHT - 25, "按空格跳过");
}


