#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Object.hpp"
#include <array>
#include <vector>

class Circle : public Object {
private:
    std::array<int, 2> center;
    int radius;
    int num_segments; // Number of line segments used to approximate the circle
    bool needBoundary;
public:
    Circle(std::array<int, 2> center, int radius, std::array<unsigned char, 3> boundary_color, bool needBoundary, int num_segments = 100);
    void draw();
};

#endif // CIRCLE_HPP
