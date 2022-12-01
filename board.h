#ifndef BOARD_H
#define BOARD_H
#include <string>
#include <iostream>
#include "subject.h"
#include "cell.h"
#include <memory>
//#include "player.h"

class Board: public Subject{
    std::vector<std::vector<Cell*>> theBoard;
    std::vector<Piece*> p1Pieces;
    std::vector<Piece*> p2Pieces;
    //Player* p1;
    //Player* p2;
    public:
        Board();
        void basic_setup();
        void movePiece(char name, std::string direction);
        char getState(int row, int col) const;
        bool positionOccupied(int x, int y);
        //void removePiece(p: *Piece);
};

#endif