
#ifndef HEXAGON_HPP
#define HEXAGON_HPP

#include "Object.hpp"
#include <array>
#include <vector>

class Hexagon : public Object {
private:
    std::array<int, 2> center;
    int radius;
    std::vector<std::array<int, 2>> vertices; // Stores the 6 vertices of the hexagon

    void calculateVertices(); // Helper function to compute vertices
    bool needBoundary;
public:
    Hexagon(std::array<int, 2> center, int radius, std::array<unsigned char, 3> boundary_color, bool needboundary);
    void draw();
};

#endif // HEXAGON_HPP
