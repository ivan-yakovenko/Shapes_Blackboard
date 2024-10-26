#pragma once
#include "../Shape/Shape.h"
#include "../Board/Board.h"

class Circle : public Shape {
private:
    int radius;
public:
    Circle(int x, int y, bool isFilled, std::string& color, bool colorFramed, std::string& color2, int radius);
    ~Circle() override = default;
    void draw(Board &board, bool isFilled, std::string color, bool colorFramed, std::string color2) override;
    void printInfo() override;
    void saveInfo(std::ofstream &fout) override;

    [[nodiscard]] int getRadius() const;
};

