#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>

class Window {
private:
    std::string title;
    int width;
    int height;
    bool fullscreen;

    void initialize();
    
    static void displayCallback();
    static void keyCallback(unsigned char key, int x, int y);

public:
    Window(std::string title);
    Window(std::string title, int width, int height);
    ~Window();

    void run();
};

#endif // WINDOW_HPP
