#include "square.hpp"

Square::Square(std::array<int, 2> topLeft, int sideLength, std::array<int, 3> color)
    : Rectangle(topLeft, {topLeft[0] + sideLength, topLeft[1] - sideLength}, color) {}
