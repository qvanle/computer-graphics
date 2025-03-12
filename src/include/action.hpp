#ifndef ACTION_HPP
#define ACTION_HPP

#include "window.hpp"

class Action {
private: 
    std::shared_ptr<Window> instance;
    struct {
        int x;
        int y;
        std::array<int, 3> color;
        bool status = false;
    } fillation;
public: 
    Action(std::shared_ptr<Window> ins);
    void putPixel(int x, int y, std::array<int, 3> color);
    std::array<int, 3> getPixel(int x, int y);
    void orderfill(int x, int y, std::array<int, 3> color);
    void fill(int x, int y, std::array<int, 3> color, std::array<int, 3> lastColor = {-1, -1, -1});
    void fill();
    void boundaryFill(int x, int y, std::array<int, 3> color, std::array<int, 3> boundaryColor);
    bool isColorSimilar(std::array<int, 3> color1, std::array<int, 3> color2, int tolerance = 6);
};

#endif 
