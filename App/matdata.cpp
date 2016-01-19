#include "matdata.h"

MatData::MatData()
{

}

void MatData::setMat(cv::Mat &image)
{
    m_image = image;
}

QList<Data::DataType> MatData::dataTypes()
{
    return QList<Data::DataType>() << Data::CV_MAT_8UC1;
}

