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
    std::vector<std::vector<std::shared_ptr<Cell>>> theBoard;
    std::vector<std::shared_ptr <Piece>> cementedPieces;
    std::shared_ptr <Player> p1;
    std::shared_ptr <Player> p2;
    int playerTurn;
    bool abilityUsed;
    public:
        Board(std::shared_ptr <Player> player1, std::shared_ptr <Player> player2, int playT);
        void basic_setup();
        bool movePiece(char name, std::string direction);
        char getState(int row, int col) const;
        bool positionOccupied(int x, int y);
        std::shared_ptr <Player> getP1();
        std::shared_ptr <Player> getP2();
        int getPlayerTurn();
        void setTurn(int turn);
        void displayBoard();
        bool useAbility(int ability, int playerNum);
        void updateCemented();
        void updateHurricane();
        bool getAbilityUsed();
        void setAbilityUsed(bool val);
        //void removePiece(p: *Piece);
};


#endif