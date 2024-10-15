#pragma once
#include <iostream>
#include <stack>
#include "../Shape/Shape.h"
#include <sstream>
#include "../Rectangle/Rectangle.h"
#include "../Triangle/Triangle.h"
#include "../VerticalLine/VerticalLine.h"
#include "../HorizontalLine/HorizontalLine.h"
#include "../Circle/Circle.h"
#include "fstream"

const int BoardWidth = 80;
const int BoardHeight = 21;

class Board {
private:
    std::vector<std::vector<char>> grid;
    std::vector<std::pair<long, std::unique_ptr<Shape>>> shapes;
public:
    Board();
    void draw();
    void setGrid(int x, int y);
    void list();
    void showShapes();
    void add(std::string& shapeParameters);
    void undo();
    void clear();
    void save(std::string& filepath);
    void load(std::string& filepath);
};
