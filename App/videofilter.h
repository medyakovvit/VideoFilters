#ifndef VIDEOFILTER_H
#define VIDEOFILTER_H

#include "request.h"

class VideoFilter
{
public:
    VideoFilter();

    VideoFilter* getNextFilter(){return m_next;}
    void setNextFilter(VideoFilter*);

    virtual void filter(Request* ) = 0;

protected:
    VideoFilter* m_next;
};

#endif // VIDEOFILTER_H
