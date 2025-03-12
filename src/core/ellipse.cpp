#include <OpenGL/gl.h>
#ifdef __APPLE__
#include <GLUT/glut.h>  // macOS uses this path
#else
#include <GL/glut.h>    // Linux and Windows use this
#endif


#include "Ellipse.hpp"
#include <cmath>

#define PI 3.14159265

Ellipse::Ellipse(std::array<int, 2> center, int radius_x, int radius_y, std::array<unsigned char, 3> boundary_color, bool needbound, int num_segments)
    : Object(boundary_color), center(center), radius_x(radius_x), radius_y(radius_y), needBoundary(needbound), num_segments(num_segments) {}

void Ellipse::draw(){
    glColor3ub(boundary_color[0], boundary_color[1], boundary_color[2]);
    glLineWidth(10);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < num_segments; i++) {
        double angle = 2.0 * PI * i / num_segments;
        int x = center[0] + static_cast<int>(radius_x * cos(angle));
        int y = center[1] + static_cast<int>(radius_y * sin(angle));
        glVertex2i(x, y);
    }
    glEnd();
    glBegin(GL_POINTS);
    for (int i = 0; i < num_segments; i++) {
        double angle = 2.0 * PI * i / num_segments;
        int x = center[0] + static_cast<int>(radius_x * cos(angle));
        int y = center[1] + static_cast<int>(radius_y * sin(angle));
        glVertex2i(x, y);
    }
    glEnd();
    
    if(needBoundary) boundaryFillNoRecur(center, boundary_color);
}

