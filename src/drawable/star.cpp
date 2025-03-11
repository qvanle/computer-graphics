#include "star.hpp"
#include <cmath>

#define PI 3.14159265358979323846

Star::Star(std::array<int, 2> center, int size, std::array<int, 3> color)
    : Object(color), center(center), size(size) {}

void Star::Draw() {
    glColor3ub(color[0], color[1], color[2]);

    glBegin(GL_TRIANGLE_FAN); // Use triangle fan to fill the star

    // Center of the star
    glVertex2f(center[0], center[1]);

    // Generate the 5 points of the star
    for (int i = 0; i <= 10; i++) {
        float angle = i * PI / 5.0; // Divide full circle into 10 parts
        float radius = (i % 2 == 0) ? size : size / 2.5; // Alternate large and small radius

        float x = center[0] + radius * cos(angle);
        float y = center[1] + radius * sin(angle);
        glVertex2f(x, y);
    }

    glEnd();
}

