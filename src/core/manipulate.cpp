#ifdef __APPLE__
#include <GLUT/glut.h>  // macOS uses this path
#else
#include <GL/glut.h>    // Linux and Windows use this
#endif

#include <string>
#include <iostream>
#include <fstream>

#include "manipulate.hpp"

Manipulate::Manipulate(std::string name) : x(0), y(0), width(150), height(200), active(false) {
    // open file assets/${name} and read each line into options  
    this->name = name;
    name = "assets/manipulate/" + name + ".txt";
    std::ifstream file(name);
    if (!file.is_open()) {
        std::cerr << "Error: could not open file " << name << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        options.push_back(line);
    }

    int n = options.size();
    height = n * 25;
    width = 300;
}

Manipulate::Manipulate(std::string name, int x, int y) : x(x), y(y), width(150), height(200), active(true) {
    this->name = name;
    name = "assets/manipulate/" + name + ".txt";
    std::ifstream file(name);
    if (!file.is_open()) {
        std::cerr << "Error: could not open file " << name << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        options.push_back(line);
    }

    int n = options.size();
    height = n * 25;
    width = 300;
}

void Manipulate::move(int x, int y) {
    this->x = x;
    this->y = y;
}


void Manipulate::display() {
    if (!active) return;
    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y - height);
    glVertex2f(x, y - height);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    for (size_t i = 0; i < options.size(); ++i) {
        glRasterPos2f(x + 10, y - 20 - (i * 25));
        for (char c : options[i]) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
        }
    }
    
}

void Manipulate::swi() {
    active = !active;
}

void Manipulate::display(int x, int y) {
    move(x, y);
    display();
}

void Manipulate::swiDisplay() {
    active = !active;
    if (active) display();
}

void Manipulate::swiDisplay(int x, int y) {
    move(x, y);
    swiDisplay();
}

bool Manipulate::isInside(int mx, int my) {
    return mx >= x && mx <= x + width && my >= y - height && my <= y;
}

int Manipulate::getOptionIndex(int mx, int my) {
    if (!isInside(mx, my)) return -1;
    return (y - my) / 25;
}

void Manipulate::deactivate() {
    active = false;
}

bool Manipulate::isActive() const {
    return active;
}

std::unique_ptr<Manipulate> MANI::menu = std::make_unique<Manipulate>("menu");
std::unique_ptr<Manipulate> MANI::line = std::make_unique<Manipulate>("line");
std::unique_ptr<Manipulate> MANI::triangle = std::make_unique<Manipulate>("triangle");
std::unique_ptr<Manipulate> MANI::quadrilateral = std::make_unique<Manipulate>("quadrilateral");
std::unique_ptr<Manipulate> MANI::oval = std::make_unique<Manipulate>("oval");
std::unique_ptr<Manipulate> MANI::polygon = std::make_unique<Manipulate>("polygon");
std::unique_ptr<Manipulate> MANI::operation = std::make_unique<Manipulate>("operation");
std::unique_ptr<Manipulate> MANI::other = std::make_unique<Manipulate>("other");

