#include <QString>
#include <QtTest>

#include "../../App/thresholdvideofilter.h"

class ThresholdVideoFilterTest : public QObject
{
    Q_OBJECT

public:
    ThresholdVideoFilterTest();

private Q_SLOTS:
    void inDataTypes();
    void outDataTypes();
    void connectTo_competible_filter();
    void connectTo_uncompetible_filter();
    void filter_empty_mat();
    void filter_valid_mat();
    void filter_null_data();
    void filter_color_mat();
};

class CompatibleVideoFilter : public VideoFilter
{
public:
    CompatibleVideoFilter(){}
    void filter(Data *){return;}
    Data* getData(){return 0;}
    QList<Data::DataType> supportedInDataTypes(){return QList<Data::DataType>() << Data::CV_MAT_8UC1;}
    QList<Data::DataType> supportedOutDataTypes(){return QList<Data::DataType>();}
};

class UnCompatibleVideoFilter : public VideoFilter
{
public:
    UnCompatibleVideoFilter(){}
    void filter(Data *){return;}
    Data* getData(){return 0;}
    QList<Data::DataType> supportedInDataTypes(){return QList<Data::DataType>() << Data::CV_RECT;}
    QList<Data::DataType> supportedOutDataTypes(){return QList<Data::DataType>();}
};

ThresholdVideoFilterTest::ThresholdVideoFilterTest()
{

}

void ThresholdVideoFilterTest::inDataTypes()
{
    ThresholdVideoFilter filter;
    QList<Data::DataType> expectedInTypes;

    expectedInTypes << Data::CV_MAT_8UC1;

    QCOMPARE(expectedInTypes, filter.supportedInDataTypes());
}

void ThresholdVideoFilterTest::outDataTypes()
{
    ThresholdVideoFilter filter;
    QList<Data::DataType> expectedOutTypes;

    expectedOutTypes << Data::CV_MAT_8UC1;

    QCOMPARE(expectedOutTypes, filter.supportedOutDataTypes());
}

void ThresholdVideoFilterTest::connectTo_competible_filter()
{
    ThresholdVideoFilter filter;
    CompatibleVideoFilter compatibleFilter;

    QVERIFY(filter.connectTo(&compatibleFilter));
}

void ThresholdVideoFilterTest::connectTo_uncompetible_filter()
{
    ThresholdVideoFilter filter;
    UnCompatibleVideoFilter uncompatibleFilter;

    QVERIFY(!filter.connectTo(&uncompatibleFilter));
}

void ThresholdVideoFilterTest::filter_empty_mat()
{
    ThresholdVideoFilter filter;
    MatData data;
    filter.filter(&data);

    MatData* threshData = static_cast<MatData*>(filter.getData());
    QVERIFY(threshData->getMat().empty());
}

void ThresholdVideoFilterTest::filter_valid_mat()
{
    unsigned char imgData[9] = {0, 100, 201, 51, 151, 251, 81, 181, 255};
    cv::Mat image(3, 3, CV_8UC1, &imgData);

    MatData data;
    data.setMat(image);

    int threshold = 100;
    ThresholdVideoFilter filter;
    filter.setThreshold(threshold);
    filter.filter(&data);

    MatData* thresholdedData = static_cast<MatData*>(filter.getData());
    cv::Mat thresholdedImage = thresholdedData->getMat();

    QVERIFY(!thresholdedImage.empty());

    for(int i=0; i<9; i++)
    {
        uchar pixel = thresholdedImage.data[i];
        if(imgData[i]>threshold)
            QVERIFY(pixel == 255);
        else
            QVERIFY(pixel == 0);
    }
}

void ThresholdVideoFilterTest::filter_null_data()
{
    ThresholdVideoFilter filter;
    int threshold = 100;
    filter.setThreshold(threshold);
    filter.filter(0);

    MatData* thresholdedData = static_cast<MatData*>(filter.getData());
    cv::Mat thresholdedImage = thresholdedData->getMat();

    QVERIFY(thresholdedImage.empty());
}

void ThresholdVideoFilterTest::filter_color_mat()
{
    cv::Mat image = cv::Mat::zeros(3, 3, CV_8UC3);

    MatData data;
    data.setMat(image);

    int threshold = 100;
    ThresholdVideoFilter filter;
    filter.setThreshold(threshold);
    filter.filter(&data);

    MatData* thresholdedData = static_cast<MatData*>(filter.getData());
    cv::Mat thresholdedImage = thresholdedData->getMat();

    QVERIFY(thresholdedImage.empty());
}

QTEST_APPLESS_MAIN(ThresholdVideoFilterTest)

#include "tst_thresholdvideofiltertest.moc"
