#include "thresholdvideofilter.h"

#include <opencv2/imgproc.hpp>
#include <QDebug>

ThresholdVideoFilter::ThresholdVideoFilter(QObject *parent) :
    VideoFilter(parent), m_threshold(0.0)
{

}

QVideoFilterRunnable *ThresholdVideoFilter::createFilterRunnable()
{
    if(!p_runnable)
        p_runnable = new ThresholdRunnable(m_threshold);

    return p_runnable;
}

double ThresholdVideoFilter::threshold()
{
    if(!p_runnable)
        return 0.0;

    ThresholdRunnable *pR = static_cast<ThresholdRunnable*>(p_runnable);
    return pR->threshold();
}

void ThresholdVideoFilter::setThreshold(double threshold)
{
    if(!p_runnable)
    {
        m_threshold = threshold;
        return;
    }

    ThresholdRunnable *pR = static_cast<ThresholdRunnable*>(p_runnable);
    if(threshold == pR->threshold())
        return;

    pR->setThreshold(threshold);
    emit thresholdChanged(threshold);
}
