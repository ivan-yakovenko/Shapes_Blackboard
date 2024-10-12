#include "Board/Board.h"
#include "Rectangle/Rectangle.h"

int main() {
    Board board;

    Rectangle rect(50, 6, 20, 4);
    rect.draw(board);

    board.draw();

}