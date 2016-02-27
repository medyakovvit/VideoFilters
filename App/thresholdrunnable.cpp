#include "thresholdrunnable.h"

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

#include <QDebug>

ThresholdRunnable::ThresholdRunnable() : m_threshold(0.0)
{

}

ThresholdRunnable::ThresholdRunnable(double threshold) :
    m_threshold(threshold)
{

}

QVideoFrame ThresholdRunnable::run(QVideoFrame *input, const QVideoSurfaceFormat &surfaceFormat, QVideoFilterRunnable::RunFlags flags)
{
    Q_UNUSED(surfaceFormat);
    Q_UNUSED(flags);

    input->map(QAbstractVideoBuffer::ReadWrite);

    cv::Mat inMat(input->height(), input->width(), CV_8UC1);
    for(int i=0; i<inMat.rows; i++)
    {
        uchar *inMatLine = inMat.ptr<uchar>(i);
        uchar *inFrameLine = input->bits() + i*input->bytesPerLine()/*i*outMat.cols*4*/;
        for(int j=0; j<inMat.cols; j++)
        {
            int index = 4*j;
            uchar value = inFrameLine[index];
            inMatLine[j] = value;
        }
    }

    cv::Mat thresholded;
    cv::threshold(inMat, thresholded, m_threshold, 255.0, cv::THRESH_BINARY);

    uchar* outMatLine;
    uchar* outputLine;

    uchar* outputBits = input->bits();

    for(int i=0; i<thresholded.rows; i++)
    {
        outMatLine = thresholded.ptr<uchar>(i);
        outputLine = outputBits + i*input->bytesPerLine()/*i*outMat.cols*4*/;
        for(int j=0; j<thresholded.cols; j++)
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

void ThresholdRunnable::setThreshold(double threshold)
{
    if(m_threshold == threshold)
        return;

    m_threshold = threshold;
}
