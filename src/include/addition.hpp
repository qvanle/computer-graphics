#ifndef ADDITION_SIGN_HPP
#define ADDITION_SIGN_HPP

#ifdef __APPLE__
#include <GLUT/glut.h>  // macOS uses this path
#else
#include <GL/glut.h>    // Linux and Windows use this
#endif

#include "object.hpp"
#include <array>

class AdditionSign : public Object {
private:
    std::array<int, 2> position;
    int size;

public:
    AdditionSign(std::array<int, 2> position, int size, std::array<int, 3> color);
    void Draw();
};

#endif // ADDITION_SIGN_HPP
