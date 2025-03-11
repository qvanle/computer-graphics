#include "arrow.hpp"
#include <cmath>

Arrow::Arrow(std::array<int, 2> start, std::array<int, 2> end, int headSize, std::array<int, 3> color)
    : Object(color), start(start), end(end), headSize(headSize) {}

void Arrow::Draw() {
    glColor3ub(color[0], color[1], color[2]);
    glLineWidth(3);  // Set line thickness

    // Draw the shaft (line)
    glBegin(GL_LINES);
    glVertex2f(start[0], start[1]);
    glVertex2f(end[0], end[1]);
    glEnd();

    // Calculate arrowhead direction
    float angle = atan2(end[1] - start[1], end[0] - start[0]);

    // Compute arrowhead points
    std::array<int, 2> left = {
        static_cast<int>(end[0] - headSize * cos(angle - M_PI / 6.0)),
        static_cast<int>(end[1] - headSize * sin(angle - M_PI / 6.0))
    };
    
    std::array<int, 2> right = {
        static_cast<int>(end[0] - headSize * cos(angle + M_PI / 6.0)),
        static_cast<int>(end[1] - headSize * sin(angle + M_PI / 6.0))
    };

    // Draw the arrowhead (triangle)
    glBegin(GL_TRIANGLES);
    glVertex2f(end[0], end[1]);
    glVertex2f(left[0], left[1]);
    glVertex2f(right[0], right[1]);
    glEnd();
}

