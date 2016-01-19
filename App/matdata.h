#ifndef MATDATA_H
#define MATDATA_H

#include <opencv2/core/core.hpp>

#include "data.h"

class MatData : public Data
{
public:
    MatData();

    cv::Mat getMat(){return m_image;}
    void setMat(cv::Mat& image);
    // Data interface
public:
    QList<DataType> dataTypes();

protected:
    cv::Mat m_image;
};

#endif // MATDATA_H
