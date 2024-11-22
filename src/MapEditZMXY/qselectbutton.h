#ifndef QSELECTBUTTON_H
#define QSELECTBUTTON_H

#include <QWidget>
#include <QAbstractButton>
namespace Ui {
class QSelectButton;
}

class QSelectButton : public QWidget
{
    Q_OBJECT

public:
    // static int nSelect;///<选中的按钮
    static int serialID;///<已创建按钮的个数
    static QString normalImgPath;///<代表正常显示的按钮
    static QString pressedImgPath;///<代表按下后显示的图片，默认为空

    explicit QSelectButton(QWidget *parent = nullptr);
    ~QSelectButton();

    QAbstractButton* getSelBtn();
    // SelectButton();//声明和实现不能同时有默认值



    //弹跳特效
    void zoomDown();//向下跳
    void zoomUp();//向上跳

    /**雷1 */
    //重写按钮 按下和释放事件
    // void mousePressEvent(QMouseEvent *e);
    // void mouseReleaseEvent(QMouseEvent *e);
    //




private:
    Ui::QSelectButton *ui;
    int m_nID;///<按钮ID




    /** 废案1 url改为静态成员变量 统一起来 */
    // void setNormalImgPath(QString normalImgPath);
    // QString getNormalImgPath();
    // void setPressedImgPath(QString pressedImgPath);
    // QString getPressedImgPath();
};

#endif // QSELECTBUTTON_H
