#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#ifdef __APPLE__
#include <GLUT/glut.h>  // macOS uses this path
#else
#include <GL/glut.h>    // Linux and Windows use this
#endif

#include "object.hpp"
#include <array>

class Rectangle : public Object {
private:
    std::array<int, 2> topLeft;
    std::array<int, 2> bottomRight;

public:
    Rectangle(std::array<int, 2> topLeft, std::array<int, 2> bottomRight, std::array<int, 3> color);
    void Draw();
};

#endif // RECTANGLE_HPP

