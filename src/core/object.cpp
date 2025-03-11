#ifdef __APPLE__
#include <GLUT/glut.h>  // macOS uses this path
#else
#include <GL/glut.h>    // Linux and Windows use this
#endif


#include "object.hpp"

Object::Object() : color({0, 0, 0}) {}

Object::Object(int r, int g, int b) : color({r, g, b}) {}

Object::Object(std::array<int, 3> color) : color(color) {}

void Object::PutPixel(int x, int y) {
    glColor3ub(color[0], color[1], color[2]);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

std::array<int, 3> Object::GetPixel(int x, int y) {
    std::array<int, 3> pixel;
    glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &pixel);
    return pixel;
}

void Object::Draw() {}
