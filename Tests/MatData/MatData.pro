#-------------------------------------------------
#
# Project created by QtCreator 2016-01-13T23:21:40
#
#-------------------------------------------------
include(../../IncludeOpenCV.pri)

QT       += testlib

QT       -= gui

TARGET = tst_matdatatest
CONFIG   += testcase #console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_matdatatest.cpp \
    ../../App/matdata.cpp \
    ../../App/data.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ../../App/matdata.h \
    ../../App/data.h
