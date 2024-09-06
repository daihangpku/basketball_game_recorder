QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    help.cpp \
    main.cpp \
    mainwindow.cpp \
    record.cpp \
    record_mode.cpp \
    replay.cpp \
    save.cpp

HEADERS += \
    help.h \
    mainwindow.h \
    record.h \
    record_mode.h \
    replay.h \
    save.h

FORMS += \
    help.ui \
    mainwindow.ui \
    record.ui \
    record_mode.ui \
    replay.ui \
    save.ui

TRANSLATIONS += \
    Basketball_Record_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    background.qrc
