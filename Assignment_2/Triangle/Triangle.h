#pragma once

#include "../Shape/Shape.h"
#include "../HorizontalLine/HorizontalLine.h"
#include "../VerticalLine/VerticalLine.h"

class RightTriangle : Shape {
private:
    int x, y, width, height;
public:
    RightTriangle(int x, int y, int width, int height);

    ~RightTriangle() = default;

    void draw(Board &board) override;
};


