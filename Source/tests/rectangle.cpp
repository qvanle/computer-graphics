// this file is use to test the feature draw rectangle
#ifdef __APPLE__
#include <GLUT/glut.h>  // macOS uses this path
#else
#include <GL/glut.h>    // Linux and Windows use this
#endif

#include "window.hpp"
#include "rectangle.hpp"

Rectangle x = Rectangle({325, 222}, {475, 325}, {255, 10, 10});

class NewWindow : public Window {
private: 
    static void displayCallBack(){
        glClear(GL_COLOR_BUFFER_BIT);
        x.draw();
        glFlush();
    }        
public:
    NewWindow(const char* title) : Window(title) {
        glutDisplayFunc(displayCallBack);
    }
    
    NewWindow(const char* title, int width, int height) : Window(title, width, height) {
        glutDisplayFunc(displayCallBack);
    }
};

int main() {
    // Create a fullscreen window with a title
    NewWindow window("Rectangle Test", 800, 600);
    
    // Run the window loop
    window.run();

    return 0;
}

