#ifndef CELL_H
#define CELL_H
#include <string>
#include <iostream>

class Board;

class Cell {
    int row, col;
    Board * theBoard;
    //shared_ptr<Piece> piece;
    int server;
    int firewall;
    public:
        Cell(int row, int col);
        int hasPiece();
        int isFirewall();
        int isServer();
        int getRow();
        int getCol();
}