QT += core gui charts widgets sql multimedia multimediawidgets network printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    connection.cpp \
    employe.cpp \
    client.cpp \
    projet.cpp \
    sponsor.cpp \
    ressource.cpp \
    bubblemapwidget.cpp \
    bubblemapwindow.cpp \
    chatbot.cpp

HEADERS += \
    mainwindow.h \
    connection.h \
    employe.h \
    client.h \
    projet.h \
    sponsor.h \
    ressource.h \
    bubblemapwidget.h \
    bubblemapwindow.h \
    chatbot.h

FORMS += \
    mainwindow.ui \

RESOURCES += \
    ressources.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
