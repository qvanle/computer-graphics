#ifndef ARROW_HPP
#define ARROW_HPP

#ifdef __APPLE__
#include <GLUT/glut.h>  // macOS uses this path
#else
#include <GL/glut.h>    // Linux and Windows use this
#endif

#include "object.hpp"
#include <array>

class Arrow : public Object {
private:
    std::array<int, 2> start;
    std::array<int, 2> end;
    int headSize;

public:
    Arrow(std::array<int, 2> start, std::array<int, 2> end, int headSize, std::array<int, 3> color);
    void Draw() override;
};

#endif // ARROW_HPP

