#ifndef LINE_HPP
#define LINE_HPP

#ifdef __APPLE__
#include <GLUT/glut.h>  // macOS uses this path
#else
#include <GL/glut.h>    // Linux and Windows use this
#endif

#include "object.hpp"
#include <array>

class Line : public Object {
private:
    std::array<int, 2> start;
    std::array<int, 2> end;

public:
    Line(std::array<int, 2> start, std::array<int, 2> end, std::array<int, 3> color);
    void Draw();
};

#endif // LINE_HPP
