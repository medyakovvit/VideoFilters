TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    request.cpp \
    videofilter.cpp \
    thresholdvideofilter.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    request.h \
    videofilter.h \
    thresholdvideofilter.h

