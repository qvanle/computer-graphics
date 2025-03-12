// this file is use to test feature draw circle
#ifdef __APPLE__
#include <GLUT/glut.h>  // macOS uses this path
#else
#include <GL/glut.h>    // Linux and Windows use this
#endif

#include "window.hpp"
#include "circle.hpp"

Circle x = Circle({325, 220}, 100, {255, 10, 10}, true, 100);
Circle y = Circle({325, 221}, 98, {255, 10, 10}, false, 100);

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
    NewWindow window("Circle Test", 800, 600);
    
    // Run the window loop
    window.run();

    return 0;
}

