#ifndef BOARD_H
#define BOARD_H
#include <string>
#include <iostream>

class board: public subject{
    std::vector<std::vector<Piece*> theBoard;
    Player* p1;
    Player* p2;
    
}