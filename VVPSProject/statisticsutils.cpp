#include "statisticsutils.h"

StatisticsUtils::StatisticsUtils()
    :complete(false)
{

}

bool StatisticsUtils::getComplete() const
{
    return complete;
}

void StatisticsUtils::setComplete(bool newComplete)
{
    complete = newComplete;
}

QList<int> StatisticsUtils::calculateMode(QList<int> set)
{
    QMap<int, int> map;
    QList<int> result;
    int max = 0;
    for (auto el : set) {
        auto mapElement = map.find(el);
        if (mapElement == map.end())
            mapElement = map.insert(el, 1);
        else
            mapElement.value()++;

        if (mapElement.value() > max) {
            max = mapElement.value();
            result.clear();
            result.append(mapElement.key());
        } else if (mapElement.value() == max) {
            result.append(mapElement.key());
        }
    }
    if (result.size() > 3)
        return {};
    return result;
}

double StatisticsUtils::calculateMedian(QList<int> set)
{
    int size = set.size();
    // check for even case
    if (size % 2 != 0)
        return (double)set[size / 2];

    return (double)(set[(size - 1) / 2] + set[size / 2]) / 2.0;
}

double StatisticsUtils::calculateAverage(QList<int> set)
{
    double sum = 0;
    for (auto el : set) {
        sum += el;
    }
    return sum / set.size();
}

int StatisticsUtils::calculateScope(QList<int> set)
{
    return set.last() - set.first();
}

double StatisticsUtils::calculateDeviation(QList<int> set)
{
    return std::sqrt(calculateVariance(set));
}

double StatisticsUtils::calculateVariance(QList<int> set)
{
    double average = calculateAverage(set);
    double deviation = 0.0;

    for (auto el : set) {
        deviation += (el - average) * (el - average);
    }

    return deviation / (set.size() - !complete);
}
