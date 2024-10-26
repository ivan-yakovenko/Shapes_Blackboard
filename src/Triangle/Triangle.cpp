#include "Triangle.h"

Triangle::Triangle(int x, int y, bool isFilled, std::string& color, bool colorFramed, std::string& color2, int width, int height) : Shape(x, y, isFilled, color, colorFramed, color2), width(width), height(height) {}

void Triangle::draw(Board &board, bool isFilled, std::string color, bool colorFramed, std::string color2) {
    if (x >= 0 && x < BoardWidth && y >= 0 && y < BoardHeight) {
        if(isFilled && !color.empty() && colorFramed && !color2.empty()) {
            char c = static_cast<char>(std::toupper(color[0]));

            HorizontalLine base(x, y, isFilled, color, colorFramed, color2, width);

            base.draw(board, isFilled, color, colorFramed, color2);

            for (int i = 0; i < height / 2; i++) {
                board.setGrid(y - i, x + i, c);
                for (int j = x + i + 1; j < x + width - i; j++) {
                    board.setGrid(y - i, j, c);
                }
            }

            for (int i = 0; i < (height / 2) + 1; i++) {
                board.setGrid(y - i, x + width - i, c);
            }
        }
        if (isFilled && !color.empty()) {
            char c = static_cast<char>(std::toupper(color[0]));

            HorizontalLine base(x, y, isFilled, color, colorFramed, color, width);

            base.draw(board, isFilled, color, colorFramed, color2);

            for (int i = 0; i < height / 2; i++) {
                board.setGrid(y - i, x + i, c);
                for (int j = x + i + 1; j < x + width - i; j++) {
                    board.setGrid(y - i, j, c);
                }
            }

            for (int i = 0; i < (height / 2) + 1; i++) {
                board.setGrid(y - i, x + width - i, c);
            }
        }
        if(colorFramed && !color2.empty()) {
            char c = static_cast<char>(std::toupper(color2[0]));
            HorizontalLine base(x, y, isFilled, color, colorFramed, color2, width);

            base.draw(board, isFilled, color, colorFramed, color2);

            for (int i = 0; i < height / 2; i++) {
                board.setGrid(y - i, x + i, c);
            }

            for (int i = 0; i < (height / 2) + 1; i++) {
                board.setGrid(y - i, x + width - i, c);
            }

        }
        if(color.empty() && color2.empty()) {
            HorizontalLine base(x, y, isFilled, color, colorFramed, color2, width);

            base.draw(board, isFilled, color, colorFramed, color2);

            for (int i = 0; i < height / 2; i++) {
                board.setGrid(y - i, x + i, '*');
            }

            for (int i = 0; i < (height / 2) + 1; i++) {
                board.setGrid(y - i, x + width - i, '*');
            }

        }
    } else {
        return;
    }
}

void Triangle::printInfo() {
    std::cout << "triangle " << x << " " << y << " "  << isFilled << " " << color << " " << colorFramed << " " << color2 << " " << width << " " << height << std::endl;
}

int Triangle::getX() const {
    return this->x;
}

int Triangle::getY() const {
    return this->y;
}

int Triangle::getWidth() const {
    return this->width;
}

int Triangle::getHeight() const {
    return this->height;
}

void Triangle::saveInfo(std::ofstream &fout) {
    fout << isFilled << " " << color << " " << colorFramed << " " << color2 << " " << "triangle" << " " << x << " " << y << " " << width << " " << height << std::endl;
}