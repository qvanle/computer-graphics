
#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#ifdef __APPLE__
#include <GLUT/glut.h>  // macOS uses this path
#else
#include <GL/glut.h>    // Linux and Windows use this
#endif

#include "object.hpp"
#include <array>

class Circle : public Object {
private:
    std::array<int, 2> center;
    int radius;

public:
    Circle(std::array<int, 2> center, int radius, std::array<int, 3> color);
    void Draw() override;
};

#endif // CIRCLE_HPP
