#ifndef STARTMENU_H
#define STARTMENU_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QAbstractButton>
#include <QKeyEvent>
#include "Global.h"
namespace Ui {
class StartMenu;
}

class StartMenu : public QWidget
{
    Q_OBJECT

public:
    explicit StartMenu(QWidget *parent = nullptr);
    ~StartMenu();
    void paintEvent(QPaintEvent *event)override ;

    //弹跳特效
    void zoomDown(QAbstractButton* SelBtn);//向下跳
    void zoomUp(QAbstractButton* SelBtn);//向上跳

    bool isFileEmpty(const QString &filePath);
    bool isStartMenuActive();
    void setActive(bool value);
    bool eventFilter(QObject *watched, QEvent *event);
private:
    Ui::StartMenu *ui;
    bool isActive;
signals:
    void newStart();
    void continueGame();
};

#endif // STARTMENU_H
