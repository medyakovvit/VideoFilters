#include "thresholdvideofilter.h"

#include "opencv2/imgproc.hpp"

ThresholdVideoFilter::ThresholdVideoFilter() :
    m_threshold(0.0),
    m_maxValue(255.0)
{

}

void ThresholdVideoFilter::setThreshold(double threshold)
{
    if(m_threshold == threshold)
        return;

    m_threshold = threshold;
}

void ThresholdVideoFilter::filter(Data *data)
{
    cv::Mat thresholded;

    if (!data)
    {
        m_data.setMat(thresholded);
        return;
    }

    MatData* matData = static_cast<MatData*>(data);
    cv::Mat image = matData->getMat();

    if(image.empty())
    {
        m_data.setMat(thresholded);
        return;
    }

    if(image.type() != CV_8UC1)
    {
        m_data.setMat(thresholded);
        return;
    }

    cv::threshold(image, thresholded, this->m_threshold, 255.0, cv::THRESH_BINARY);

    m_data.setMat(thresholded);

    return;
}

QList<Data::DataType> ThresholdVideoFilter::supportedInDataTypes()
{
    return QList<Data::DataType>() << Data::CV_MAT_8UC1;
}

QList<Data::DataType> ThresholdVideoFilter::supportedOutDataTypes()
{
    return QList<Data::DataType>() << Data::CV_MAT_8UC1;
}
