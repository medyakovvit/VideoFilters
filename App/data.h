#ifndef REQUEST_H
#define REQUEST_H

#include <QList>

class Data
{
public:

    enum DataType{
        CV_MAT_8UC1 = 0,
        CV_MAT_8UC3,
        CV_RECT
    };

    Data();

    virtual QList<DataType> dataTypes() = 0;
};

#endif // REQUEST_H
