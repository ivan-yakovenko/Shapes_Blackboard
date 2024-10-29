cmake_minimum_required(VERSION 3.28)
project(Shapes_Blackboard)

set(CMAKE_CXX_STANDARD 20)

add_executable(Shapes_Blackboard src/main.cpp
        src/Shape/Shape.h
        src/Board/Board.cpp
        src/Board/Board.h
        src/HorizontalLine/HorizontalLine.cpp
        src/HorizontalLine/HorizontalLine.h
        src/VerticalLine/VerticalLine.cpp
        src/VerticalLine/VerticalLine.h
        src/Rectangle/Rectangle.cpp
        src/Rectangle/Rectangle.h
        src/Circle/Circle.cpp
        src/Circle/Circle.h
        src/Triangle/Triangle.cpp
        src/Triangle/Triangle.h
        src/Triangle/Triangle.cpp
        src/Triangle/Triangle.h
        src/CLI/CLI.cpp
        src/CLI/CLI.h
)