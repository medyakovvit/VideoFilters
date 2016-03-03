#include "rgb2grayvideofilter.h"

#include "opencv2/imgproc/imgproc.hpp"

#include <QDebug>

RGB2GrayVideoFilter::RGB2GrayVideoFilter(QString name, QObject *parent) : VideoFilter(name, parent)
{
    m_qmlFile = "Rgb2GrayPanel.qml";
}

QVideoFilterRunnable *RGB2GrayVideoFilter::createFilterRunnable()
{
    qDebug() << "RGB2GrayVideoFilter::createFilterRunnable()";

//    if(!p_runnable)
//        p_runnable = new Rgb2GrayRunnable;

    return p_runnable = new Rgb2GrayRunnable;
}

