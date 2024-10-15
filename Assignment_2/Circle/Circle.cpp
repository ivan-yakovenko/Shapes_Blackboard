#include "Circle.h"

Circle::Circle(int cx, int cy, int radius) : cx(cx), cy(cy), radius(radius) {}

void Circle::draw(Board &board) {
    if (cx >= 0 && cx < BoardWidth && cy >= 0 && cy < BoardHeight) {
        int x = 0;
        int y = -radius;
        int p = -radius;

        while (x < -y) {
            if (p > 0) {
                y += 1;
                p += 2 * x + 1 + 2 * y;
            } else {
                p += 2 * x + 1;
            }
            board.setGrid(cy + y, cx + x);
            board.setGrid(cy + y, cx - x);
            board.setGrid(cy - y, cx + x);
            board.setGrid(cy - y, cx - x);
            board.setGrid(cy + x, cx + y);
            board.setGrid(cy - x, cx + y);
            board.setGrid(cy + x, cx - y);
            board.setGrid(cy - x, cx - y);
            x += 1;
        }
    } else {
        return;
    }
}

void Circle::printInfo() {
    std::cout << cx << " " << cy << " " << radius << std::endl;
}