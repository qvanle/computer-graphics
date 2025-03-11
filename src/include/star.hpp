#ifndef STAR_HPP
#define STAR_HPP

#ifdef __APPLE__
#include <GLUT/glut.h>  // macOS uses this path
#else
#include <GL/glut.h>    // Linux and Windows use this
#endif

#include "object.hpp"
#include <array>

class Star : public Object {
private:
    std::array<int, 2> center;
    int size;

public:
    Star(std::array<int, 2> center, int size, std::array<int, 3> color);
    void Draw() override;
};

#endif // STAR_HPP
