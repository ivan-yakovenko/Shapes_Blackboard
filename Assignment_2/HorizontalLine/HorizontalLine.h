#pragma once
#include "../Shape/Shape.h"
#include "../Board/Board.h"

class HorizontalLine : public Shape {
private:
    int x, y, length;
public:
    HorizontalLine(int x, int y, int length);
    ~HorizontalLine() override = default;
    void draw(Board &board) override;
    void printInfo() override;
    int getX() const;
    int getY() const;
    int getLength() const;
};
