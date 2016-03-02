#include "rgb2grayrunnable.h"

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

#include <QDebug>

Rgb2GrayRunnable::Rgb2GrayRunnable()
{

}

Rgb2GrayRunnable::~Rgb2GrayRunnable()
{
    qDebug() << "Rgb2GrayRunnable d-tor";
}

QVideoFrame Rgb2GrayRunnable::run(QVideoFrame *input, const QVideoSurfaceFormat &surfaceFormat, QVideoFilterRunnable::RunFlags flags)
{
    Q_UNUSED(surfaceFormat);
    Q_UNUSED(flags);

    input->map(QAbstractVideoBuffer::ReadWrite);

    cv::Mat inMat(input->height(), input->width(), CV_8UC4, input->bits(), input->bytesPerLine());

    cv::Mat outMat;
    cv::cvtColor(inMat, outMat, CV_RGB2GRAY);

    uchar* outMatLine;
    uchar* outputLine;

    uchar* outputBits = input->bits();

    for(int i=0; i<outMat.rows; i++)
    {
        outMatLine = outMat.ptr<uchar>(i);
        outputLine = outputBits + i*input->bytesPerLine()/*i*outMat.cols*4*/;
        for(int j=0; j<outMat.cols; j++)
        {
            int index = 4*j;
            uchar value = outMatLine[j];
            outputLine[index] = value; // R
            outputLine[index+1] = value; // G
            outputLine[index+2] = value; // B
            outputLine[index+3] = 255; // A
        }
    }

    input->unmap();
    return *input;
}
