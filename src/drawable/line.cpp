#include "line.hpp"

Line::Line(std::array<int, 2> start, std::array<int, 2> end, std::array<int, 3> color)
    : Object(color), start(start), end(end) {}

void Line::Draw() {
    glColor3ub(color[0], color[1], color[2]);
    glLineWidth(5.0f);  // Set line width to 5 pixels
    glBegin(GL_LINES);
    glVertex2f(start[0], start[1]);
    glVertex2f(end[0], end[1]);
    glEnd();
}
