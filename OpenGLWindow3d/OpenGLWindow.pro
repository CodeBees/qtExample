#-------------------------------------------------
#
# Project created by QtCreator 2016-12-12T09:18:45
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OpenGLWindow
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    +=


LIBS += -lopengl32 -lglu32
