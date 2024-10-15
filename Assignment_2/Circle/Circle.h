#pragma once
#include "../Shape/Shape.h"
#include "../Board/Board.h"

class Circle : public Shape {
private:
    int cx, cy, radius;
public:
    Circle(int cx, int cy, int radius);
    ~Circle() override = default;
    void draw(Board &board) override;
    void printInfo() override;
    int getCX() const;
    int getCY() const;
    int getRadius() const;
};

