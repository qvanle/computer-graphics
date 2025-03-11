#include <iostream>

#include "window.hpp"
#include "subtraction.hpp"

MinusSign x = MinusSign({640, 400}, 200, {0, 0, 0});

class NewWindow : public Window {
// inherit all 
// override the static functions
private:
    static void displayCallback() {
        std::cout << "Display Callback" << std::endl;
        glClear(GL_COLOR_BUFFER_BIT);
        x.Draw();
        glFlush();
    }
public:
    NewWindow(std::string title) : Window(title){
        glutDisplayFunc(displayCallback);
    }
};

int main() {
    // Create a fullscreen window with a title
    NewWindow window("Subtraction Test");
    // Run the window loop
    window.run();

    return 0;
}

