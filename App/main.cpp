#include <QApplication>
#include <QQmlApplicationEngine>

#include <QtQml>

#include "rgb2grayvideofilter.h"
#include "thresholdvideofilter.h"
#include "filtersmodel.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    FiltersModel model;

    QString message("You can't create instance of class");

    qmlRegisterUncreatableType<RGB2GrayVideoFilter>("my.filters", 1, 0, "Rgb2GrayFilter", message);
    qmlRegisterUncreatableType<ThresholdVideoFilter>("my.filters", 1, 0, "ThresholdFilter", message);
    qmlRegisterType<FiltersModel>("my.filters", 1, 0, "FiltersModel");
    //engine.rootContext()->setContextProperty("filtersModel", QVariant::fromValue(model.filters()));

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

