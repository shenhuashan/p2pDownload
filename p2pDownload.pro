QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

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
    host.cpp \
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
    partner.cpp \
    recqtimer.cpp \
    tcpsocketutil.cpp \
    udpsocketutil.cpp

HEADERS += \
    Recqtimer.h \
    host.h \
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
    partner.h \
    tcpsocketutil.h \
    udpsocketutil.h \
    uniformlabel.h

FORMS += \
    downloadmanager.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
