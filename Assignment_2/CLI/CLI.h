#pragma once

#include "../Board/Board.h"

class CLI {
private:
    Board board;
    bool static validCommand(std::string &command);
public:
    void run();
};
