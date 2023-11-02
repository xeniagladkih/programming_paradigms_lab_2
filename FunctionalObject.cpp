#include "FunctionalObject.h"


FunctionalObject::FunctionalObject(std::pair<double, double> x0, const std::vector<std::pair<double, double>>& basePoints)
        : currentPoint(x0), basePoints(basePoints)
{
}


std::pair<double, double> FunctionalObject::operator()()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, basePoints.size() - 1);

    int idx = dis(gen);
    currentPoint = { (currentPoint.first + basePoints[idx].first) / 2,
                     (currentPoint.second + basePoints[idx].second) / 2 };
    return currentPoint;
}