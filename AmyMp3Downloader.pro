#-------------------------------------------------
#
# Project created by QtCreator 2015-03-26T09:21:09
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AmyMp3Downloader
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    htmlpaser.cpp \
    node.cpp

HEADERS  += mainwindow.h \
    htmlpaser.h \
    node.h

FORMS    += mainwindow.ui
