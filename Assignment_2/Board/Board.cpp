#include "Board.h"

Board::Board() :  grid(BoardHeight, std::vector<char>(BoardWidth, ' ')) {}

void Board::draw() {
    std::cout << std::string(BoardWidth + 2, '-') << '\n';

    for(auto& row : grid) {
        std::cout << '|';
        for(char element : row) {
            std::cout << element;
        }
        std::cout << '|' << '\n';
    }
    std::cout << std::string(BoardWidth + 2, '-') << '\n';
}

void Board::setGrid(int x, int y) {
        grid[x][y] = '*';
}

