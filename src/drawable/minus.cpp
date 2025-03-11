#include "subtraction.hpp"

MinusSign::MinusSign(std::array<int, 2> position, int width, std::array<int, 3> color)
    : Object(color), position(position), width(width) {}

void MinusSign::Draw() {
    glColor3ub(color[0], color[1], color[2]);
    glLineWidth(5);  // Set line thickness
    glBegin(GL_LINES);
    glVertex2f(position[0] - width / 2.0, position[1]);
    glVertex2f(position[0] + width / 2.0, position[1]);
    glEnd();
}
