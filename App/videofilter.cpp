#include "videofilter.h"

VideoFilter::VideoFilter(QObject *parent) : QAbstractVideoFilter(parent),
    p_runnable(0)
{

}

VideoFilter::~VideoFilter()
{
    if(p_runnable)
    {
        delete p_runnable;
        p_runnable = 0;
    }
}

