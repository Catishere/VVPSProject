#include <QtTest>
#include "statisticsutils.h"

class StatisticsUtilsTest : public QObject
{
    Q_OBJECT

static const QList<int> testData;
static const QList<int> testDataEven;

public:
    StatisticsUtilsTest();
    ~StatisticsUtilsTest();

private slots:
    static void testCalculateMode();
    static void testCalculateModeAmodal();
    static void testCalculateModeTrimodal();
    static void testCalculateMedianOdd();
    static void testCalculateMedianEven();
    static void testCalculateAverage();
    static void testCalculateScope();
    static void testCalculateDeviationSample();
    static void testCalculateDeviationComplete();
    static void testCalculateVarianceSample();
    static void testCalculateVarianceComplete();

};

const QList<int> StatisticsUtilsTest::testData =
            {  1,  3,  6,  7,  7,  9,  9,
              10, 11, 11, 14, 14, 14, 15,
              15, 15, 15, 16, 16, 18, 18,
              19, 19, 19, 20 };

const QList<int> StatisticsUtilsTest::testDataEven =
            {  1,  3,  6,  7,  7,  9,  9,
              10, 11, 11, 14, 14, 15, 15,
              15, 15, 15, 16, 16, 18, 18,
              19, 19, 19 };

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
}

void StatisticsUtilsTest::testCalculateModeAmodal()
{
    StatisticsUtils stats;
    auto mode = stats.calculateMode(QList<int> { 1, 2, 3, 4, 5});
    QCOMPARE(mode.length(), 0);
}

void StatisticsUtilsTest::testCalculateModeTrimodal()
{
    StatisticsUtils stats;
    auto mode = stats.calculateMode(QList<int> { 1, 2, 3, 3, 4, 4, 5, 5});
    QCOMPARE(mode.length(), 3);
    QCOMPARE(mode.at(0), 3);
    QCOMPARE(mode.at(1), 4);
    QCOMPARE(mode.at(2), 5);
}

void StatisticsUtilsTest::testCalculateMedianOdd()
{
    StatisticsUtils stats;
    auto median = stats.calculateMedian(testData);
    QCOMPARE(median, 14);
}

void StatisticsUtilsTest::testCalculateMedianEven()
{
    StatisticsUtils stats;
    auto median = stats.calculateMedian(testDataEven);
    QCOMPARE(median, 14.5);
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

void StatisticsUtilsTest::testCalculateDeviationSample()
{

    StatisticsUtils stats;
    auto deviation = stats.calculateDeviation(testData);
    QCOMPARE(deviation, 5.23354564325);
}

void StatisticsUtilsTest::testCalculateDeviationComplete()
{
    StatisticsUtils stats;
    stats.setComplete(true);
    QVERIFY(stats.getComplete());
    auto deviation = stats.calculateDeviation(testData);
    QCOMPARE(deviation, 5.12780654861);
}

void StatisticsUtilsTest::testCalculateVarianceSample()
{
    StatisticsUtils stats;
    auto variance = stats.calculateVariance(testData);
    QCOMPARE(variance, 27.39);
}

void StatisticsUtilsTest::testCalculateVarianceComplete()
{
    StatisticsUtils stats;
    stats.setComplete(true);
    QVERIFY(stats.getComplete());
    auto variance = stats.calculateVariance(testData);
    QCOMPARE(variance, 26.2944);
}

QTEST_APPLESS_MAIN(StatisticsUtilsTest)

#include "tst_statisticsutilstest.moc"
