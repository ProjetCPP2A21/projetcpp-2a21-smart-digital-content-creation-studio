QT += core sql multimedia multimediawidgets widgets \
    quick
QT+= sql
CONFIG += console
CONFIG -= app_bundle
QT += printsupport
QT += charts
QT += core gui sql widgets printsupport charts



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connectionbd.cpp \
    main.cpp \
    ressource.cpp \
    ressourcemainwindow.cpp \
    statsdialog.cpp

HEADERS += \
    connectionbd.h \
    ressource.h \
    ressourcemainwindow.h \
    statsdialog.h

FORMS += \
    ressourcemainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Ressources.qrc
