#pragma once
#include "../Shape/Shape.h"

class HorizontalLine : Shape {
private:
    int x, y, length;
public:
    HorizontalLine(int x, int y, int length);
    ~HorizontalLine() = default;
    void draw(Board &board) override;
};
