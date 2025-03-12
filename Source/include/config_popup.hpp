
#ifndef CONFIG_POPUP_HPP
#define CONFIG_POPUP_HPP

#include <vector>
#include <string>
#include <iostream>

class ConfigPopup {
private:
    std::vector<std::string> shapes = {"Circle", "Ellipse", "Rectangle", "Polygon"};
    std::vector<std::string> colors = {"Black", "Red", "Green", "Blue"};
    int selectedShape = 0;
    int selectedColor = 0;
    int width, height;
    int buttonX, buttonY, buttonWidth, buttonHeight;

public:
    ConfigPopup(int width, int height);
    void display();
    int mouseClick(int button, int state, int x, int y);
    void drawButton();
    int getShape();
    int getColor();
};

#endif
