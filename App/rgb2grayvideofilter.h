#ifndef RGB2GRAYVIDEOFILTER_H
#define RGB2GRAYVIDEOFILTER_H

#include <QAbstractVideoFilter>

#include "rgb2grayrunnable.h"

class RGB2GrayVideoFilter : public QAbstractVideoFilter
{
public:
    RGB2GrayVideoFilter(QObject * parent = 0);

    QVideoFilterRunnable *createFilterRunnable() { return new Rgb2GrayRunnable; }

signals:
    void finished(QObject *result);
};

#endif // RGB2GRAYVIDEOFILTER_H
