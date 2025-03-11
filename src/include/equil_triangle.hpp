#ifndef EQUILATERAL_TRIANGLE_HPP
#define EQUILATERAL_TRIANGLE_HPP

#ifdef __APPLE__
#include <GLUT/glut.h>  // macOS uses this path
#else
#include <GL/glut.h>    // Linux and Windows use this
#endif

#include "triangle.hpp"
#include <cmath>

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(std::array<int, 2> topVertex, int sideLength, std::array<int, 3> color);
};

#endif // EQUILATERAL_TRIANGLE_HPP

