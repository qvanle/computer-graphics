
#ifndef REGULAR_PENTAGON_HPP
#define REGULAR_PENTAGON_HPP

#ifdef __APPLE__
#include <GLUT/glut.h>  // macOS uses this path
#else
#include <GL/glut.h>    // Linux and Windows use this
#endif

#include "object.hpp"
#include <array>
#include <vector>
#include <cmath>

class RegularPentagon : public Object {
private:
    std::array<int, 2> center;
    int sideLength;
    std::vector<std::array<float, 2>> vertices;

public:
    RegularPentagon(std::array<int, 2> center, int sideLength, std::array<int, 3> color);
    void Draw();
    void CalculateVertices();
};

#endif // REGULAR_PENTAGON_HPP
