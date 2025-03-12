#include <OpenGL/gl.h>
#ifdef __APPLE__
#include <GLUT/glut.h>  // macOS uses this path
#else
#include <GL/glut.h>    // Linux and Windows use this
#endif

#include "Hexagon.hpp"
#include <cmath>

#define PI 3.14159265

Hexagon::Hexagon(std::array<int, 2> center, int radius, std::array<unsigned char, 3> boundary_color, bool needboundary)
    : Object(boundary_color), center(center), radius(radius), needBoundary(needboundary) {
    calculateVertices();
}

void Hexagon::calculateVertices() {
    vertices.clear();
    for (int i = 0; i < 6; i++) {
        double angle = 2.0 * PI * i / 6; // 60-degree increments
        int x = center[0] + static_cast<int>(radius * cos(angle));
        int y = center[1] + static_cast<int>(radius * sin(angle));
        vertices.push_back({x, y});
    }
}

void Hexagon::draw() {
    glColor3ub(boundary_color[0], boundary_color[1], boundary_color[2]);
    glLineWidth(10);
    glBegin(GL_LINE_LOOP);
    for (const auto& vertex : vertices) {
        glVertex2i(vertex[0], vertex[1]);
    }
    glEnd();
    glPointSize(6);
    glBegin(GL_POINTS);
    for (const auto& vertex : vertices) {
        glVertex2i(vertex[0], vertex[1]);
    }
    glEnd();

    if(needBoundary) boundaryFillNoRecur(center, boundary_color);
}

