#ifndef PIECE_H
#define PIECE_H
#include <string>
#include <iostream>
#include <memory>
#include "cell.h"

class Board;

class Cell;

class Piece {
    //Board * b;
    //Cell * cell;
    char name;
    std::string link;
    bool isVirus;
    int strength;
    int playerNum;
    bool isVisible;
    int row;
    int col;
    bool isBoosted;
    //bool isRevealed; // if revealed then true
    public:
        Piece(char n, std::string link, bool vir, int str, int player);
        char getName() const;
        std::string getLink() const;
        bool playerTwo() const;
        //void setBoard(Board * b);
        //void setCell(Cell * c);
        int getStrength();
        //Cell* getCell();
        bool Virus() const;
        void setVirus(bool vir);
        int getRow();
        int getCol();
        int getPlayer();
        void setCol(int c);
        void setRow(int r);
        void setVisibility(bool vis);
        bool getVisibility();
        std::string getLinkName();
        void changeName(char newName);
        int getBoosted();
        void setBoosted(bool val);
        //bool flipRevealed();
        //bool getRevealed();
        void changeName(char newName);
};

#endif