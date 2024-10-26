#include "Rectangle.h"

Rectangle::Rectangle(int x, int y, bool isFilled, std::string &color, bool colorFramed, std::string &color2, int width,
                     int height)
        : Shape(x, y, isFilled, color, colorFramed, color2), width(width), height(height) {}

void Rectangle::draw(Board &board, bool isFilled, std::string color, bool colorFramed, std::string color2) {
    if (x >= 0 && x < BoardWidth && y >= 0 && y < BoardHeight) {

        if (isFilled && !color.empty() && colorFramed && !color2.empty()) {
            char c = color[0];
            c = static_cast<char>(std::toupper(c));

            HorizontalLine topLine(x, y, isFilled, color, colorFramed, color2, width);
            VerticalLine leftLine(x, y, isFilled, color, colorFramed, color2, height);
            VerticalLine rightLine(x + width - 1, y, isFilled, color, colorFramed, color2, height);
            HorizontalLine bottomLine(x, y + height - 1, isFilled, color, colorFramed, color2, width);

            topLine.draw(board, isFilled, color, colorFramed, color2);
            leftLine.draw(board, isFilled, color, colorFramed, color2);
            rightLine.draw(board, isFilled, color, colorFramed, color2);
            bottomLine.draw(board, isFilled, color, colorFramed, color2);

            for (int i = y + 1; i < y + height - 1; i++) {
                for (int j = x + 1; j < x + width - 1; j++) {
                    board.setGrid(i, j, c);
                }
            }
        }


        if (colorFramed && !color2.empty()) {
            HorizontalLine topLine(x, y, isFilled, color, colorFramed, color2, width);
            VerticalLine leftLine(x, y, isFilled, color, colorFramed, color2, height);
            VerticalLine rightLine(x + width - 1, y, isFilled, color, colorFramed, color2, height);
            HorizontalLine bottomLine(x, y + height - 1, isFilled, color, colorFramed, color2, width);

            topLine.draw(board, isFilled, color, colorFramed, color2);
            leftLine.draw(board, isFilled, color, colorFramed, color2);
            rightLine.draw(board, isFilled, color, colorFramed, color2);
            bottomLine.draw(board, isFilled, color, colorFramed, color2);
        }

        if (isFilled && !color.empty()) {
            char c = static_cast<char>(std::toupper(color[0]));

            HorizontalLine topLine(x, y, isFilled, color, colorFramed, color, width);
            VerticalLine leftLine(x, y, isFilled, color, colorFramed, color, height);
            VerticalLine rightLine(x + width - 1, y, isFilled, color, colorFramed, color, height);
            HorizontalLine bottomLine(x, y + height - 1, isFilled, color, colorFramed, color, width);

            topLine.draw(board, isFilled, color, colorFramed, color2);
            leftLine.draw(board, isFilled, color, colorFramed, color2);
            rightLine.draw(board, isFilled, color, colorFramed, color2);
            bottomLine.draw(board, isFilled, color, colorFramed, color2);

            for (int i = y + 1; i < y + height - 1; i++) {
                for (int j = x + 1; j < x + width - 1; j++) {
                    board.setGrid(i, j, c);
                }
            }
        }
        if(color.empty() && color2.empty()) {
            HorizontalLine topLine(x, y, isFilled, color, colorFramed, color2, width);
            VerticalLine leftLine(x, y, isFilled, color, colorFramed, color2, height);
            VerticalLine rightLine(x + width - 1, y, isFilled, color, colorFramed, color2, height);
            HorizontalLine bottomLine(x, y + height - 1, isFilled, color, colorFramed, color2, width);

            topLine.draw(board, isFilled, color, colorFramed, color2);
            leftLine.draw(board, isFilled, color, colorFramed, color2);
            rightLine.draw(board, isFilled, color, colorFramed, color2);
            bottomLine.draw(board, isFilled, color, colorFramed, color2);
        }

    } else {
        return;
    }
}

void Rectangle::printInfo() {
    std::cout << "rectangle " << x << " " << y << " "  << isFilled << " " << color << " " << colorFramed << " " << color2 << " " << width << " " << height << std::endl;
}

int Rectangle::getWidth() const {
    return this->width;
}

int Rectangle::getHeight() const {
    return this->height;
}

void Rectangle::saveInfo(std::ofstream &fout) {
    fout << isFilled << " " << color << " " << colorFramed << " " << color2 << " " << "rectangle" << " " << x << " " << y << " " << width << " " << height << std::endl;
}