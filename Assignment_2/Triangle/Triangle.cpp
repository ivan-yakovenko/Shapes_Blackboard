#include "Triangle.h"

Triangle::Triangle(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {}

void Triangle::draw(Board &board) {
    if (x >= 0 && x < BoardWidth && y >= 0 && y < BoardHeight) {
        HorizontalLine base(x, y, width);

        base.draw(board);

        for (int i = 0; i < height / 2; i++) {
            board.setGrid(y - i, x + i);
        }

        for (int i = 0; i < (height / 2) + 1; i++) {
            board.setGrid(y - i, x + width - i);
        }
    } else {
        return;
    }
}

void Triangle::printInfo() {
    std::cout << x << " " << y << " " << width << " " << height << std::endl;
}