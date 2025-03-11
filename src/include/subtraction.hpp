#ifndef MINUS_SIGN_HPP
#define MINUS_SIGN_HPP

#ifdef __APPLE__
#include <GLUT/glut.h>  // macOS uses this path
#else
#include <GL/glut.h>    // Linux and Windows use this
#endif

#include "object.hpp"
#include <array>

class MinusSign : public Object {
private:
    std::array<int, 2> position;
    int width;

public:
    MinusSign(std::array<int, 2> position, int width, std::array<int, 3> color);
    void Draw();
};

#endif // MINUS_SIGN_HPP
