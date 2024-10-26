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
    void saveInfo(std::ofstream &fout) override;
    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;
    [[nodiscard]] int getLength() const;
};
