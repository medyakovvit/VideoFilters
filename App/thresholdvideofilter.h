#ifndef THRESHOLDVIDEOFILTER_H
#define THRESHOLDVIDEOFILTER_H

#include "videofilter.h"

class ThresholdVideoFilter : public VideoFilter
{
public:
    ThresholdVideoFilter();

    // VideoFilter interface
public:
    void filter(Data *);
    QList<Data::DataType> supportedInDataTypes();
    QList<Data::DataType> supportedOutDataTypes();

protected:
    double m_thresold;
    double m_maxValue;
};

#endif // THRESHOLDVIDEOFILTER_H
