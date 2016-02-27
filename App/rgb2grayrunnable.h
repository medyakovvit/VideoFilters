#ifndef RGB2GRAYRUNNABLE_H
#define RGB2GRAYRUNNABLE_H

#include <QVideoFilterRunnable>

class Rgb2GrayRunnable : public QVideoFilterRunnable
{
public:
    Rgb2GrayRunnable();
    QVideoFrame run(QVideoFrame *input, const QVideoSurfaceFormat &surfaceFormat, RunFlags flags);
};

#endif // RGB2GRAYRUNNABLE_H
