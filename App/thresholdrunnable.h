#ifndef THRESHOLDRUNNABLE_H
#define THRESHOLDRUNNABLE_H

#include <QVideoFilterRunnable>

class ThresholdRunnable : public QVideoFilterRunnable
{
public:
    ThresholdRunnable();
    ThresholdRunnable(double threshold);

    QVideoFrame run(QVideoFrame *input, const QVideoSurfaceFormat &surfaceFormat, RunFlags flags);
    double threshold(){return m_threshold;}
    void setThreshold(double threshold);

protected:
    double m_threshold;
};

#endif // THRESHOLDRUNNABLE_H
