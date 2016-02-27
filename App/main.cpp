#include <QApplication>
#include <QQmlApplicationEngine>

#include <QtQml>

#include "rgb2grayvideofilter.h"
#include "thresholdvideofilter.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<RGB2GrayVideoFilter>("my.filters", 1, 0, "Rgb2GrayFilter");
    qmlRegisterType<ThresholdVideoFilter>("my.filters", 1, 0, "ThresholdFilter");

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

