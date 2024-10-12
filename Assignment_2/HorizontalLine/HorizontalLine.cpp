#include "HorizontalLine.h"

HorizontalLine::HorizontalLine(int x, int y, int length) : x(x), y(y), length(length) {}

void HorizontalLine::draw(Board &board) {
    for(int i = x; i < x + length && i < BoardWidth; i++) {
        board.setGrid(y, i);
    }
}