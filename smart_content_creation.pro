QT += core gui charts widgets sql multimedia multimediawidgets
include(path/to/QXlsx/QXlsx.pri)
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += serialport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino_manager.cpp \
    bubblemapwidget.cpp \
    bubblemapwindow.cpp \
    client.cpp \
    main.cpp \
    mainwindow.cpp\
    connection.cpp\
    employe.cpp \
    projet.cpp\
    sponsor.cpp\
    ressource.cpp
    bubblemapwidget.cpp\



HEADERS += \
    arduino_manager.h \
    bubblemapwidget.h \
    bubblemapwindow.h \
    client.h \
    mainwindow.h\
    connection.h\
    Employe.h \
    projet.h\
    sponsor.h\
    ressource.h


FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressources.qrc
