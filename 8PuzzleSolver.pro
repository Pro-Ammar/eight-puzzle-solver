#-------------------------------------------------
#
# Project created by QtCreator 2016-10-21T11:36:53
#
#-------------------------------------------------

QT       += core gui
QT += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 8PuzzleSolver
TEMPLATE = app


SOURCES += main.cpp\
        eightpuzzlesolver.cpp \
    path.cpp \
    node.cpp \
    move.cpp

HEADERS  += eightpuzzlesolver.h \
    path.h \
    node.h \
    move.h

FORMS    += eightpuzzlesolver.ui

DISTFILES +=
