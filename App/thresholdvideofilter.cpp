#include "thresholdvideofilter.h"

#include "thresholdrunnable.h"

#include <opencv2/imgproc.hpp>
#include <QDebug>

ThresholdVideoFilter::ThresholdVideoFilter(QString name, QObject *parent) :
    VideoFilter(name, parent), m_threshold(0.0)
{
    m_qmlFile = "ThresholdPanel.qml";
}

QVideoFilterRunnable *ThresholdVideoFilter::createFilterRunnable()
{
    qDebug() << "ThresholdVideoFilter::createFilterRunnable()";
    return p_runnable = new ThresholdRunnable(this);
}

double ThresholdVideoFilter::threshold()
{
    return m_threshold;
}

void ThresholdVideoFilter::setThreshold(double threshold)
{
    if(m_threshold == threshold)
        return;

    m_threshold = threshold;
    emit thresholdChanged(threshold);
}
