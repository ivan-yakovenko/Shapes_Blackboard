#pragma once

#include "../Shape/Shape.h"
#include "../HorizontalLine/HorizontalLine.h"
#include "../Board/Board.h"

class Triangle : public Shape {
private:
    int width, height;
public:
    Triangle(int x, int y, bool isFilled, std::string& color, bool colorFramed, std::string& color2, int width, int height);

    ~Triangle() override = default;

    void draw(Board &board, bool isFilled, std::string color, bool colorFramed, std::string color2) override;

    void printInfo() override;

    void saveInfo(std::ofstream &fout) override;
    [[nodiscard]] int getWidth() const;
    [[nodiscard]] int getHeight() const;
};


