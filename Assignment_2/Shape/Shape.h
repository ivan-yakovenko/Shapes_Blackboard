#pragma once
#include "../Board/Board.h"

class Shape {
public:
    virtual void draw(Board& board) = 0;
    ~Shape() = default;
};