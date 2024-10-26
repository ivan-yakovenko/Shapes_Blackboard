#include "VerticalLine.h"

VerticalLine::VerticalLine(int x, int y, bool isFilled, std::string &color, bool colorFramed, std::string &color2,
                           int length) : Shape(x, y, isFilled, color, colorFramed, color2),
                                         length(length) {}

void VerticalLine::draw(Board &board, bool isFilled, std::string color, bool colorFramed, std::string color2) {
    if (x >= 0 && x < BoardWidth && y >= 0 && y < BoardHeight) {
        if (colorFramed && !color2.empty()) {
            char c = color2[0];
            c = static_cast<char>(std::toupper(c));
            for (int i = y; i < y + length && i < BoardHeight; i++) {
                board.setGrid(i, x, c);
            }
        } else if (isFilled && !color.empty()) {
            char c = color[0];
            c = static_cast<char>(std::toupper(c));
            for (int i = y; i < y + length && i < BoardHeight; i++) {
                board.setGrid(i, x, c);
            }
        }
        if (color.empty() && color2.empty()) {
            for (int i = y; i < y + length && i < BoardHeight; i++) {
                board.setGrid(i, x, '*');
            }
        }
    } else {
        return;
    }
}

void VerticalLine::printInfo() {
    std::cout << "verticalLine " << x << " " << y << " " << isFilled << " " << color << " " << colorFramed << " " << color2
              << " " << length
              << std::endl;
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
    fout << isFilled << " " << color << " " << colorFramed << " " << color2 << "verticalLine" << " " << x << " " << y << " " <<
         " " << length
         << std::endl;
}