#ifndef RIGHT_ISOSCELES_TRIANGLE_HPP
#define RIGHT_ISOSCELES_TRIANGLE_HPP

#ifdef __APPLE__
#include <GLUT/glut.h>  // macOS uses this path
#else
#include <GL/glut.h>    // Linux and Windows use this
#endif

#include "triangle.hpp"

class RightIsoscelesTriangle : public Triangle {
public:
    RightIsoscelesTriangle(std::array<int, 2> rightAngleVertex, int legLength, std::array<int, 3> color);
};

#endif // RIGHT_ISOSCELES_TRIANGLE_HPP

