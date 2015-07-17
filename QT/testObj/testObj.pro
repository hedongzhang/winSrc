#-------------------------------------------------
#
# Project created by QtCreator 2015-07-13T23:10:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testObj
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    parentclass.cpp \
    sonclass.cpp

HEADERS  += mainwindow.h \
    parentclass.h \
    sonclass.h

FORMS    += mainwindow.ui
