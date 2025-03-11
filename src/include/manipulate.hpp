#ifndef MANIPULATE_HPP
#define MANIPULATE_HPP

#include <vector>
#include <string>
#include <memory>

class Manipulate {
private:
    int x, y; // Position of menu
    int width, height; // Size of menu
    std::vector<std::string> options;
    bool active;
    std::string name;
public:
    Manipulate(std::string name);
    Manipulate(std::string name, int x, int y);
    void move(int x, int y);
    void swi();
    void display();
    void display(int x, int y);
    void swiDisplay();
    void swiDisplay(int x, int y);
    bool isInside(int mx, int my);
    int getOptionIndex(int mx, int my);
    void deactivate();
    bool isActive() const;
};

// create a namespace name MANI 
namespace MANI{
    extern std::unique_ptr<Manipulate> menu;
    extern std::unique_ptr<Manipulate> line;
    extern std::unique_ptr<Manipulate> triangle;
    extern std::unique_ptr<Manipulate> quadrilateral;
    extern std::unique_ptr<Manipulate> oval;
    extern std::unique_ptr<Manipulate> polygon;
    extern std::unique_ptr<Manipulate> operation;
    extern std::unique_ptr<Manipulate> other;
}

#endif // MANIPULATE_HPP
