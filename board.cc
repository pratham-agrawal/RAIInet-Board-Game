#include "board.h"
#include <vector>
#include <memory>
#include <string>
#include "player.h"
#include "piece.h"
using namespace std;

Board::Board(Player *player1, Player *player2, int playT): p1{player1}, p2{player2}, playerTurn{playT} {
    //Create empty cells
    for (int i=0; i<8; i++){
        vector<Cell *> vect;
        theBoard.emplace_back(vect);
        for (int j=0; j<8; ++j) {
            Cell * temp = new Cell{i,j};
            theBoard.at(i).emplace_back(temp);
			theBoard.at(i).at(j)->setBoard(this);
		}
	}
}

void Board::basic_setup() {
    //creates servers
    theBoard.at(0).at(3)->setServer(1);
    theBoard.at(0).at(4)->setServer(1);
    theBoard.at(7).at(3)->setServer(2);
    theBoard.at(7).at(4)->setServer(2);

    for (int i = 0; i < 8; ++i) {
        int top = 0;
        int bottom = 7;
        if (i > 2 && i < 5) {
            top = 1;
            bottom = 6;
        }

        //p1->getPieces().at(i)->setBoard(this);
        //p1->getPieces().at(i)->setCell(theBoard.at(top).at(i));
        p1->getPieces().at(i)->setRow(top);
        p1->getPieces().at(i)->setCol(i);
        theBoard.at(top).at(i)->setPiece(p1->getPieces().at(i));

        //p2->getPieces().at(i)->setBoard(this);
        //p2->getPieces().at(i)->setCell(theBoard.at(bottom).at(i));
        p2->getPieces().at(i)->setRow(bottom);
        p2->getPieces().at(i)->setCol(i);
        theBoard.at(bottom).at(i)->setPiece(p2->getPieces().at(i));
    }
}



char Board::getState(int row, int col) const {
    Cell *current = theBoard.at(row).at(col);
    if (current->hasPiece()){
        return current->getPiece()->getName();
    }
    int fw = current->isFirewall();
    if (fw == 1) {
        return 'm';
    }
    if (fw == 2) {
        return 'w';
    }
    if (current->isServer()){
        return 's';
    }
    return '.';
}

bool Board::movePiece(char name, string direction){
    //Set player and piece
    int player_num = 0;
    Piece * currentPiece = nullptr;
    Player * player = nullptr;
    Player * opponent = nullptr;
    
    if(name >= 65 && name <= 72 && playerTurn == 2){
        currentPiece = p2->getPieces().at(name - 65);
        player_num = 2;
        player = p2;
        opponent = p1;
    } else if (name >= 97 && name <= 104 && playerTurn == 1){
        currentPiece = p1->getPieces().at(name - 97);
        player_num = 1;
        player = p1;
        opponent = p2;
    } else {
        cout << "invalid piece" << endl;
        return false;
    }

    int oldX = currentPiece->getRow();
    int oldY = currentPiece->getCol();

    //Set target coordinates
    int newX = oldX;
    int newY = oldY;
    //int newX = currentPiece->getRow();
    //int newY = currentPiece->getCol();
    int moveAmount = 1 + currentPiece->getBoosted();
    //cout << currentPiece->getBoosted() << moveAmount << endl;
    if (direction == "up") {
        //newX --;
        newX -= moveAmount;
    }
    else if (direction == "down") {
        //newX ++;
        newX += moveAmount;
    }
    else if (direction == "left") {
        //newY --;
        newY -= moveAmount;
    }
    else if (direction == "right") {
        //newY ++;
        newY += moveAmount;
    }

    //Check if moving off board
    if ((player_num == 1 && newX == 8) || (player_num == 2 && newX == -1)){
        cout << "Downloading own link" << endl;
        //REVEAL?
        if (currentPiece->Virus()){
            player->downloadVirus();
        }
        else {
            player->downloadData();
        }
        theBoard.at(oldX).at(oldY)->setPiece(nullptr);
        return true;
    }

    if (newX < 0 || newX > 7 || newY < 0 || newY > 7){
        cout << "Attempting to move off board" << endl;
        return false;
        //throw ();
    }

    Cell * targetCell = theBoard.at(newX).at(newY);
    
    //Check if server
    if (targetCell->isServer()){
        if (targetCell->isServer() == player_num){
            cout << "Attempting to move onto own server" << endl;
            return false;
            //throw();
        }
        else {
            cout << "Oponents server downloaded your link" << endl;
            if (currentPiece->Virus()){
                opponent->downloadVirus();
            }
            else {
                opponent->downloadData();
            }
            theBoard.at(oldX).at(oldY)->setPiece(nullptr);
            return true;
        }
    }


    //Check if moving to square with piece
    if (targetCell->hasPiece()){
        if (targetCell->hasPiece() == player_num){
            cout << "Attempting to move to square with own piece" << endl;
            return false;
            //throw ();
        }
        else {
            if (currentPiece->getStrength() >= targetCell->getPiece()->getStrength()){
                cout << "Your strength higher" << endl;
                if (targetCell->getPiece()->Virus()){
                    player->downloadVirus();
                }
                else {
                    player->downloadData();
                }
                currentPiece->setVisibility(true);
                targetCell->getPiece()->setVisibility(true);
                return true;
                //remove from player?? set downloaded to true??
            }
            else {
                cout << "Your strength weaker" << endl;
                if (currentPiece->Virus()){
                    opponent->downloadVirus();
                }
                else {
                    opponent->downloadData();
                }
                currentPiece->setVisibility(true);
                targetCell->getPiece()->setVisibility(true);
                theBoard.at(oldX).at(oldY)->setPiece(nullptr);
                return true;
                // remove from player?? set downloaded to true??
            }
        }
    }
    
    //move piece
    targetCell->setPiece(currentPiece);
    currentPiece->setRow(newX);
    currentPiece->setCol(newY);
    theBoard.at(oldX).at(oldY)->setPiece(nullptr);

    //Check if firewall
    if (targetCell->isFirewall() && targetCell->isFirewall() != player_num) {
        currentPiece->setVisibility(true);
        if (currentPiece->Virus()){
            player->downloadVirus();
            targetCell->setPiece(nullptr);
        }
    }
    return true;
}

Player * Board::getP1(){
    return p1;
}

Player * Board::getP2(){
    return p2;
}

int Board::getPlayerTurn(){
    return playerTurn;
}

void Board::setTurn(int turn){
    playerTurn = turn;
}
