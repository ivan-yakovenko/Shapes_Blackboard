#pragma once

#include <iostream>
#include <fstream>

#define yellow "\033[33m"
#define blue "\033[34m"
#define red "\033[31m"
#define magenta "\033[35m"
#define cyan "\033[36m"
#define reset "\033[0m"

class Board;

class Shape {
protected:
    bool isFilled = false;
    bool colorFramed = false;
    std::string color;
    std::string color2;
    int x, y;
public:
    Shape(int x, int y, bool isFilled, std::string &color, bool colorFramed, std::string &color2) : x(x), y(y),
                                                                                                    isFilled(isFilled),
                                                                                                    color(color),
                                                                                                    colorFramed(
                                                                                                            colorFramed),
                                                                                                    color2(color2) {};

    virtual void draw(Board &board, bool isFilled, std::string color, bool colorFramed, std::string color2) = 0;

    virtual ~Shape() = default;

    static long generateID() {
        static long id = 0;
        return id++;
    }

    virtual void printInfo() = 0;

    virtual void saveInfo(std::ofstream &fout) = 0;

    [[nodiscard]] bool getIsFilled() const {
        return this->isFilled;
    }

    [[nodiscard]] bool getColorFramed() const {
        return this->colorFramed;
    }

    [[nodiscard]] std::string getColor() const {
        return this->color;
    }

    [[nodiscard]] std::string getColor2() const {
        return this->color2;
    }

    [[nodiscard]] int getX() const {
        return this->x;
    }

    [[nodiscard]] int getY() const {
        return this->y;
    }

    void setColor(std::string& colorSetter) {
        this->color = colorSetter;
    };

    void setColor2(std::string& colorSetter2) {
        this->color2 = colorSetter2;
    }

    void setFilled(bool isFilledSetter) {
        this->isFilled = isFilledSetter;
    }

    void setFramed(bool isFramedSetter) {
        this->colorFramed = isFramedSetter;
    }

    void setX(int xSetter) {
        this->x = xSetter;
    }

    void setY(int ySetter) {
        this->y = ySetter;
    }

};