#include "Board.h"

Board::Board() : grid(BoardHeight, std::vector<char>(BoardWidth, ' ')) {}

void Board::modeChecker(std::string &mode) {
    if (mode != "fill" && mode != "frame" && mode != "horizontalLine" && mode != "verticalLine" && mode != "triangle" &&
        mode != "rectangle" &&
        mode != "circle") {
        std::cerr << "Wrong mode" << std::endl;
        return;
    }
}

void Board::colorChecker(std::string &color) {
    if (color != "yellow" && color != "cyan" && color != "magenta" && color != "red" && color != "blue") {
        std::cerr << "No such color" << std::endl;
        return;
    }
}

void Board::draw() {
    std::cout << "\033[0m" << std::string(BoardWidth + 2, '-') << '\n';

    for (auto &row: grid) {
        std::cout << "\033[0m" << '|';
        for (char element: row) {
            switch (element) {
                case 'Y':
                    std::cout << yellow << element;
                    break;
                case 'B':
                    std::cout << blue << element;
                    break;
                case 'R':
                    std::cout << red << element;
                    break;
                case 'M':
                    std::cout << magenta << element;
                    break;
                case 'C':
                    std::cout << cyan << element;
                    break;
                default:
                    std::cout << reset << element;
                    break;
            }
        }
        std::cout << "\033[0m" << '|' << '\n';
    }
    std::cout << "\033[0m" << std::string(BoardWidth + 2, '-') << '\n';
}

