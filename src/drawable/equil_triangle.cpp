#include "equil_triangle.hpp"

EquilateralTriangle::EquilateralTriangle(std::array<int, 2> topVertex, int sideLength, std::array<int, 3> color)
    : Triangle(
        topVertex,
        {topVertex[0] - sideLength / 2, topVertex[1] - static_cast<int>(sideLength * std::sqrt(3) / 2)},
        {topVertex[0] + sideLength / 2, topVertex[1] - static_cast<int>(sideLength * std::sqrt(3) / 2)},
        color
    ) {}

