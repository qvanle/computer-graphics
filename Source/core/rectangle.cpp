#ifdef __APPLE__
#include <GLUT/glut.h>  // macOS uses this path
#else
#include <GL/glut.h>    // Linux and Windows use this
#endif

#include "Rectangle.hpp"

Rectangle::Rectangle(std::array<int, 2> top_left, std::array<int, 2> bottom_right, std::array<unsigned char, 3> boundary_color)
    : Object(boundary_color), top_left(top_left), bottom_right(bottom_right) {}

void Rectangle::draw() {
    glColor3ub(boundary_color[0], boundary_color[1], boundary_color[2]);
    glLineWidth(8);
    glBegin(GL_LINE_LOOP);
    glVertex2i(top_left[0], top_left[1]);
    glVertex2i(bottom_right[0], top_left[1]);
    glVertex2i(bottom_right[0], bottom_right[1]);
    glVertex2i(top_left[0], bottom_right[1]);
    glEnd();
    glPointSize(8);
    glBegin(GL_POINTS);
    glVertex2i(top_left[0], top_left[1]);
    glVertex2i(bottom_right[0], top_left[1]);
    glVertex2i(bottom_right[0], bottom_right[1]);
    glVertex2i(top_left[0], bottom_right[1]);
    glEnd();


    std::array<int, 2> center;
    center[0] = (top_left[0] + bottom_right[0]) / 2;
    center[1] = (top_left[1] + bottom_right[1]) / 2;
    std::array<unsigned char, 3> fill_color = boundary_color;
    boundaryFillNoRecur(center, fill_color);
}
