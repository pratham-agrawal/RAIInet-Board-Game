#ifndef CELL_H
#define CELL_H
#include <string>
#include <iostream>
#include <memory>
#include "piece.h"

class Board;
class Piece;

class Cell {
    int row, col;
    Board * theBoard;
    Piece * piece;
    int server;
    int firewall;
    public:
        Cell(int row, int col);
        int hasPiece() const;
        int isFirewall() const;
        int isServer() const;
        int getRow();
        int getCol();
        Piece* getPiece();
        void setBoard(Board * b);
        void setFirewall(int x);
        void setServer(int x);
        void setPiece(Piece *p);
};

#endif