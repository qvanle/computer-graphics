#ifdef __APPLE__
#include <GLUT/glut.h>  // macOS uses this path
#else
#include <GL/glut.h>    // Linux and Windows use this
#endif

#include <cstdlib>
#include <memory>
#include <iostream>

#include "action.hpp"
#include "window.hpp"

std::shared_ptr<Action> Window::action = nullptr;

// Static function for display callback
void Window::displayCallback() {
    glClear(GL_COLOR_BUFFER_BIT);
    action->fill();
    glFlush();
}

// Static function for keyboard input
void Window::keyCallback(unsigned char key, int x, int y) {
    if (key == 27) { // Escape key
        exit(0);
    }
}

// Static function for mouse input
void Window::mouseCallback(int button, int state, int x, int y) {
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        action->orderfill(x, y, {0, 0, 0});
        glutPostRedisplay();
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
        glViewport(0, 0, glutGet(GLUT_SCREEN_WIDTH), glutGet(GLUT_SCREEN_HEIGHT));
        width = glutGet(GLUT_SCREEN_WIDTH);
        height = glutGet(GLUT_SCREEN_HEIGHT);
    } else {
        glutInitWindowSize(width, height);
        glutCreateWindow(title.c_str());
    }

    // 🔴 Set 2D Projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, height, 0);  // Flip Y-axis so (0,0) is top-left
    glMatrixMode(GL_MODELVIEW);

    glClearColor(0.99f, 0.99f, 0.93f, 1.0f); // Beige background color
    // set drawing color to black
    glColor3f(0.0f, 0.0f, 0.0f);

    // Register the display callback
    glutDisplayFunc(Window::displayCallback);

    // Register the key callback
    glutKeyboardFunc(Window::keyCallback);
    
    // Register the mouse callback 
    glutMouseFunc(Window::mouseCallback);
    
    action = std::make_shared<Action>(std::make_shared<Window>(*this));
}

void Window::run() {
    glutMainLoop();
}
