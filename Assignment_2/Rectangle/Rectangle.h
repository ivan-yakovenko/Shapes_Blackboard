#pragma once
#include "../Shape/Shape.h"
#include "../HorizontalLine/HorizontalLine.h"
#include "../VerticalLine/VerticalLine.h"

class Rectangle : Shape {
private:
    int x, y, width, height;
public:
    Rectangle(int x, int y, int width, int height);
    ~Rectangle() = default;
    void draw(Board &board) override;
};

