#include "videofilter.h"

VideoFilter::VideoFilter() :
    m_next(NULL)
{

}

void VideoFilter::setNextFilter(VideoFilter *filter)
{
    if (!filter)
        return;

    m_next = filter;
}

