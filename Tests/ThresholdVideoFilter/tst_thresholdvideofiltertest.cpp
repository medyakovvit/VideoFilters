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
};

ThresholdVideoFilterTest::ThresholdVideoFilterTest()
{

}

void ThresholdVideoFilterTest::inDataTypes()
{
    ThresholdVideoFilter filter;
    QList<Data::DataType> expectedInTypes;

    expectedInTypes << Data::CV_MAT;

    QCOMPARE(expectedInTypes, filter.supportedInDataTypes());
}

void ThresholdVideoFilterTest::outDataTypes()
{
    ThresholdVideoFilter filter;
    QList<Data::DataType> expectedOutTypes;

    expectedOutTypes << Data::CV_MAT;

    QCOMPARE(expectedOutTypes, filter.supportedOutDataTypes());
}

QTEST_APPLESS_MAIN(ThresholdVideoFilterTest)

#include "tst_thresholdvideofiltertest.moc"
