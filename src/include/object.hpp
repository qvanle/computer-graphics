#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <array> 

using uc = unsigned char;

class Object {
protected:
    std::array<unsigned char, 3> boundary_color;
public: 
    Object();
    Object(std::array<unsigned char, 3> boundary_color);
    ~Object();
    void setColor(std::array<unsigned char, 3> color);
    void putPixel(std::array<int, 2> pos, std::array<unsigned char, 3> color);
    std::array<unsigned char, 3> readPixel(std::array<int, 2> pos);
    void boundaryFill(std::array<int, 2> pos, std::array<unsigned char, 3> fill_color);
    void boundaryFillNoRecur(std::array<int, 2> pos, std::array<unsigned char, 3> fill_color);
    virtual void draw();
};

#endif // OBJECT_HPP
