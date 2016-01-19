#include "videofilter.h"

VideoFilter::VideoFilter() :
    m_next(NULL)
{

}

bool VideoFilter::connectTo(VideoFilter *filter)
{
    if (!filter)
        return false;

    QList<Data::DataType> nextInTypesList = filter->supportedInDataTypes();
    QList<Data::DataType> currentOutTypesList = this->supportedOutDataTypes();

    foreach (Data::DataType type, nextInTypesList) {
        if(currentOutTypesList.contains(type))
            return true;
    }

    return false;
}

