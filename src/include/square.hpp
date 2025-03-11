#ifndef SQUARE_HPP
#define SQUARE_HPP

#ifdef __APPLE__
#include <GLUT/glut.h>  // macOS uses this path
#else
#include <GL/glut.h>    // Linux and Windows use this
#endif

#include "rectangle.hpp"

class Square : public Rectangle {
public:
    Square(std::array<int, 2> topLeft, int sideLength, std::array<int, 3> color);
};

#endif // SQUARE_HPP
