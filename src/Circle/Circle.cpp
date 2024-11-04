#include "Circle.h"

Circle::Circle(int cx, int cy, bool isFilled, std::string& color, bool colorFramed, std::string& color2, int radius) : Shape(cx, cy, isFilled, color, colorFramed, color2), radius(radius) {}

void Circle::draw(Board &board, bool isFilled, std::string color, bool colorFramed, std::string color2) {
    if (x >= 0 && x < BoardWidth && y >= 0 && y < BoardHeight) {
        if(isFilled && !color.empty() && colorFramed && !color2.empty()) {
            char c = static_cast<char>(std::toupper(color[0]));
            char c2 = static_cast<char>(std::toupper(color2[0]));

            int px = 0;
            int py = -radius;
            int p = -radius;

            while (px < -py) {
                if (p > 0) {
                    py += 1;
                    p += 2 * px + 1 + 2 * py;
                } else {
                    p += 2 * px + 1;
                }
                board.setGrid(y + py, x + px, c2);
                board.setGrid(y + py, x - px, c2);
                board.setGrid(y - py, x + px, c2);
                board.setGrid(y - py, x - px, c2);
                board.setGrid(y + px, x + py, c2);
                board.setGrid(y - px, x + py, c2);
                board.setGrid(y + px, x - py, c2);
                board.setGrid(y - px, x - py, c2);
                px += 1;
            }

            for (int i = -radius; i <= radius; i++) {
                for (int j = -radius; j <= radius; j++) {
                    if (i * i + j * j <= radius * radius) {
                        board.setGrid(y + i, x + j, c);
                    }
                }
            }
        }
        if(isFilled && !color.empty()) {
            char c = static_cast<char>(std::toupper(color[0]));

            int px = 0;
            int py = -radius;
            int p = -radius;

            while (px < -py) {
                if (p > 0) {
                    py += 1;
                    p += 2 * px + 1 + 2 * py;
                } else {
                    p += 2 * px + 1;
                }
                board.setGrid(y + py, x + px, c);
                board.setGrid(y + py, x - px, c);
                board.setGrid(y - py, x + px, c);
                board.setGrid(y - py, x - px, c);
                board.setGrid(y + px, x + py, c);
                board.setGrid(y - px, x + py, c);
                board.setGrid(y + px, x - py, c);
                board.setGrid(y - px, x - py, c);
                px += 1;
            }

            for (int i = -radius; i <= radius; i++) {
                for (int j = -radius; j <= radius; j++) {
                    if (i * i + j * j <= radius * radius) {
                        board.setGrid(y + i, x + j, c);
                    }
                }
            }

        }
        if(colorFramed && !color2.empty()) {
            char c = static_cast<char>(std::toupper(color2[0]));

            int px = 0;
            int py = -radius;
            int p = -radius;

            while (px < -py) {
                if (p > 0) {
                    py += 1;
                    p += 2 * px + 1 + 2 * py;
                } else {
                    p += 2 * px + 1;
                }
                board.setGrid(y + py, x + px, c);
                board.setGrid(y + py, x - px, c);
                board.setGrid(y - py, x + px, c);
                board.setGrid(y - py, x - px, c);
                board.setGrid(y + px, x + py, c);
                board.setGrid(y - px, x + py, c);
                board.setGrid(y + px, x - py, c);
                board.setGrid(y - px, x - py, c);
                px += 1;
            }
        }
        if(color.empty() && color2.empty()) {
            int px = 0;
            int py = -radius;
            int p = -radius;

            while (px < -py) {
                if (p > 0) {
                    py += 1;
                    p += 2 * px + 1 + 2 * py;
                } else {
                    p += 2 * px + 1;
                }
                board.setGrid(y + py, x + px, '*');
                board.setGrid(y + py, x - px, '*');
                board.setGrid(y - py, x + px, '*');
                board.setGrid(y - py, x - px, '*');
                board.setGrid(y + px, x + py, '*');
                board.setGrid(y - px, x + py, '*');
                board.setGrid(y + px, x - py, '*');
                board.setGrid(y - px, x - py, '*');
                px += 1;
            }
        }
    } else {
        return;
    }
}

void Circle::printInfo() {
    std::cout << "circle " << x << " " << y << " " << isFilled << " " << color << " " << colorFramed << " " << color2 << " " << radius << std::endl;
}

int Circle::getRadius() const {
    return this->radius;
}

void Circle::saveInfo(std::ofstream &fout) {
    fout << isFilled << " " << color << " " << colorFramed << " " <<  color2 << " " << "circle" << " " << x << " " << y << " " << radius << std::endl;
}

void Circle::setRadius(int radiusSetter) {
    this->radius = radiusSetter;
}