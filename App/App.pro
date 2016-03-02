include(../IncludeOpenCV.pri)

TEMPLATE = app

QT += qml quick widgets multimedia

SOURCES += main.cpp \
    videofilter.cpp \
    thresholdvideofilter.cpp \
    #data.cpp \
    #matdata.cpp \
    rgb2grayvideofilter.cpp \
    rgb2grayrunnable.cpp \
    thresholdrunnable.cpp \
    filtersmodel.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    videofilter.h \
    thresholdvideofilter.h \
    #data.h \
    #matdata.h \
    rgb2grayvideofilter.h \
    rgb2grayrunnable.h \
    thresholdrunnable.h \
    filtersmodel.h

