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
    bool isDownloaded;
    //bool isRevealed; // if revealed then true
    public:
        Piece(char n, std::string link, bool vir, int str, int player);
        char getName() const;
        std::string getLink() const;
        bool playerTwo() const;
        int getStrength();
        bool virus() const;
        void polarize();
        int getRow();
        int getCol();
        int getPlayer();
        void setCol(int c);
        void setRow(int r);
        void setVisibility(bool vis);
        bool getVisibility();
        std::string getLinkName();
        void changeName(char newName);
        bool getBoosted();
        void setBoosted(bool val);
        bool getDownloaded();
        void setDownloaded(bool d);
};

#endif