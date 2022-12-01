#ifndef PIECE_H
#define PIECE_H
#include <string>
#include <iostream>
#include <memory>
#include "cell.h"

class Board;

class Piece {
    Board * b;
    Cell *cell;
    char name;
    bool isVirus;
    int strength;
    bool playerNum;
    public:
        Piece(Board *b, Cell *c, char n, bool vir, int str, bool player);
        bool playerTwo() const;
        bool Virus() const;
        void setVirus(bool vir);
};

#endif