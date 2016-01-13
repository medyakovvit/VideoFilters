#ifndef VIDEOFILTER_H
#define VIDEOFILTER_H

#include "data.h"

class VideoFilter
{
public:
    VideoFilter();

    VideoFilter* getNextFilter(){return m_next;}
    void setNextFilter(VideoFilter*);

    virtual void filter(Data* ) = 0;
    virtual QList<Data::DataType> supportedInDataTypes() = 0;
    virtual QList<Data::DataType> supportedOutDataTypes() = 0;

protected:
    VideoFilter* m_next;
};

#endif // VIDEOFILTER_H
