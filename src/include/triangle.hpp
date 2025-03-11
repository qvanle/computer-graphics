#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#ifdef __APPLE__
#include <GLUT/glut.h>  // macOS uses this path
#else
#include <GL/glut.h>    // Linux and Windows use this
#endif

#include "object.hpp"
#include <array>

class Triangle : public Object {
private:
    std::array<int, 2> v1;
    std::array<int, 2> v2;
    std::array<int, 2> v3;

public:
    Triangle(std::array<int, 2> v1, std::array<int, 2> v2, std::array<int, 2> v3, std::array<int, 3> color);
    void Draw();
};

#endif // TRIANGLE_HPP
