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
    if (x >= 0 && x < BoardHeight && y >= 0 && y < BoardWidth) {
        grid[x][y] = '*';
    }
}

void Board::list() {
    for (const auto &shape: shapes) {
        std::cout << shape.first << " ";
        shape.second->printInfo();
    }
    if (shapes.empty()) {
        std::cout << "No shapes" << std::endl;
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
    std::istringstream parameters(shapeParameters);
    std::string shape;
    int x, y, p1, p2;
    if (parameters >> shape >> x >> y >> p1) {
        if (shape != "horizontalLine" && shape != "verticalLine" && shape != "triangle" && shape != "rectangle" &&
            shape != "circle") {
            std::cerr << "No such shape" << std::endl;
            return;
        }
        if (x < 0 || x >= BoardWidth || y < 0 || y >= BoardHeight) {
            std::cerr << "Inappropriate coordinates" << std::endl;
            return;
        }
        if (parameters >> p2) {
            if (shape == "rectangle") {
                for (const auto &existingShape: shapes) {
                    if (auto *eShape = dynamic_cast<Rectangle *>(existingShape.second.get())) {
                        if (eShape->getWidth() == p1 && eShape->getHeight() == p2 && eShape->getX() == x &&
                            eShape->getY() == y) {
                            std::cerr << "Such shape at such position exists" << std::endl;
                            return;
                        }
                    }
                }
                if (p1 >= BoardWidth || p2 >= BoardHeight) {
                    std::cerr << "Inappropriate width/length" << std::endl;
                    return;
                }
                long id = Shape::generateID();
                std::unique_ptr<Shape> newShape = std::make_unique<Rectangle>(x, y, p1, p2);
                shapes.emplace_back(id, std::move(newShape));
                shapes.back().second->draw(*this);
            }
            if (shape == "triangle") {
                if (p1 != p2 || p1 % 2 != 0 || p2 % 2 != 0) {
                    std::cerr << "Wrong parameters" << std::endl;
                    return;
                }
                for (const auto &existingShape: shapes) {
                    if (auto *eShape = dynamic_cast<Triangle *>(existingShape.second.get())) {
                        if (eShape->getWidth() == p1 && eShape->getHeight() == p2 && eShape->getX() == x &&
                            eShape->getY() == y) {
                            std::cerr << "Such shape at such position exists" << std::endl;
                            return;
                        }
                    }
                }
                if (p1 >= BoardWidth || p2 >= BoardHeight) {
                    std::cerr << "Inappropriate width/height" << std::endl;
                    return;
                }
                long id = Shape::generateID();
                std::unique_ptr<Shape> newShape = std::make_unique<Triangle>(x, y, p1, p2);
                shapes.emplace_back(id, std::move(newShape));
                shapes.back().second->draw(*this);
            }
        } else {
            if (shape == "horizontalLine") {
                for (const auto &existingShape: shapes) {
                    if (auto *eShape = dynamic_cast<HorizontalLine*>(existingShape.second.get())) {
                        if (eShape->getLength() == p1 && eShape->getX() == x && eShape->getY() == y) {
                            std::cerr << "Such shape at such position exists" << std::endl;
                            return;
                        }
                    }
                }
                if (p1 >= BoardWidth) {
                    std::cerr << "Inappropriate width" << std::endl;
                    return;
                }
                long id = Shape::generateID();
                std::unique_ptr<Shape> newShape = std::make_unique<HorizontalLine>(x, y, p1);
                shapes.emplace_back(id, std::move(newShape));
                shapes.back().second->draw(*this);
            }
            if (shape == "verticalLine") {
                for (const auto &existingShape: shapes) {
                    if (auto *eShape = dynamic_cast<VerticalLine *>(existingShape.second.get())) {
                        if (eShape->getLength() == p1 && eShape->getX() == x && eShape->getY() == y) {
                            std::cerr << "Such shape at such position exists" << std::endl;
                            return;

                        }
                    }
                }
                if (p1 >= BoardHeight) {
                    std::cerr << "Inappropriate height" << std::endl;
                    return;
                }
                long id = Shape::generateID();
                std::unique_ptr<Shape> newShape = std::make_unique<VerticalLine>(x, y, p1);
                shapes.emplace_back(id, std::move(newShape));
                shapes.back().second->draw(*this);
            }
            if (shape == "circle") {
                for (const auto &existingShape: shapes) {
                    if (auto *eShape = dynamic_cast<Circle *>(existingShape.second.get())) {
                        if (eShape->getRadius() == p1 && eShape->getCX() == x && eShape->getCY() == y) {
                            std::cerr << "Such shape at such position exists" << std::endl;
                            return;
                        }
                    }
                }
                if (x + p1 >= BoardWidth && y + p1 >= BoardHeight) {
                    std::cerr << "Inappropriate radius" << std::endl;
                    return;
                }
                long id = Shape::generateID();
                std::unique_ptr<Shape> newShape = std::make_unique<Circle>(x, y, p1);
                shapes.emplace_back(id, std::move(newShape));
                shapes.back().second->draw(*this);
            }
        }
    } else {
        return;
    }
}

void Board::undo() {
    shapes.pop_back();

    grid.assign(BoardHeight, std::vector<char>(BoardWidth, ' '));

    for (const auto &shape: shapes) {
        shape.second->draw(*this);
    }
}

void Board::clear() {
    shapes.clear();
    grid.assign(BoardHeight, std::vector<char>(BoardWidth, ' '));
}

void Board::save(std::string &filepath) {
    std::ofstream fout(filepath);

    if (!fout) {
        throw std::runtime_error("Can't open the file for saving " + filepath);
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

    fout.close();
}

void Board::load(std::string &filepath) {
    std::ifstream fin(filepath);

    std::string line;
    std::getline(fin, line);

    for (int i = 0; i < BoardHeight; i++) {
        std::getline(fin, line);
        for (int j = 0; j < BoardWidth; j++) {
            grid[i][j] = line[j + 1];
        }
    }

    std::getline(fin, line);

    if (!fin) {
        throw std::runtime_error("Can't open the file for loading" + filepath);
    }

    fin.close();
}
