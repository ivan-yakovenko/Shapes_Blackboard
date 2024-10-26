#pragma once
#include "../Shape/Shape.h"
#include "../Board/Board.h"

class VerticalLine : public Shape {
private:
    int x, y, length;
public:
    VerticalLine(int x, int y, int length);
    ~VerticalLine() override = default;
    void draw(Board &board) override;
    void printInfo() override;
    void saveInfo(std::ofstream &fout) override;
    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;
    [[nodiscard]] int getLength() const;
};

