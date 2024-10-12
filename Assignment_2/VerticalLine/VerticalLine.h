#pragma once
#include "../Shape/Shape.h"

class VerticalLine : Shape {
private:
    int x, y, length;
public:
    VerticalLine(int x, int y, int length);
    ~VerticalLine() = default;
    void draw(Board &board) override;
};

