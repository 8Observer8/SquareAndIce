#-------------------------------------------------
#
# Project created by QtCreator 2014-12-28T13:08:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SquareAndIce
TEMPLATE = app


SOURCES += main.cpp\
        Dialog.cpp \
    Square.cpp \
    Scene.cpp \
    Ground.cpp \
    Plane.cpp

HEADERS  += Dialog.h \
    Square.h \
    Scene.h \
    Ground.h \
    Plane.h

FORMS    += Dialog.ui

RESOURCES += \
    Shaders.qrc \
    Textures.qrc
