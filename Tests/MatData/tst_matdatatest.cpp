#include <QString>
#include <QtTest>

#include "../../App/matdata.h"

class MatDataTest : public QObject
{
    Q_OBJECT

public:
    MatDataTest();

private Q_SLOTS:
    void dataTypes();
};

MatDataTest::MatDataTest()
{
}

void MatDataTest::dataTypes()
{
    MatData data;
    QList<Data::DataType> expecteTypes;

    expecteTypes << Data::CV_MAT;

    QCOMPARE(data.dataTypes(), expecteTypes);
}

QTEST_APPLESS_MAIN(MatDataTest)

#include "tst_matdatatest.moc"
