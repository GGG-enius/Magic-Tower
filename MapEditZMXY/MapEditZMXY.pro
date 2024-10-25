QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    TileButton.cpp \
    infoedit.cpp \
    main.cpp \
    mainmap.cpp \
    mainwindow.cpp \
    maparea.cpp \
    qselectarea.cpp \
    qselectbutton.cpp \
    selecttile.cpp

HEADERS += \
    TileButton.h \
    infoedit.h \
    mainmap.h \
    mainwindow.h \
    maparea.h \
    qselectarea.h \
    qselectbutton.h \
    selecttile.h

FORMS += \
    infoedit.ui \
    mainwindow.ui \
    maparea.ui \
    qselectarea.ui \
    qselectbutton.ui \
    selecttile.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
