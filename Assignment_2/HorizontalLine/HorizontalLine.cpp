#include "HorizontalLine.h"

HorizontalLine::HorizontalLine(int x, int y, int length) : x(x), y(y), length(length) {}

void HorizontalLine::draw(Board &board) {
    if (x >= 0 && x < BoardWidth && y >= 0 && y < BoardHeight) {
        for (int i = x; i < x + length && i < BoardWidth; i++) {
            board.setGrid(y, i);
        }
    } else {
        return;
    }
}

void HorizontalLine::printInfo() {
    std::cout << x << " " << y << " " << length << std::endl;
}

int HorizontalLine::getX() const {
    return this->x;
}

int HorizontalLine::getY() const {
    return this->y;
}

int HorizontalLine::getLength() const {
    return this->length;
}