#ifndef REQUEST_H
#define REQUEST_H

#include <QList>

class Data
{
public:

    enum DataType{
        CV_MAT = 0,
        CV_RECT
    };

    Data();

    virtual QList<DataType> dataTypes() = 0;
};

#endif // REQUEST_H
