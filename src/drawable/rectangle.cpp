
#include "rectangle.hpp"

Rectangle::Rectangle(std::array<int, 2> topLeft, std::array<int, 2> bottomRight, std::array<int, 3> color)
    : Object(color), topLeft(topLeft), bottomRight(bottomRight) {}

void Rectangle::Draw() {
    glColor3ub(color[0], color[1], color[2]);
    glBegin(GL_QUADS);
    glVertex2f(topLeft[0], topLeft[1]);
    glVertex2f(bottomRight[0], topLeft[1]);
    glVertex2f(bottomRight[0], bottomRight[1]);
    glVertex2f(topLeft[0], bottomRight[1]);
    glEnd();
}