void Board::setGrid(int x, int y, char c) {
    if (x >= 0 && x < BoardHeight && y >= 0 && y < BoardWidth) {
        grid[x][y] = c;
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
    std::string shape, mode, mode2, color, color2;
    int x, y, p1, p2;
    bool filled = false, framed = false;

    parameters >> mode;

    modeChecker(mode);

    if (mode == "fill") {
        filled = true;
        parameters >> color;
        colorChecker(color);
        parameters >> mode2;
        modeChecker(mode2);
        if (mode2 == "frame") {
            framed = true;
            parameters >> color2;
            colorChecker(color2);
            parameters >> shape >> x >> y >> p1;
        } else {
            shape = mode2;
            parameters >> x >> y >> p1;
        }
    } else if (mode == "frame") {
        framed = true;
        parameters >> color2;
        colorChecker(color2);
        parameters >> mode2;
        modeChecker(mode2);
        if (mode2 == "fill") {
            filled = true;
            parameters >> color;
            colorChecker(color);
            parameters >> shape >> x >> y >> p1;
        } else {
            shape = mode2;
            parameters >> x >> y >> p1;
        }
    } else {
        shape = mode;
        parameters >> x >> y >> p1;
    }


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
            std::unique_ptr<Shape> newShape = std::make_unique<Rectangle>(x, y, filled, color, framed, color2, p1, p2);
            shapes.emplace_back(id, std::move(newShape));
            shapes.back().second->draw(*this, filled, color, framed, color2);
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
            std::unique_ptr<Shape> newShape = std::make_unique<Triangle>(x, y, filled, color, framed, color2, p1, p2);
            shapes.emplace_back(id, std::move(newShape));
            shapes.back().second->draw(*this, filled, color, framed, color2);
        }
    } else {
        if (shape == "horizontalLine") {
            for (const auto &existingShape: shapes) {
                if (auto *eShape = dynamic_cast<HorizontalLine *>(existingShape.second.get())) {
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
            std::unique_ptr<Shape> newShape = std::make_unique<HorizontalLine>(x, y, filled, color, framed, color2, p1);
            shapes.emplace_back(id, std::move(newShape));
            shapes.back().second->draw(*this, filled, color, framed, color2);
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
            std::unique_ptr<Shape> newShape = std::make_unique<VerticalLine>(x, y, filled, color, framed, color2, p1);
            shapes.emplace_back(id, std::move(newShape));
            shapes.back().second->draw(*this, filled, color, framed, color2);
        }
        if (shape == "circle") {
            for (const auto &existingShape: shapes) {
                if (auto *eShape = dynamic_cast<Circle *>(existingShape.second.get())) {
                    if (eShape->getRadius() == p1 && eShape->getX() == x && eShape->getY() == y) {
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
            std::unique_ptr<Shape> newShape = std::make_unique<Circle>(x, y, filled, color, framed, color2, p1);
            shapes.emplace_back(id, std::move(newShape));
            shapes.back().second->draw(*this, filled, color, framed, color2);
        }
    }
}

void Board::undo() {
    shapes.pop_back();

    grid.assign(BoardHeight, std::vector<char>(BoardWidth, ' '));

    for (const auto &shape: shapes) {
        shape.second->draw(*this, shape.second->getIsFilled(), shape.second->getColor(), shape.second->getColorFramed(),
                           shape.second->getColor2());
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

    for (const auto &shape: shapes) {
        fout << shape.first << " ";
        shape.second->saveInfo(fout);
    }

    fout.close();
}

void Board::load(std::string &filepath) {
    std::ifstream fin(filepath);

    if (!fin) {
        throw std::runtime_error("Can't open the file for loading " + filepath);
    }

    std::string shapeParameters;
    while (std::getline(fin, shapeParameters)) {
        std::istringstream parameters(shapeParameters);
        std::string shape, mode, mode2, color, color2;
        int x, y, p1, p2;
        long id;
        bool filled = false, framed = false;

        parameters >> id >> mode;

        if (mode == "1") {
            filled = true;
            parameters >> color;
            colorChecker(color);
            parameters >> mode2;
            if (mode2 == "1") {
                framed = true;
                parameters >> color2;
                colorChecker(color2);
            }
        } else {
            parameters >> mode2;
            if (mode2 == "1") {
                framed = true;
                parameters >> color2;
                colorChecker(color2);
            }
        }

        parameters >> shape >> x >> y >> p1;

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
                std::unique_ptr<Shape> newShape = std::make_unique<Rectangle>(x, y, filled, color, framed, color2, p1,
                                                                              p2);
                shapes.emplace_back(id, std::move(newShape));
                shapes.back().second->draw(*this, filled, color, framed, color2);
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
                std::unique_ptr<Shape> newShape = std::make_unique<Triangle>(x, y, filled, color, framed, color2, p1,
                                                                             p2);
                shapes.emplace_back(id, std::move(newShape));
                shapes.back().second->draw(*this, filled, color, framed, color2);
            }
        } else {
            if (shape == "horizontalLine") {
                for (const auto &existingShape: shapes) {
                    if (auto *eShape = dynamic_cast<HorizontalLine *>(existingShape.second.get())) {
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
                std::unique_ptr<Shape> newShape = std::make_unique<HorizontalLine>(x, y, filled, color, framed, color2,
                                                                                   p1);
                shapes.emplace_back(id, std::move(newShape));
                shapes.back().second->draw(*this, filled, color, framed, color2);
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
                std::unique_ptr<Shape> newShape = std::make_unique<VerticalLine>(x, y, filled, color, framed, color2,
                                                                                 p1);
                shapes.emplace_back(id, std::move(newShape));
                shapes.back().second->draw(*this, filled, color, framed, color2);
            }
            if (shape == "circle") {
                for (const auto &existingShape: shapes) {
                    if (auto *eShape = dynamic_cast<Circle *>(existingShape.second.get())) {
                        if (eShape->getRadius() == p1 && eShape->getX() == x && eShape->getY() == y) {
                            std::cerr << "Such shape at such position exists" << std::endl;
                            return;
                        }
                    }
                }
                if (x + p1 >= BoardWidth && y + p1 >= BoardHeight) {
                    std::cerr << "Inappropriate radius" << std::endl;
                    return;
                }
                std::unique_ptr<Shape> newShape = std::make_unique<Circle>(x, y, filled, color, framed, color2, p1);
                shapes.emplace_back(id, std::move(newShape));
                shapes.back().second->draw(*this, filled, color, framed, color2);
            }
        }

    }
    fin.close();
}

void Board::select(std::string &parameter) {
    std::istringstream parseParameters(parameter);
    long id;
    int x, y;
    if (parseParameters >> id) {
        for (const auto &shape: shapes) {
            if (shape.first == id) {
                selectedShape = shape.second.get();
                shape.second->printInfo();
                return;
            }
        }
    }
    parseParameters.clear();
    parseParameters.str(parameter);
    if (parseParameters >> x >> y) {
        bool founded = false;
        for (auto shape = shapes.rbegin(); shape != shapes.rend(); shape++) {
            if (shape->second->getX() == x && shape->second->getY() == y) {
                selectedShape = shape->second.get();
                shape->second->printInfo();
                founded = true;
                break;
            }
        }
        if (!founded) {
            std::cerr << "No shapes at these coordinates" << std::endl;
        }
    } else {
        std::cerr << "Wrong id/coordinates" << std::endl;
        return;
    }
}

void Board::remove() {
    if (selectedShape == nullptr) {
        std::cerr << "No shape to delete" << std::endl;
        return;
    }

    for (auto shape = shapes.begin(); shape != shapes.end(); shape++) {
        if (shape->second.get() == selectedShape) {
            shapes.erase(shape);
            selectedShape = nullptr;
            grid.assign(BoardHeight, std::vector<char>(BoardWidth, ' '));
            for (const auto &eShape: shapes) {
                eShape.second->draw(*this, eShape.second->getIsFilled(), eShape.second->getColor(),
                                    eShape.second->getColorFramed(),
                                    eShape.second->getColor2());
            }
            return;
        }
    }
}

void Board::edit(std::string &parameters) {

    std::istringstream parseParameters(parameters);
    int p1, p2;

    if (selectedShape == nullptr) {
        std::cerr << "No shape to edit" << std::endl;
        return;
    }

    for (auto shape = shapes.begin(); shape != shapes.end(); shape++) {
        if (shape->second.get() == selectedShape) {
            long id = shape->first;
            int x = shape->second->getX();
            int y = shape->second->getY();
            bool filled = shape->second->getIsFilled();
            bool framed = shape->second->getColorFramed();
            std::string color = shape->second->getColor();
            std::string color2 = shape->second->getColor2();



            if (dynamic_cast<Rectangle *>(shape->second.get())) {

                if(parseParameters >> p1 >> p2) {
                    if(p1 < BoardWidth || p2 < BoardHeight) {
                        remove();
                        std::unique_ptr<Shape> newShape = std::make_unique<Rectangle>(x, y, filled, color, framed, color2, p1,
                                                                                      p2);
                        shapes.emplace_back(id, std::move(newShape));
                        shapes.back().second->draw(*this, filled, color, framed, color2);
                        break;
                    }
                    else {
                        std::cerr << "Shape will go out of the board" << std::endl;
                        return;
                    }
                }
                else {
                    std::cerr << "Invalid argument count" << std::endl;
                    return;
                }
            }




            if (dynamic_cast<Triangle *>(shape->second.get())) {

                if(parseParameters >> p1 >> p2) {
                    if(p1 < BoardWidth || p2 < BoardHeight) {
                        remove();
                        std::unique_ptr<Shape> newShape = std::make_unique<Triangle>(x, y, filled, color, framed, color2, p1,
                                                                                     p2);
                        shapes.emplace_back(id, std::move(newShape));
                        shapes.back().second->draw(*this, filled, color, framed, color2);
                        break;
                    }
                    else {
                        std::cerr << "Shape will go out of the board" << std::endl;
                        return;
                    }
                }
                else {
                    std::cerr << "Invalid argument count" << std::endl;
                    return;
                }
            }




            if (dynamic_cast<HorizontalLine *>(shape->second.get())) {
                if(parseParameters >> p1) {
                    if(p1 < BoardWidth) {
                        remove();
                        std::unique_ptr<Shape> newShape = std::make_unique<HorizontalLine>(x, y, filled, color, framed, color2,
                                                                                           p1);
                        shapes.emplace_back(id, std::move(newShape));
                        shapes.back().second->draw(*this, filled, color, framed, color2);
                        break;
                    }
                    else {
                        std::cerr << "Shape will go out of the board" << std::endl;
                        return;
                    }
                }
                else {
                    std::cerr << "Invalid argument count" << std::endl;
                    return;
                }
            }



            if (dynamic_cast<VerticalLine *>(shape->second.get())) {

                if(parseParameters >> p1) {
                    if(p1 < BoardWidth) {
                        remove();
                        std::unique_ptr<Shape> newShape = std::make_unique<VerticalLine>(x, y, filled, color, framed, color2,
                                                                                         p1);
                        shapes.emplace_back(id, std::move(newShape));
                        shapes.back().second->draw(*this, filled, color, framed, color2);
                        break;
                    }
                    else {
                        std::cerr << "Shape will go out of the board" << std::endl;
                        return;
                    }
                }
                else {
                    std::cerr << "Invalid argument count" << std::endl;
                    return;
                }

            }



            if (dynamic_cast<Circle *>(shape->second.get())) {

                if(parseParameters >> p1) {
                    if(p1 < BoardWidth) {
                        remove();
                        std::unique_ptr<Shape> newShape = std::make_unique<Circle>(x, y, filled, color, framed, color2, p1);
                        shapes.emplace_back(id, std::move(newShape));
                        shapes.back().second->draw(*this, filled, color, framed, color2);
                        break;
                    }
                    else {
                        std::cerr << "Shape will go out of the board" << std::endl;
                        return;
                    }
                }
                else {
                    std::cerr << "Invalid argument count" << std::endl;
                    return;
                }
            }
        }
    }
}

void Board::paint(std::string &color) {



    if (selectedShape == nullptr) {
        std::cerr << "No shape to paint" << std::endl;
        return;
    }

    for (auto shape = shapes.begin(); shape != shapes.end(); shape++) {
        if (shape->second.get() == selectedShape) {
            long id = shape->first;
            int x = shape->second->getX();
            int y = shape->second->getY();
            bool filled = shape->second->getIsFilled();
            bool framed = shape->second->getColorFramed();




            if (auto *rectangle = dynamic_cast<Rectangle *>(shape->second.get())) {

                int p1 = rectangle->getWidth();
                int p2 = rectangle->getHeight();

                remove();
                if (!filled && !framed) {
                    std::unique_ptr<Shape> newShape = std::make_unique<Rectangle>(x, y, filled, color, true, color, p1,
                                                                                  p2);
                    shapes.emplace_back(id, std::move(newShape));
                    shapes.back().second->draw(*this, filled, color, true, color);
                    break;
                }

                std::unique_ptr<Shape> newShape = std::make_unique<Rectangle>(x, y, filled, color, framed, color, p1,
                                                                              p2);
                shapes.emplace_back(id, std::move(newShape));
                shapes.back().second->draw(*this, filled, color, framed, color);
                break;
            }




            if (auto *triangle = dynamic_cast<Triangle *>(shape->second.get())) {

                int p1 = triangle->getWidth();
                int p2 = triangle->getHeight();

                remove();
                if (!filled && !framed) {
                    std::unique_ptr<Shape> newShape = std::make_unique<Triangle>(x, y, filled, color, true, color, p1,
                                                                                 p2);
                    shapes.emplace_back(id, std::move(newShape));
                    shapes.back().second->draw(*this, filled, color, true, color);
                    break;
                }
                std::unique_ptr<Shape> newShape = std::make_unique<Triangle>(x, y, filled, color, framed, color, p1,
                                                                             p2);
                shapes.emplace_back(id, std::move(newShape));
                shapes.back().second->draw(*this, filled, color, framed, color);
                break;
            }




            if (auto *horizontalLine = dynamic_cast<HorizontalLine *>(shape->second.get())) {

                int p1 = horizontalLine->getLength();

                remove();
                if (!filled && !framed) {
                    std::unique_ptr<Shape> newShape = std::make_unique<HorizontalLine>(x, y, filled, color, true, color,
                                                                                       p1);
                    shapes.emplace_back(id, std::move(newShape));
                    shapes.back().second->draw(*this, filled, color, true, color);
                    break;
                }

                std::unique_ptr<Shape> newShape = std::make_unique<HorizontalLine>(x, y, filled, color, framed, color,
                                                                                   p1);
                shapes.emplace_back(id, std::move(newShape));
                shapes.back().second->draw(*this, filled, color, framed, color);
                break;
            }




            if (auto *verticalLine = dynamic_cast<VerticalLine *>(shape->second.get())) {

                int p1 = verticalLine->getLength();

                remove();

                if (!filled && !framed) {
                    std::unique_ptr<Shape> newShape = std::make_unique<VerticalLine>(x, y, filled, color, true, color,
                                                                                     p1);
                    shapes.emplace_back(id, std::move(newShape));
                    shapes.back().second->draw(*this, filled, color, true, color);
                    break;
                }


                std::unique_ptr<Shape> newShape = std::make_unique<VerticalLine>(x, y, filled, color, framed, color,
                                                                                 p1);
                shapes.emplace_back(id, std::move(newShape));
                shapes.back().second->draw(*this, filled, color, framed, color);
                break;
            }




            if (auto *circle = dynamic_cast<Circle *>(shape->second.get())) {


                int p1 = circle->getRadius();


                remove();

                if (!filled && !framed) {
                    std::unique_ptr<Shape> newShape = std::make_unique<Circle>(x, y, filled, color, true, color, p1);
                    shapes.emplace_back(id, std::move(newShape));
                    shapes.back().second->draw(*this, filled, color, true, color);
                    break;
                }

                std::unique_ptr<Shape> newShape = std::make_unique<Circle>(x, y, filled, color, framed, color, p1);
                shapes.emplace_back(id, std::move(newShape));
                shapes.back().second->draw(*this, filled, color, framed, color);
                break;
            }
        }
    }

}

void Board::move(int x, int y) {



    if (selectedShape == nullptr) {
        std::cerr << "No shape to move" << std::endl;
        return;
    }

    for (auto shape = shapes.begin(); shape != shapes.end(); shape++) {



        if (shape->second.get() == selectedShape) {
            long id = shape->first;
            bool filled = shape->second->getIsFilled();
            bool framed = shape->second->getColorFramed();
            std::string color = shape->second->getColor();
            std::string color2 = shape->second->getColor2();



            if (auto *rectangle = dynamic_cast<Rectangle *>(shape->second.get())) {

                int p1 = rectangle->getWidth();
                int p2 = rectangle->getHeight();

                remove();
                std::unique_ptr<Shape> newShape = std::make_unique<Rectangle>(x, y, filled, color, framed, color2, p1,
                                                                              p2);
                shapes.emplace_back(id, std::move(newShape));
                shapes.back().second->draw(*this, filled, color, framed, color2);
                break;
            }



            if (auto *triangle = dynamic_cast<Triangle *>(shape->second.get())) {

                int p1 = triangle->getWidth();
                int p2 = triangle->getHeight();

                remove();

                std::unique_ptr<Shape> newShape = std::make_unique<Triangle>(x, y, filled, color, framed, color2, p1,
                                                                             p2);
                shapes.emplace_back(id, std::move(newShape));
                shapes.back().second->draw(*this, filled, color, framed, color2);
                break;
            }



            if (auto *horizontalLine = dynamic_cast<HorizontalLine *>(shape->second.get())) {

                int p1 = horizontalLine->getLength();

                remove();

                std::unique_ptr<Shape> newShape = std::make_unique<HorizontalLine>(x, y, filled, color, framed, color2,
                                                                                   p1);
                shapes.emplace_back(id, std::move(newShape));
                shapes.back().second->draw(*this, filled, color, framed, color2);
                break;
            }



            if (auto *verticalLine = dynamic_cast<VerticalLine *>(shape->second.get())) {

                int p1 = verticalLine->getLength();

                remove();

                std::unique_ptr<Shape> newShape = std::make_unique<VerticalLine>(x, y, filled, color, framed, color2,
                                                                                 p1);
                shapes.emplace_back(id, std::move(newShape));
                shapes.back().second->draw(*this, filled, color, framed, color2);
                break;
            }



            if (auto *circle = dynamic_cast<Circle *>(shape->second.get())) {


                int p1 = circle->getRadius();


                remove();


                std::unique_ptr<Shape> newShape = std::make_unique<Circle>(x, y, filled, color, framed, color2, p1);
                shapes.emplace_back(id, std::move(newShape));
                shapes.back().second->draw(*this, filled, color, framed, color2);
                break;
            }
        }
    }
}