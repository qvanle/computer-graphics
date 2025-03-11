#include "pentagon.hpp"

#define PI 3.14159265358979323846

RegularPentagon::RegularPentagon(std::array<int, 2> center, int sideLength, std::array<int, 3> color)
    : Object(color), center(center), sideLength(sideLength) {
    CalculateVertices();
}

void RegularPentagon::CalculateVertices() {
    vertices.clear();
    float radius = sideLength / (2 * sin(PI / 5));  // Calculate the circumradius of the pentagon
    for (int i = 0; i < 5; i++) {
        float angle = 2 * PI * i / 5 - PI / 2;  // Rotate so the top vertex is upright
        float x = center[0] + radius * cos(angle);
        float y = center[1] + radius * sin(angle);
        vertices.push_back({x, y});
    }
}

void RegularPentagon::Draw() {
    glColor3ub(color[0], color[1], color[2]);
    glBegin(GL_POLYGON);
    for (const auto& vertex : vertices) {
        glVertex2f(vertex[0], vertex[1]);
    }
    glEnd();
}

