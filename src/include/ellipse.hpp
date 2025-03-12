#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP

#include "Object.hpp"
#include <array>
#include <vector>

class Ellipse : public Object {
private:
    std::array<int, 2> center;
    int radius_x;
    int radius_y;
    int num_segments; // Number of segments used to approximate the ellipse
    bool needBoundary;
    
public:
    Ellipse(std::array<int, 2> center, int radius_x, int radius_y, std::array<unsigned char, 3> boundary_color, bool needboud, int num_segments = 100);
    void draw();
};

#endif // ELLIPSE_HPP
