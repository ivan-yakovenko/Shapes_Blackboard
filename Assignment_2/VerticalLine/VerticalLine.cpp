#include "VerticalLine.h"

VerticalLine::VerticalLine(int x, int y, int length) : x(x), y(y), length(length) {}

void VerticalLine::draw(Board &board) {
    if (x >= 0 && x < BoardWidth && y >= 0 && y < BoardHeight) {
        for (int i = y; i < y + length && i < BoardHeight; i++) {
            board.setGrid(i, x);
        }
    } else {
        return;
    }
}

void VerticalLine::printInfo() {
    std::cout << x << " " << y << " " << length << std::endl;
}




