
#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP

#ifdef __APPLE__
#include <GLUT/glut.h>  // macOS uses this path
#else
#include <GL/glut.h>    // Linux and Windows use this
#endif

#include "object.hpp"
#include <array>

class Ellipse : public Object {
private:
    std::array<int, 2> center;
    int width;
    int height;

public:
    Ellipse(std::array<int, 2> center, int width, int height, std::array<int, 3> color);
    void Draw() override;
};

#endif // ELLIPSE_HPP
