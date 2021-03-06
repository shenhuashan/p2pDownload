QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += console

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    client.cpp \
    downloadmanager.cpp \
    httpdownloader.cpp \
    commmsg.cpp \
    ctrlmsg.cpp \
    filemsg.cpp \
    main.cpp \
    mainctrl.cpp \
    mainctrlutil.cpp \
    mainrecord.cpp \
    mainwindow.cpp \
    msgutil.cpp \
    p2ptcpsocket.cpp \
    recqtimer.cpp \
    tcpsocketutil.cpp \
    test1.cpp \
    udpsocketutil.cpp

HEADERS += \
    Recqtimer.h \
    client.h \
    downloadmanager.h \
    httpdownloader.h \
    commmsg.h \
    ctrlmsg.h \
    filemsg.h \
    mainctrl.h \
    mainctrlmacro.h \
    mainctrlutil.h \
    mainrecord.h \
    mainwindow.h \
    msgutil.h \
    p2ptcpsocket.h \
    tcpsocketutil.h \
    test1.h \
    udpsocketutil.h \
    uniformlabel.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
