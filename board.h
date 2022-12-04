#ifndef BOARD_H
#define BOARD_H
#include <string>
#include <iostream>
#include "subject.h"
#include "cell.h"
#include <memory>
#include "player.h"
#include <vector>

class Board: public Subject{
    std::vector<std::vector<Cell*>> theBoard;
    Player *p1;
    Player *p2;
    int playerTurn;
    public:
        Board(Player *player1, Player *player2, int playT);
        void basic_setup();
        bool movePiece(char name, std::string direction);
        char getState(int row, int col) const;
        bool positionOccupied(int x, int y);
        Player* getP1();
        Player* getP2();
        int getPlayerTurn();
        void setTurn(int turn);
<<<<<<< HEAD
        bool useAbility(int ability, int playerNum);
=======
>>>>>>> a4d1ffc (movement bug fixes)
        void displayBoard();
        //void removePiece(p: *Piece);
};


#endif