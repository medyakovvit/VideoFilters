#ifndef REQUEST_H
#define REQUEST_H

#include <QList>

enum DataType{
    CV_MAT = 0,
    CV_RECT
};

class Request
{
public:
    Request();

    virtual QList<DataType> supportedInDataTypes() = 0;
    virtual QList<DataType> supportedOutDataTypes() = 0;
};

#endif // REQUEST_H
