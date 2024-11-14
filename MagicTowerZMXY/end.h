#ifndef END_H
#define END_H

#include <QWidget>
#include "Global.h"
#include <QMediaPlayer>
#include <QPaintEvent>
#include <QVideoWidget>
#include <QTimer>
class End : public QWidget
{
    Q_OBJECT
public:
    explicit End(QWidget *parent = nullptr);

    QVideoWidget* videowidget;
    QMediaPlayer* endAnimation;
    void handleError(QMediaPlayer::Error error, const QString &errorString);

    void paintEvent(QPaintEvent* event);
    void playEndVideo();
    bool isActiving();
private:
    bool isActive;
    bool changed;
    bool floatAnimation;
    QTimer* timerAnimation;
    QTimer* timerRole;
signals:
};

#endif // END_H
