#ifndef STATISTICSUTILS_H
#define STATISTICSUTILS_H

#include <QList>
#include <QDebug>
#include <QMap>

class StatisticsUtils
{
    bool complete;
public:
    StatisticsUtils();
    QList<int> calculateMode(QList<int> set);
    double calculateMedian(QList<int> set);
    double calculateAverage(QList<int> set);
    int calculateScope(QList<int> set);
    double calculateDeviation(QList<int> set);
    double calculateVariance(QList<int> set);
    bool getComplete() const;
    void setComplete(bool newComplete);
};

#endif // STATISTICSUTILS_H
