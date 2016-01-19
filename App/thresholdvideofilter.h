#ifndef THRESHOLDVIDEOFILTER_H
#define THRESHOLDVIDEOFILTER_H

#include "videofilter.h"
#include "matdata.h"

class ThresholdVideoFilter : public VideoFilter
{
public:
    ThresholdVideoFilter();

    double threshold(){return m_threshold;}
    void setThreshold(double threshold);

    // VideoFilter interface
public:
    void filter(Data *);
    Data* getData(){return &m_data;}
    QList<Data::DataType> supportedInDataTypes();
    QList<Data::DataType> supportedOutDataTypes();

protected:
    double m_threshold;
    double m_maxValue;
    MatData m_data;
};

#endif // THRESHOLDVIDEOFILTER_H
