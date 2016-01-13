#include "thresholdvideofilter.h"

ThresholdVideoFilter::ThresholdVideoFilter() :
    m_thresold(0.0),
    m_maxValue(255.0)
{

}

void ThresholdVideoFilter::filter(Data *)
{
    return;
}

QList<Data::DataType> ThresholdVideoFilter::supportedInDataTypes()
{
    return QList<Data::DataType>() << Data::CV_MAT;
}

QList<Data::DataType> ThresholdVideoFilter::supportedOutDataTypes()
{
    return QList<Data::DataType>() << Data::CV_MAT;
}
