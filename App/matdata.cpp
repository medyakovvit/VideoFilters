#include "matdata.h"

MatData::MatData()
{

}

QList<Data::DataType> MatData::dataTypes()
{
    return QList<Data::DataType>() << Data::CV_MAT;
}

