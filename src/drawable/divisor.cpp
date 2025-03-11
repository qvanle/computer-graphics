#include "division.hpp"

DivisionSign::DivisionSign(std::array<int, 2> position, int size, std::array<int, 3> color)
    : Object(color), position(position), size(size) {}

void DivisionSign::Draw() {
    glColor3ub(color[0], color[1], color[2]);
    glLineWidth(5);  // Set line thickness

    glBegin(GL_LINES);
    // Horizontal line (-)
    glVertex2f(position[0] - size / 2.0, position[1]);
    glVertex2f(position[0] + size / 2.0, position[1]);
    glEnd();

    // Draw top dot
    glPointSize(8);
    glBegin(GL_POINTS);
    glVertex2f(position[0], position[1] + size / 2.0);
    glEnd();

    // Draw bottom dot
    glBegin(GL_POINTS);
    glVertex2f(position[0], position[1] - size / 2.0);
    glEnd();
}

