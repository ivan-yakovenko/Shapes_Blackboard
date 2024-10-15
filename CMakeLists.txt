cmake_minimum_required(VERSION 3.28)
project(Shapes_Blackboard)

set(CMAKE_CXX_STANDARD 20)

add_executable(Shapes_Blackboard Assignment_2/main.cpp
        Assignment_2/Shape/Shape.h
        Assignment_2/Board/Board.cpp
        Assignment_2/Board/Board.h
        Assignment_2/HorizontalLine/HorizontalLine.cpp
        Assignment_2/HorizontalLine/HorizontalLine.h
        Assignment_2/VerticalLine/VerticalLine.cpp
        Assignment_2/VerticalLine/VerticalLine.h
        Assignment_2/Rectangle/Rectangle.cpp
        Assignment_2/Rectangle/Rectangle.h
        Assignment_2/Circle/Circle.cpp
        Assignment_2/Circle/Circle.h
        Assignment_2/Triangle/Triangle.cpp
        Assignment_2/Triangle/Triangle.h
        Assignment_2/Triangle/Triangle.cpp
        Assignment_2/Triangle/Triangle.h
        Assignment_2/CLI/CLI.cpp
        Assignment_2/CLI/CLI.h
)