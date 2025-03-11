#include "ellipse.hpp"
#include <cmath>

#define PI 3.14159265358979323846

Ellipse::Ellipse(std::array<int, 2> center, int width, int height, std::array<int, 3> color)
    : Object(color), center(center), width(width), height(height) {}

void Ellipse::Draw() {
    glColor3ub(color[0], color[1], color[2]);

    glBegin(GL_POLYGON);
    
    // Draw ellipse using small line segments
    for (int i = 0; i < 360; i++) {
        float angle = i * PI / 180.0; // Convert degrees to radians
        float x = center[0] + (width / 2.0) * cos(angle);
        float y = center[1] + (height / 2.0) * sin(angle);
        glVertex2f(x, y);
    }

    glEnd();
}

