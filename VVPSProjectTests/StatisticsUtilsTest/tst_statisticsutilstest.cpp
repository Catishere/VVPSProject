#include <QtTest>
#include "statisticsutils.h"

class StatisticsUtilsTest : public QObject
{
    Q_OBJECT

static const QList<int> testData;

public:
    StatisticsUtilsTest();
    ~StatisticsUtilsTest();

private slots:
    static void testCalculateMode();
    static void testCalculateMedian();
    static void testCalculateAverage();
    static void testCalculateScope();
    static void testCalculateDeviation();
    static void testCalculateVariance();

};

const QList<int> StatisticsUtilsTest::testData =
            {  1,  3,  6,  7,  7,  9,  9,
              10, 11, 11, 14, 14, 14, 15,
              15, 15, 15, 16, 16, 18, 18,
              19, 19, 19, 20 };

StatisticsUtilsTest::StatisticsUtilsTest()
{
}

StatisticsUtilsTest::~StatisticsUtilsTest()
{
}

void StatisticsUtilsTest::testCalculateMode()
{
    StatisticsUtils stats;
    auto mode = stats.calculateMode(testData);
    QCOMPARE(mode.length(), 1);
    QCOMPARE(mode.at(0), 15);

    mode = stats.calculateMode(QList<int>
                                          { 1, 2, 3, 3, 4, 4, 5, 5});
    QCOMPARE(mode.length(), 3);
    QCOMPARE(mode.at(0), 3);
    QCOMPARE(mode.at(1), 4);
    QCOMPARE(mode.at(2), 5);


    mode = stats.calculateMode(QList<int>
                                          { 1, 2, 3, 4, 5});
    QCOMPARE(mode.length(), 0);
}

void StatisticsUtilsTest::testCalculateMedian()
{
    StatisticsUtils stats;
    auto median = stats.calculateMedian(testData);
    QCOMPARE(median, 14);
}

void StatisticsUtilsTest::testCalculateAverage()
{
    StatisticsUtils stats;
    auto average = stats.calculateAverage(testData);
    QCOMPARE(average, 12.84);
}

void StatisticsUtilsTest::testCalculateScope()
{
    StatisticsUtils stats;
    auto scope = stats.calculateScope(testData);
    QCOMPARE(scope, 19);
}

void StatisticsUtilsTest::testCalculateDeviation()
{
    StatisticsUtils stats;
    auto deviation = stats.calculateDeviation(testData);
    QCOMPARE(deviation, 5.23354564325);
    stats.setComplete(true);
    deviation = stats.calculateDeviation(testData);
    QCOMPARE(deviation, 5.12780654861);
}

void StatisticsUtilsTest::testCalculateVariance()
{
    StatisticsUtils stats;
    auto variance = stats.calculateVariance(testData);
    QCOMPARE(variance, 27.39);
    stats.setComplete(true);
    variance = stats.calculateVariance(testData);
    QCOMPARE(variance, 26.2944);
}

QTEST_APPLESS_MAIN(StatisticsUtilsTest)

#include "tst_statisticsutilstest.moc"
