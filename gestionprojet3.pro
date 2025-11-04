QT += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gestionprojet3
TEMPLATE = app

SOURCES += main.cpp \
           gprojet.cpp \
           connection.cpp \
    projet.cpp


HEADERS += gprojet.h \
           connection.h \
    projet.h


FORMS += gprojet.ui

CONFIG += c++17
