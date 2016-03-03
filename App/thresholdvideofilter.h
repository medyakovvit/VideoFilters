#ifndef THRESHOLDVIDEOFILTER_H
#define THRESHOLDVIDEOFILTER_H

#include "videofilter.h"

class ThresholdRunnable;

class ThresholdVideoFilter : public VideoFilter
{
    Q_OBJECT
    Q_PROPERTY(double threshold READ threshold WRITE setThreshold NOTIFY thresholdChanged)

public:
    ThresholdVideoFilter(QString name, QObject *parent=0);

    QVideoFilterRunnable *createFilterRunnable();

    double threshold();

public slots:
    void setThreshold(double threshold);

signals:
    void finished(QObject *result);
    void thresholdChanged(double threshold);

protected:
    double m_threshold;
};

#endif // THRESHOLDVIDEOFILTER_H
