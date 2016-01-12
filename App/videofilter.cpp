#include "videofilter.h"

VideoFilter::VideoFilter() :
    m_next(NULL)
{

}

void VideoFilter::setNextFilter(VideoFilter *filter)
{
    if(*m_next == *filter)
        return;

    m_next = filter;
}

