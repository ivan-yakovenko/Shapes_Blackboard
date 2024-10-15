#include "RightTriangle.h"

RightTriangle::RightTriangle(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {}

void RightTriangle::draw(Board &board) {
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






//for (int i = 0; i < height / 2 && y - i >= 0; i++) {
//board.setGrid(y - i, x + i);
//}
//for (int i = 0; i < (height / 2) + 1 && y - i >= 0 && x + width - i >= 0; i++) {
//board.setGrid(y - i, x + width - i);
//}