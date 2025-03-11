#include "right_isosceles_triangle.hpp"

RightIsoscelesTriangle::RightIsoscelesTriangle(std::array<int, 2> rightAngleVertex, int legLength, std::array<int, 3> color)
    : Triangle(
        rightAngleVertex,
        {rightAngleVertex[0] + legLength, rightAngleVertex[1]},   // Base vertex
        {rightAngleVertex[0], rightAngleVertex[1] + legLength},   // Height vertex
        color
    ) {}
