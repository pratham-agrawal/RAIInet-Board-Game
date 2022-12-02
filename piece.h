#ifndef PIECE_H
#define PIECE_H
#include <string>
#include <iostream>
#include <memory>
#include "cell.h"

class Board;

class Cell;

class Piece {
    Board * b;
    Cell * cell;
    char name;
    bool isVirus;
    int strength;
    int playerNum;
    bool isVisible;
    public:
        Piece(char n, bool vir, int str, int player);
        char getName() const;
        bool playerTwo() const;
        void setBoard(Board * b);
        void setCell(Cell * c);
        Cell* getCell();
        bool Virus() const;
        void setVirus(bool vir);
};

#endif