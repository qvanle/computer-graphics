#ifdef __APPLE__
#include <GLUT/glut.h>  // macOS uses this path
#else
#include <GL/glut.h>    // Linux and Windows use this
#endif

#include <iostream>
#include <queue>

#include "object.hpp"


Object::Object() {
    boundary_color = {0, 0, 0};
}

Object::Object(std::array<unsigned char, 3> boundary_color) {
    this->boundary_color = boundary_color;
}

Object::~Object() {
    // Nothing to do here
}

void Object::setColor(std::array<unsigned char, 3> color){
    this->boundary_color = color;
}

void Object::putPixel(std::array<int, 2> pos, std::array<unsigned char, 3> color) {
    glBegin(GL_POINTS);
    glColor3ub(color[0], color[1], color[2]);
    glVertex2i(pos[0], pos[1]);
    glEnd();
}

std::array<unsigned char, 3> Object::readPixel(std::array<int, 2> pos) {
    unsigned char pixel[3];
    glReadPixels(pos[0], 600 - pos[1], 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixel);
    return {pixel[0], pixel[1], pixel[2]};
}

void Object::boundaryFillNoRecur(std::array<int, 2> seed, std::array<unsigned char, 3> fill_color) {
    std::queue<std::array<int, 2>> q;
    q.push(seed);
    int pointSize = 2;
    glPointSize(pointSize);
    int cnt = 0;
    while (!q.empty()) {
        std::array<int, 2> current = q.front();
        q.pop();
        std::array<unsigned char, 3> current_color = readPixel(current);
        if(current_color == boundary_color) {
            continue;
        }
        if(current_color == fill_color) {
            continue;
        }
        
        putPixel(current, fill_color);
        q.push({current[0] + pointSize, current[1]});
        q.push({current[0] - pointSize, current[1]});
        q.push({current[0], current[1] + pointSize});
        q.push({current[0], current[1] - pointSize});
        cnt++;

    }
    std::cout << "Finished filling " << cnt << " pixels" << std::endl;
} 

void Object::boundaryFill(std::array<int, 2> seed, std::array<unsigned char, 3> fill_color) {
    std::array<unsigned char, 3> current_color = readPixel(seed);
    if (current_color != boundary_color && current_color != fill_color) {
        putPixel(seed, fill_color);
        boundaryFill({seed[0] + 1, seed[1]}, fill_color);
        boundaryFill({seed[0] - 1, seed[1]}, fill_color);
        boundaryFill({seed[0], seed[1] + 1}, fill_color);
        boundaryFill({seed[0], seed[1] - 1}, fill_color);
    }
}

void Object::draw() {
    // Nothing to do here
}



