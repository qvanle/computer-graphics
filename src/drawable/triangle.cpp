#include "triangle.hpp"

Triangle::Triangle(std::array<int, 2> v1, std::array<int, 2> v2, std::array<int, 2> v3, std::array<int, 3> color)
    : Object(color), v1(v1), v2(v2), v3(v3) {}

void Triangle::Draw() {
    glColor3ub(color[0], color[1], color[2]);
    glBegin(GL_TRIANGLES);
    glVertex2f(v1[0], v1[1]);
    glVertex2f(v2[0], v2[1]);
    glVertex2f(v3[0], v3[1]);
    glEnd();
}

