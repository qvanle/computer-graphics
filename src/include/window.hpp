#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include <memory>

#include "manipulate.hpp"

class Action;

class Window {
private:
    friend class Action;
    std::string title;
    int width;
    int height;
    bool fullscreen;
    static std::shared_ptr<Action> action;
    void initialize();
    
    static void displayCallback();
    static void keyCallback(unsigned char key, int x, int y);
    static void mouseCallback(int button, int state, int x, int y);
public:
    Window(std::string title);
    Window(std::string title, int width, int height);
    ~Window();

    void run();
};

#endif // WINDOW_HPP
