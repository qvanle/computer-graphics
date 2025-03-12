#ifdef __APPLE__
#include <GLUT/glut.h>  // macOS uses this path
#else
#include <GL/glut.h>    // Linux and Windows use this
#endif

#include <queue>
#include <array>
#include <iostream>

#include "action.hpp"

Action::Action(std::shared_ptr<Window> ins) : instance(ins) {}

void Action::putPixel(int x, int y, std::array<int, 3> color) {
    glBegin(GL_POINTS);   
    glColor3ub(color[0], color[1], color[2]);
    glVertex2i(x, y);
    glEnd();
}

std::array<int, 3> Action::getPixel(int x, int y) {
    std::array<int, 3> color;
    glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, &color);
    return color;
}

void Action::fill() {
    fill(fillation.x, fillation.y, fillation.color);
}

void Action::fill(int x, int y, std::array<int, 3> color, std::array<int, 3> lastColor) {
    if (!fillation.status) {
        
        return;
    }
    //fillation.status = false;
    /**
    if(x < 0 || x >= instance->width || y < 0 || y >= instance->height) {
        return;
    }
    std::array<int, 3> currentColor = getPixel(x, y);
    if(lastColor[0] == -1) {
        lastColor = currentColor;
        if(isColorSimilar(currentColor, color)) {
            return;
        }
    }
    if(!isColorSimilar(currentColor, lastColor)) {
        return;
    }

    putPixel(x, y, color);
    fill(x + 1, y, color, lastColor);
    fill(x - 1, y, color, lastColor);
    fill(x, y + 1, color, lastColor);
    fill(x, y - 1, color, lastColor);
    **/ 
    std::queue< std::pair<int, int> > q;
    q.push({x, y});
    int cnt = 0;
    glColor3ub(color[0], color[1], color[2]);
    // set pixel size to 20
    int pointSize = 30;
    glPointSize(pointSize);
    glBegin(GL_POINTS);
    while(!q.empty()) {
        std::pair<int, int> p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;

        if(x < 0 || x >= instance->width || y < 0 || y >= instance->height) {
            continue;
        }
        std::array<int, 3> currentColor = getPixel(x, y);
        if(lastColor[0] == -1) {
            lastColor = currentColor;
            if(isColorSimilar(currentColor, color)) {
                break;
            }
        }
        if(!isColorSimilar(currentColor, lastColor)) {
            continue;
        }
        
        glVertex2i(x, y);

        q.push({x + pointSize, y});
        q.push({x - pointSize, y});
        q.push({x, y + pointSize});
        q.push({x, y - pointSize});
        cnt++;
        if(cnt > 200000) {
            break;
        }
    }
    glEnd();
    glFlush();
}

bool Action::isColorSimilar(std::array<int, 3> color1, std::array<int, 3> color2, int tolerance) {
    int dir = abs(color1[0] - color2[0]);
    int dig = abs(color1[1] - color2[1]);
    int dib = abs(color1[2] - color2[2]);
    if (dir > tolerance || dig > tolerance || dib > tolerance) {
        return false;
    }
    return dir + dig + dib <= tolerance * 3 * 0.8;
}

void Action::orderfill(int x, int y, std::array<int, 3> color){
    fillation.x = x;
    fillation.y = y;
    fillation.color = color;
    fillation.status = true;
}

void Action::boundaryFill(int x, int y, std::array<int, 3> fillColor, std::array<int, 3> boundaryColor) {
    if (x < 0 || x >= instance->width || y < 0 || y >= instance->height) {
        return;
    }
    std::array<int, 3> currentColor = getPixel(x, y);
    if (isColorSimilar(currentColor, boundaryColor)) {
        return;
    }
    if (!isColorSimilar(currentColor, fillColor)) {
        putPixel(x, y, fillColor);
        boundaryFill(x + 1, y, fillColor, boundaryColor);
        boundaryFill(x - 1, y, fillColor, boundaryColor);
        boundaryFill(x, y + 1, fillColor, boundaryColor);
        boundaryFill(x, y - 1, fillColor, boundaryColor);
    }
}

