#pragma once
#include "../Shape/Shape.h"
#include "../Board/Board.h"

class VerticalLine : public Shape {
private:
    int length;
public:
    VerticalLine(int x, int y, bool isFilled, std::string& color, bool colorFramed, std::string& color2, int length);
    ~VerticalLine() override = default;
    void draw(Board &board, bool isFilled, std::string color, bool colorFramed, std::string color2) override;
    void printInfo() override;
    void saveInfo(std::ofstream &fout) override;
    [[nodiscard]] int getLength() const;

    void setLength(int lengthSetter);
};

