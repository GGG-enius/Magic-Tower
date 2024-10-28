#ifndef TILEBUTTON_H
#define TILEBUTTON_H

#include <QPushButton>
#include <QPainter>
#include <QImage>
#include <QList>
#include <QMouseEvent>
/** 总图块数量*/
#define PIC_TOTEL           230
#define PIC_ABLE            186             ///<可用图块数量
//#define PIC_WIDTH		32
//#define PIC_HEIGHT	32



/**@struct NPCINFO
* @brief NPC信息结构体 \n
* 定义存储NPC的信息
*/
struct NPCINFO
{
    int nLevel;///<   等级
    int nHealth;///<	生命值
    int nAttack;///<	攻击力
    int nDefense;///<	防御力
    int nMoney;///<		金币
    int Experi;///<		经验值
    int RedKey;	///<	  红钥匙
    int BlueKey;///<	 蓝钥匙
    int YelKey;	///<	 黄钥匙
};

class TileButton : public QPushButton
{
    Q_OBJECT
public:
    static QString tileURL[PIC_TOTEL];
    static QImage tilePNG[PIC_TOTEL];
    static int serialID;///<已创建按钮的个数
    static long defaultSerialID;///<默认按钮序列号
    static NPCINFO npcBuf[PIC_ABLE];
    static int curSelectTileID;
    static int defaultFloorID;
    explicit TileButton(QWidget *parent = nullptr);
    //normalImg代表正常显示的按钮
    //pressImg代表按下后显示的图片，默认为空
    void m_setStyleSheet(QString normalImg,QString checkedImg="");//声明和实现不能同时有默认值

    QString normalImgPath;
    QString checkedImgPath;
    // NPCINFO getNpcInfo();
    // void setNpcInfo(NPCINFO info);
    void paintEvent(QPaintEvent* e);
    void mousePressEvent(QMouseEvent *e);
private:
    // NPCINFO m_npcInfo;
    int m_nID;///<按钮ID
    long m_isDefault;///<判断是否是默认按钮
signals:
    void updateDefaltTile();
    //最底层没有发送信号只有接受信号并用槽函数响应
    // void Init(NPCINFO info);
    // void updateNpcInfo(NPCINFO info);
};

#endif // TILEBUTTON_H
