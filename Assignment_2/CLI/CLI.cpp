#include "CLI.h"

bool CLI::validCommand(std::string &command) {
    if (command != "draw" && command != "list" && command != "shapes" && command != "add" && command != "undo" &&
        command != "clear" && command != "save" && command != "load") {
        std::cerr << "Wrong command, try again" << std::endl;
        return false;
    }
    return true;
}

void CLI::run() {
    while (true) {
        std::string commandLine, command;
        std::getline(std::cin, commandLine);
        std::istringstream tokens(commandLine);
        tokens >> command;
        if (!validCommand(command)) {
            continue;
        }
        if (command == "draw") {
            board.draw();
        }
        if (command == "list") {
            board.list();
        }
        if(command == "shapes") {
            board.showShapes();
        }
        if (command == "add") {
            std::string shapeParameters;
            std::getline(tokens, shapeParameters);
            board.add(shapeParameters);
        }
        if (command == "undo") {
            board.undo();
        }
        if (command == "clear") {
            board.clear();
        }
        if (command == "save") {
            std::string filepath;
            tokens >> filepath;
            board.save(filepath);
        }
        if (command == "load") {
            std::string filepath;
            tokens >> filepath;
            board.load(filepath);
        }
    }
}
