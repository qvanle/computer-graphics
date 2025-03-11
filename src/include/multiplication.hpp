#ifndef MULTIPLICATION_SIGN_HPP
#define MULTIPLICATION_SIGN_HPP

#ifdef __APPLE__
#include <GLUT/glut.h>  // macOS uses this path
#else
#include <GL/glut.h>    // Linux and Windows use this
#endif

#include "object.hpp"
#include <array>

class MultiplicationSign : public Object {
private:
    std::array<int, 2> position;
    int size;

public:
    MultiplicationSign(std::array<int, 2> position, int size, std::array<int, 3> color);
    void Draw();
};

#endif // MULTIPLICATION_SIGN_HPP

