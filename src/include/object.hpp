#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <array>

class Object {
protected:
    std::array<int, 3> color;
    void PutPixel(int x, int y);
    std::array<int, 3> GetPixel(int x, int y);
public:
    Object();
    Object(int r, int g, int b);
    Object(std::array<int, 3> color);
    virtual void Draw();
};

#endif // OBJECT_HPP
