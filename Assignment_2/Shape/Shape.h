#pragma once
#include <iostream>

class Board;

class Shape {
public:
    virtual void draw(Board& board) = 0;
    virtual ~Shape() = default;
    static long generateID() {
        return std::rand();
    }
    virtual void printInfo() = 0;
};