#ifdef __APPLE__
#include <GLUT/glut.h>  // macOS uses this path
#else
#include <GL/glut.h>    // Linux and Windows use this
#endif


#include <cstdlib>

#include "window.hpp"

// Static function for display callback
void Window::displayCallback() {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

// Static function for keyboard input
void Window::keyCallback(unsigned char key, int x, int y) {
    if (key == 27) { // Escape key
        exit(0);
    }
}

Window::Window(std::string title) : title(title), fullscreen(true) {
    initialize();
}

Window::Window(std::string title, int width, int height) 
    : title(title), width(width), height(height), fullscreen(false) {
    initialize();
}

Window::~Window() {
    if (fullscreen) {
        glutLeaveGameMode();
    }
}

void Window::initialize() {
    int argc = 1;
    char* argv[1] = {(char*)"app"};
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    if (fullscreen) {
        glutGameModeString("1920x1080:32@60"); // Example fullscreen mode
        glutEnterGameMode();
    } else {
        glutInitWindowSize(width, height);
        glutCreateWindow(title.c_str());
    }

    glClearColor(0.96f, 0.96f, 0.86f, 1.0f); // Beige background color

    // Register the display callback
    glutDisplayFunc(Window::displayCallback);

    // Register the key callback
    glutKeyboardFunc(Window::keyCallback);
}

void Window::run() {
    glutMainLoop();
}
