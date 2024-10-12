#include "VerticalLine.h"

VerticalLine::VerticalLine(int x, int y, int length) : x(x), y(y), length(length) {}

void VerticalLine::draw(Board &board) {
    for(int i = y; i < y + length && i < BoardHeight; i++) {
        board.setGrid(i, x);
    }
}
