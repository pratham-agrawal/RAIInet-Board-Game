#ifndef BOARD_H
#define BOARD_H
#include <string>
#include <iostream>
#include "subject.h"
#include "cell.h"

class Board: public Subject{
    std::vector<std::vector<Piece*> theBoard;
    Player* p1;
    Player* p2;
    public:
        void move (piece: string, direction: string);
        string getState(x: int, y: int);
        bool positionOccupied(x: int, y: int);
        void removePiece(p: *Piece);
}