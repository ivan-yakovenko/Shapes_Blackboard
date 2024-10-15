#pragma once
#include "../Shape/Shape.h"
#include "../HorizontalLine/HorizontalLine.h"
#include "../VerticalLine/VerticalLine.h"

class Rectangle : public Shape {
private:
    int x, y, width, height;
public:
    Rectangle(int x, int y, int width, int height);
    ~Rectangle() override = default;
    void draw(Board &board) override;
    void printInfo() override;
    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;
};

