#ifndef CELL_H
#define CELL_H
#include <string>
#include <iostream>
#include <memory>

class Board;

class Cell {
    int row, col;
    Board * theBoard;
    //shared_ptr<Piece> piece;
    int server;
    int firewall;
    public:
        Cell(int row, int col);
        int hasPiece() const;
        int isFirewall() const;
        int isServer() const;
        int getRow();
        int getCol();
        void setBoard(Board * b);
        void setFirewall(int x);
        void setServer(int x);
};

#endif