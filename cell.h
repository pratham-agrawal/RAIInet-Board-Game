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
    //std::shared_ptr <Board> theBoard;
    std::shared_ptr <Piece> piece;
    int firewall;
    int server; 
    bool hurricaned;
    public:
        Cell(int row, int col);
        int hasPiece() const;
        int isFirewall() const;
        int isServer() const;
        int getRow();
        int getCol();
        std::shared_ptr <Piece> getPiece();
        //void setBoard(std::shared_ptr <Board> b);
        void setFirewall(int x);
        void setServer(int x);
        void setPiece(std::shared_ptr <Piece> p);
        bool isHurricaned();
        void setHurricaned(bool val);
};

#endif
