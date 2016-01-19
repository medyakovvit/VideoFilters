#-------------------------------------------------
#
# Project created by QtCreator 2016-01-12T23:31:26
#
#-------------------------------------------------
include(../../IncludeOpenCV.pri)

QT       += testlib

QT       -= gui

TARGET = tst_thresholdvideofiltertest
CONFIG   += testcase #console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_thresholdvideofiltertest.cpp \
    ../../App/thresholdvideofilter.cpp \
    ../../App/videofilter.cpp \
    ../../App/matdata.cpp \
    ../../App/data.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ../../App/thresholdvideofilter.h \
    ../../App/videofilter.h \
    ../../App/matdata.h \
    ../../App/data.h
