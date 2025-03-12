#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include "config_popup.hpp"

#include "rectangle.hpp"
#include "ellipse.hpp"
#include "circle.hpp"
#include "hexagon.hpp"

class Window {
private:
    std::string title;
    int width;
    int height;
    bool fullscreen;    
    static ConfigPopup* popup;  // Pointer to the popup
    static bool popupActive;    // Flag to check if the popup is open
    static int popupX, popupY;  // Popup position

    void initialize();
    
    static void displayCallback();
    static void keyCallback(unsigned char key, int x, int y);
    static void mouseCallback(int button, int state, int x, int y);

    static Rectangle rec01;
    static Rectangle rec02;

    static Hexagon hex01;
    static Hexagon hex02;

    static Circle circle01;
    static Circle circle02;

    static Ellipse ellipse01;
    static Ellipse ellipse02;
    
    static int chooseShape;
public:
    Window(std::string title);
    Window(std::string title, int width, int height);
    ~Window();

    void run();
};

#endif // WINDOW_HPP
