#-------------------------------------------------
#
# Project created by QtCreator 2015-04-22T22:49:13
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = console
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    Lesson08.cpp

HEADERS += \
    Lesson08.h

LIBS += -L  M:\githubWorkspace\lecture\console -lsqlite3
