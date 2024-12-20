QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    end.cpp \
    main.cpp \
    mainwindow.cpp \
    qbackground.cpp \
    qfight.cpp \
    qfileutil.cpp \
    qgame.cpp \
    qinfo.cpp \
    qnpc.cpp \
    qrole.cpp \
    qscene.cpp \
    qscript.cpp \
    qstory.cpp \
    qtalk.cpp \
    qtile.cpp \
    startmenu.cpp

HEADERS += \
    Global.h \
    end.h \
    mainwindow.h \
    qbackground.h \
    qfight.h \
    qfileutil.h \
    qgame.h \
    qinfo.h \
    qnpc.h \
    qrole.h \
    qscene.h \
    qscript.h \
    qstory.h \
    qtalk.h \
    qtile.h \
    startmenu.h

FORMS += \
    mainwindow.ui \
    startmenu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
