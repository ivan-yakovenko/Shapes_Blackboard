#include "Board.h"

Board::Board() : grid(BoardHeight, std::vector<char>(BoardWidth, ' ')) {}

void Board::draw() {
    std::cout << std::string(BoardWidth + 2, '-') << '\n';

    for (auto &row: grid) {
        std::cout << '|';
        for (char element: row) {
            std::cout << element;
        }
        std::cout << '|' << '\n';
    }
    std::cout << std::string(BoardWidth + 2, '-') << '\n';
}

void Board::setGrid(int x, int y) {
    if(x >= 0 && x < BoardHeight && y >= 0 && y < BoardWidth) {
        grid[x][y] = '*';
    }
}

void Board::list() {
    for(const auto& shape:shapes) {
        std::cout << shape.first << " ";
        shape.second->printInfo();
    }
}

void Board::showShapes() {
    std::cout << "horizontal line " << "x " << "y " << "length" << std::endl;
    std::cout << "vertical line " << "x " << "y " << "length" << std::endl;
    std::cout << "rectangle " << "x " << "y " << "width " << "height" << std::endl;
    std::cout << "triangle " << "x " << "y " << "width " << "height" << std::endl;
    std::cout << "circle " << "x " << "y " << "radius" << std::endl;
}

void Board::add(std::string &shapeParameters) {
    std::istringstream parameters;
    std::string shape;
    int x, y, p1, p2;
    parameters >> shape >> x >> y >> p1;
    if(parameters >> p2) {
        if(shape == "rectangle") {
            long id = Shape::generateID();
            std::unique_ptr<Shape> newShape = std::make_unique<Rectangle>(x, y, p1, p2);
            shapes.emplace_back(id, std::move(newShape));
            newShape->draw(*this);
        }
        if(shape == "triangle") {
            long id = Shape::generateID();
            std::unique_ptr<Shape> newShape = std::make_unique<Triangle>(x, y, p1, p2);
            shapes.emplace_back(id,std::move(newShape));
            newShape->draw(*this);
        }
    }
    else {
        if(shape == "horizontalLine") {
            long id = Shape::generateID();
            std::unique_ptr<Shape> newShape = std::make_unique<HorizontalLine>(x, y, p1);
            shapes.emplace_back(id, std::move(newShape));
            newShape->draw(*this);
        }
        if(shape == "verticalLine") {
            long id = Shape::generateID();
            std::unique_ptr<Shape> newShape = std::make_unique<VerticalLine>(x, y, p1);
            shapes.emplace_back(id, std::move(newShape));
            newShape->draw(*this);
        }
        if(shape == "circle") {
            long id = Shape::generateID();
            std::unique_ptr<Shape> newShape = std::make_unique<Circle>(x, y, p1);
            shapes.emplace_back(id, std::move(newShape));
            newShape->draw(*this);
        }
    }
}

void Board::undo() {
    shapes.pop_back();

    grid.assign(BoardHeight, std::vector<char>(BoardWidth, ' '));

    for(const auto& shape : shapes) {
        shape.second->draw(*this);
    }
}

void Board::clear() {
    shapes.clear();
    grid.assign(BoardHeight, std::vector<char>(BoardWidth, ' '));
}

void Board::save(std::string &filepath) {
    std::ofstream fout(filepath);

    if(!fout) {
        throw std::runtime_error("Can't open the file for saving" + filepath);
    }

    fout << std::string(BoardWidth + 2, '-') << '\n';

    for (auto &row: grid) {
        fout << '|';
        for (char element: row) {
            fout << element;
        }
        fout << '|' << '\n';
    }

    fout << std::string(BoardWidth + 2, '-') << '\n';
}

void Board::load(std::string &filepath) {
    std::ifstream fin(filepath);

    if(!fin) {
        throw std::runtime_error("Can't open the file for loading" + filepath);
    }
}
