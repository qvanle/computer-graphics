#include "hexagon.hpp"

#define PI 3.14159265358979323846

RegularHexagon::RegularHexagon(std::array<int, 2> center, int sideLength, std::array<int, 3> color)
    : Object(color), center(center), sideLength(sideLength) {
    CalculateVertices();
}

void RegularHexagon::CalculateVertices() {
    vertices.clear();
    float radius = sideLength;  // Circumradius of a regular hexagon equals its side length
    for (int i = 0; i < 6; i++) {
        float angle = 2 * PI * i / 6;  // Angles at equal intervals
        float x = center[0] + radius * cos(angle);
        float y = center[1] + radius * sin(angle);
        vertices.push_back({x, y});
    }
}

void RegularHexagon::Draw() {
    glColor3ub(color[0], color[1], color[2]);
    glBegin(GL_POLYGON);
    for (const auto& vertex : vertices) {
        glVertex2f(vertex[0], vertex[1]);
    }
    glEnd();
}

