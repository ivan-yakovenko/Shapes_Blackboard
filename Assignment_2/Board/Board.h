#pragma once
#include <iostream>

const int BoardHeight = 20;
const int BoardWidth = 80;

class Board {
private:
    std::vector<std::vector<char>> grid;
public:
    Board();
    void draw();
    void setGrid(int x, int y);
};
