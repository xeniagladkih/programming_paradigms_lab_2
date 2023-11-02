// Compiler - Microsoft Visual C++

#include <iostream>
#include <fstream>

#include "FunctionalObject.h"


int main()
{
    std::ifstream input("../input.txt");
    std::ofstream output("../output.txt");

    if (!input.is_open())
    {
        std::cerr << "Error: Could not open input file." << std::endl;
        return 1;
    }

    if (!output.is_open())
    {
        std::cerr << "Error: Could not open output file." << std::endl;
        return 1;
    }

    int n;
    std::pair<double, double> x0;
    input >> n >> x0.first >> x0.second;

    std::vector<std::pair<double, double>> basePoints;
    double x, y;
    while (input >> x >> y)
        basePoints.push_back({ x, y });

    FunctionalObject funcObj(x0, basePoints);

    for (int i = 0; i < n; ++i)
    {
        std::pair<double, double> point = funcObj();
        output << point.first << " " << point.second << std::endl;
        std::cout << point.first << " " << point.second << std::endl;
    }

    return 0;
}