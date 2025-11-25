QT += core gui sql widgets printsupport

TARGET = artemia
TEMPLATE = app

SOURCES += main.cpp \
           gprojet.cpp \
           connection.cpp \
           projet.cpp \
           chatbot.cpp

HEADERS += gprojet.h \
           connection.h \
           projet.h \
           chatbot.h

FORMS += gprojet.ui

CONFIG += c++17
