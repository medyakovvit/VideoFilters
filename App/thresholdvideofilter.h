#ifndef THRESHOLDVIDEOFILTER_H
#define THRESHOLDVIDEOFILTER_H

#include "videofilter.h"

class ThresholdVideoFilter : public VideoFilter
{
public:
    ThresholdVideoFilter();

protected:
    double m_thresold;
    double m_maxValue;
};

#endif // THRESHOLDVIDEOFILTER_H
