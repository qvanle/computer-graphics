#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Object.hpp"
#include <array>

class Rectangle : public Object {
private:
    std::array<int, 2> top_left;
    std::array<int, 2> bottom_right;

public:
    Rectangle(std::array<int, 2> top_left, std::array<int, 2> bottom_right, std::array<unsigned char, 3> boundary_color);
    void draw();
};

#endif // RECTANGLE_HPP
