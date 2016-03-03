#ifndef THRESHOLDRUNNABLE_H
#define THRESHOLDRUNNABLE_H

#include <QVideoFilterRunnable>

#include "thresholdvideofilter.h"

class ThresholdRunnable : public QVideoFilterRunnable
{
public:
    ThresholdRunnable(ThresholdVideoFilter* filter);
    ~ThresholdRunnable();

    QVideoFrame run(QVideoFrame *input, const QVideoSurfaceFormat &surfaceFormat, RunFlags flags);

protected:
    ThresholdVideoFilter *pFilter;
};

#endif // THRESHOLDRUNNABLE_H
