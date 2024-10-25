#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QKeyEvent>
#include <QMainWindow>
#include "TileButton.h"



#define NPC_FILE_NAME		"../../IOFile/Npc.bin"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    // static NPCINFO npcBuf[174];
    static bool readNpcFile();
    static bool writeNpcFile();
    //重写paintEvent
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *e);
    // void setSelectedTileID(int id);
    // int getSelectedTileID();
private:
    Ui::MainWindow *ui;
    // int selectedTileId;
signals:

};
#endif // MAINWINDOW_H
