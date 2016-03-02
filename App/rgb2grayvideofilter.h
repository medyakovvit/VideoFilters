#ifndef RGB2GRAYVIDEOFILTER_H
#define RGB2GRAYVIDEOFILTER_H

#include "videofilter.h"
#include "rgb2grayrunnable.h"

class RGB2GrayVideoFilter : public VideoFilter
{
public:
    RGB2GrayVideoFilter(QString name, QObject * parent = 0);

    QVideoFilterRunnable *createFilterRunnable();

signals:
    void finished(QObject *result);
};

#endif // RGB2GRAYVIDEOFILTER_H
