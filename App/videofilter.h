#ifndef VIDEOFILTER_H
#define VIDEOFILTER_H

#include <QAbstractVideoFilter>

class VideoFilter : public QAbstractVideoFilter
{
    Q_OBJECT

public:
    VideoFilter(QObject *parent = 0);
    virtual ~VideoFilter();

protected:
    QVideoFilterRunnable *p_runnable;
};

#endif // VIDEOFILTER_H
