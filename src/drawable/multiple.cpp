
#include "multiplication.hpp"

MultiplicationSign::MultiplicationSign(std::array<int, 2> position, int size, std::array<int, 3> color)
    : Object(color), position(position), size(size) {}

void MultiplicationSign::Draw() {
    glColor3ub(color[0], color[1], color[2]);
    glLineWidth(5);  // Set line thickness

    glBegin(GL_LINES);
    // First diagonal line (\)
    glVertex2f(position[0] - size / 2.0, position[1] - size / 2.0);
    glVertex2f(position[0] + size / 2.0, position[1] + size / 2.0);

    // Second diagonal line (/)
    glVertex2f(position[0] - size / 2.0, position[1] + size / 2.0);
    glVertex2f(position[0] + size / 2.0, position[1] - size / 2.0);
    glEnd();
}
