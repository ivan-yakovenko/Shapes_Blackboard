#include "Rectangle.h"

Rectangle::Rectangle(int x, int y, int width, int height)
        : x(x), y(y), width(width), height(height) {}

void Rectangle::draw(Board &board) {
    if (x >= 0 && x < BoardWidth && y >= 0 && y < BoardHeight) {
        HorizontalLine topLine(x, y, width);
        VerticalLine leftLine(x, y, height);
        VerticalLine rightLine(x + width - 1, y, height);
        HorizontalLine bottomLine(x, y + height - 1, width);

        topLine.draw(board);
        leftLine.draw(board);
        rightLine.draw(board);
        bottomLine.draw(board);
    }
    else {
        return;
    }
}

void Rectangle::printInfo() {
    std::cout << x << " " << y << " " << width << " " << height << std::endl;
}

int Rectangle::getX() const {
    return this->x;
}

int Rectangle::getY() const {
    return this->y;
}

int Rectangle::getWidth() const {
    return this->width;
}

int Rectangle::getHeight() const {
    return this->height;
}