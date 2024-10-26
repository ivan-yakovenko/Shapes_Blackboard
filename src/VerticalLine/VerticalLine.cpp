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

int VerticalLine::getX() const {
    return this->x;
}

int VerticalLine::getY() const {
    return this->y;
}

int VerticalLine::getLength() const {
    return this->length;
}

void VerticalLine::saveInfo(std::ofstream &fout) {
    fout << "verticalLine" << " " << x << " " << y << " " << length << std::endl;
}