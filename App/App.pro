include(../IncludeOpenCV.pri)

TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    videofilter.cpp \
    thresholdvideofilter.cpp \
    data.cpp \
    matdata.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    videofilter.h \
    thresholdvideofilter.h \
    data.h \
    matdata.h

