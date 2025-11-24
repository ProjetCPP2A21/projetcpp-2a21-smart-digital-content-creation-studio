QT       += core gui widgets sql charts quick quick3d quickwidgets

CONFIG += c++17
CONFIG -= console
CONFIG -= app_bundle
QT += quick quick3d widgets gui core


SOURCES += \
    bubblemapwidget.cpp \
    bubblemapwindow.cpp \
    client.cpp \
    connection.cpp \
    main.cpp \
    gestionclient.cpp

HEADERS += \
    bubblemapwidget.h \
    bubblemapwindow.h \
    client.h \
    connection.h \
    gestionclient.h \

FORMS += \
    gestionclient.ui

RESOURCES += \
    Ressource.qrc
