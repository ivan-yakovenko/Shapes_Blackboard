#include "Rectangle.h"

Rectangle::Rectangle(int x, int y, int width, int height)
        : x(x), y(y), width(width), height(height) {}

void Rectangle::draw(Board &board) {
    HorizontalLine topLine(x, y, width);
    VerticalLine leftLine(x, y, height);
    VerticalLine rightLine(x + width - 1, y, height);
    HorizontalLine bottomLine(x, y + height - 1, width);
    
    topLine.draw(board);
    leftLine.draw(board);
    rightLine.draw(board);
    bottomLine.draw(board);
}