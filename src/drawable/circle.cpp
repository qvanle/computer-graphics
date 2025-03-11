#include "circle.hpp"
#include <cmath>

#define PI 3.14159265358979323846

Circle::Circle(std::array<int, 2> center, int radius, std::array<int, 3> color)
    : Object(color), center(center), radius(radius) {}

void Circle::Draw() {
    glColor3ub(color[0], color[1], color[2]);

    glBegin(GL_POLYGON);
    
    // Draw circle using small line segments
    for (int i = 0; i < 360; i++) {
        float angle = i * PI / 180.0; // Convert degrees to radians
        float x = center[0] + radius * cos(angle);
        float y = center[1] + radius * sin(angle);
        glVertex2f(x, y);
    }

    glEnd();
}

