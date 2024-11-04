#include "HorizontalLine.h"

HorizontalLine::HorizontalLine(int x, int y, bool isFilled, std::string &color, bool colorFramed, std::string &color2,
                               int length) : Shape(x, y, isFilled, color, colorFramed, color2), length(length) {}

void HorizontalLine::draw(Board &board, bool isFilled, std::string color, bool colorFramed, std::string color2) {
    if (x >= 0 && x < BoardWidth && y >= 0 && y < BoardHeight) {
        if (colorFramed && !color2.empty()) {
            char c = color2[0];
            c = static_cast<char>(std::toupper(c));
            for (int i = x; i < x + length && i < BoardWidth; i++) {
                board.setGrid(y, i, c);
            }
        } else if (isFilled && !color.empty()) {
            char c = color[0];
            c = static_cast<char>(std::toupper(c));
            for (int i = x; i < x + length && i < BoardWidth; i++) {
                board.setGrid(y, i, c);
            }
        }
        if (color.empty() && color2.empty()) {
            for (int i = x; i < x + length && i < BoardWidth; i++) {
                board.setGrid(y, i, '*');
            }
        }
    } else {
        return;
    }
}

void HorizontalLine::printInfo() {
    std::cout << "horizontalLine " << x << " " << y << " " << isFilled << " " << color << " " << colorFramed << color2
              << " " << length
              << std::endl;
}


int HorizontalLine::getLength() const {
    return this->length;
}

void HorizontalLine::saveInfo(std::ofstream &fout) {
    fout << isFilled << " " << color << " " << colorFramed << color2 << " " << "horizontalLine" << " " << x << " " << y << " "
         << length
         << std::endl;
}

void HorizontalLine::setLength(int lengthSetter) {
    this->length = lengthSetter;
}