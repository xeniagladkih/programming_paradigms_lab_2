#pragma once

#include <vector>
#include <random>


class FunctionalObject
{
public:
    FunctionalObject(std::pair<double, double> x0, const std::vector<std::pair<double, double>>& basePoints);

    std::pair<double, double> operator()();

private:
    std::vector<std::pair<double, double>> basePoints;
    std::pair<double, double> currentPoint;
};