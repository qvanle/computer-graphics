// this file is use to test the feature draw ellipse
#ifdef __APPLE__
#include <GLUT/glut.h>  // macOS uses this path
#else
#include <GL/glut.h>    // Linux and Windows use this
#endif

#include "window.hpp"
#include "ellipse.hpp"

Ellipse x = Ellipse({325, 220}, 100, 50, {255, 10, 10}, true, 100);
Ellipse y = Ellipse({325, 221}, 98, 48, {255, 10, 10}, false, 100);

class NewWindow : public Window {
private: 
    static void displayCallBack(){
        glClear(GL_COLOR_BUFFER_BIT);
        x.draw();
        y.draw();
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
    NewWindow window("Ellipse Test", 800, 600);
    
    // Run the window loop
    window.run();

    return 0;
}

