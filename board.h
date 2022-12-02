#ifndef BOARD_H
#define BOARD_H
#include <string>
#include <iostream>
#include "subject.h"
#include "cell.h"
#include <memory>
#include "player.h"
#include <vector>

class Board: public Subject{
    std::vector<std::vector<Cell*>> theBoard;
    Player *p1;
    Player *p2;
    public:
        Board(Player *player1, Player *player2);
        void basic_setup();
        void movePiece(char name, std::string direction);
        char getState(int row, int col) const;
        bool positionOccupied(int x, int y);
        //void removePiece(p: *Piece);
};


#endif