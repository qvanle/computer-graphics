#ifdef __APPLE__
#include <GLUT/glut.h>  // macOS uses this path
#else
#include <GL/glut.h>    // Linux and Windows use this
#endif


#include <cstdlib>

#include "window.hpp"


ConfigPopup* Window::popup = nullptr;
bool Window::popupActive = false;
int Window::popupX = 0;
int Window::popupY = 0;


Rectangle Window::rec01 = Rectangle({325, 222}, {475, 325}, {0, 0, 0});
Rectangle Window::rec02 = Rectangle({326, 223}, {474, 324}, {0, 0, 0});

Hexagon Window::hex01 = Hexagon({325, 220}, 100, {0, 0, 0}, true);
Hexagon Window::hex02 = Hexagon({326, 223}, 95, {0, 0, 0}, true);
    
Ellipse Window::ellipse01 = Ellipse({325, 220}, 100, 50, {0, 0, 0}, true, 100);
Ellipse Window::ellipse02 = Ellipse({325, 221}, 98, 48, {0, 0, 0}, false, 100);

Circle Window::circle01 = Circle({325, 220}, 100, {0, 0, 0}, true, 100);
Circle Window::circle02 = Circle({325, 221}, 98, {0, 0, 0}, false, 100);

int Window::chooseShape = -1;

// Static function for display callback
void Window::displayCallback() {
    glClear(GL_COLOR_BUFFER_BIT);
    if (popupActive) {
        glPushMatrix();
        glTranslatef(popupX, popupY, 0);  // Move popup to mouse click location
        popup->display();
        glPopMatrix();
    }
    switch (chooseShape) {
        case 0:
            circle01.draw();
            circle02.draw();
            break;
        case 1:
            ellipse01.draw();
            ellipse02.draw();
            break;
        case 2: 
            rec01.draw();
            rec02.draw();
            break;
        case 3:
            hex01.draw();
            hex02.draw();
            break;
        default:
            break;
    }
    glFlush();
}

// Static function for keyboard input
void Window::keyCallback(unsigned char key, int x, int y) {
    if (key == 27) { // Escape key
        exit(0);
    }
}
void Window::mouseCallback(int button, int state, int x, int y) {
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        // Show popup at mouse position
        popupX = x;
        popupY = y;
        popupActive = true;
        glutPostRedisplay();
    } 
    else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (popupActive) {
            int insidePopup = popup->mouseClick(button, state, x - popupX, y - popupY);
            if (!insidePopup) {
                popupActive = false;  // Close popup if clicked outside
            }
            if(insidePopup == 2){
                popupActive = false;
                chooseShape = popup->getShape();
                int colorid = popup->getColor();
                std::array<unsigned char, 3> color;
                if(colorid == 0) color = {0, 0, 0};
                if(colorid == 1) color = {255, 0, 0};
                if(colorid == 2) color = {0, 255, 0};
                if(colorid == 3) color = {0, 0, 255};
                
                rec01.setColor(color);
                rec02.setColor(color);

                circle01.setColor(color);
                circle02.setColor(color);

                ellipse01.setColor(color);
                ellipse02.setColor(color);

                hex01.setColor(color);
                hex02.setColor(color);

            }
            glutPostRedisplay();
        }
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
    exit(0);
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

    // 🔴 Set 2D Projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, height, 0);  // Flip Y-axis so (0,0) is top-left
    glMatrixMode(GL_MODELVIEW);

    glClearColor(0.96f, 0.96f, 0.86f, 1.0f); // Beige background color

    // Register the display callback
    glutDisplayFunc(Window::displayCallback);

    // Register the key callback
    glutKeyboardFunc(Window::keyCallback);

    // Register the mouse callback 
    glutMouseFunc(Window::mouseCallback);


    // Initialize popup
    popup = new ConfigPopup(400, 200);  
}

void Window::run() {
    glutMainLoop();
}
