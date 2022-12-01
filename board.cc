#include "board.h"
#include <vector>
#include <memory>
#include <string>
using namespace std;

Board::Board(){
    //Create empty cells
    for (int i=0; i<8; i++){
        vector<Cell *> vect;
        theBoard.emplace_back(vect);
        for (int j=0; j<8; ++j) {
            theBoard.at(i).emplace_back(new Cell(i,j));
			theBoard.at(i).at(j)->setBoard(this);
		}
	}

}

void Board::basic_setup(){
    //creates servers
    theBoard.at(0).at(3)->setServer(1);
    theBoard.at(0).at(4)->setServer(1);
    theBoard.at(7).at(3)->setServer(2);
    theBoard.at(7).at(4)->setServer(2);
    
    //creates pieces A,B,C & a,b,c
    for(int i = 0; i < 3; i++){
        Piece * A = new Piece(i+65, false, 0, false);
        A->setBoard(this);
        A->setCell(theBoard.at(7).at(i));
        theBoard.at(7).at(i)->setPiece(A);
        p2Pieces.emplace_back(A);

        Piece * a = new Piece(i+97, false, 0, false);
        a->setBoard(this);
        a->setCell(theBoard.at(0).at(i));
        theBoard.at(0).at(i)->setPiece(a);
        p1Pieces.emplace_back(a);
    }

    //creates pieces D,E & d,e
    for(int i = 3; i < 5; i++){
        Piece * A = new Piece(i+65, false, 0, false);
        A->setBoard(this);
        A->setCell(theBoard.at(6).at(i));
        theBoard.at(6).at(i)->setPiece(A);
        p2Pieces.emplace_back(A);

        Piece * a = new Piece(i+97, false, 0, false);
        a->setBoard(this);
        a->setCell(theBoard.at(1).at(i));
        theBoard.at(1).at(i)->setPiece(a);
        p1Pieces.emplace_back(a);
    }

    //creates pieces F,G,H & f,g,h
    for(int i = 5; i < 8; i++){
        Piece * A = new Piece(i+65, false, 0, false);
        A->setBoard(this);
        A->setCell(theBoard.at(7).at(i));
        theBoard.at(7).at(i)->setPiece(A);
        p2Pieces.emplace_back(A);

        Piece * a = new Piece(i+97, false, 0, false);
        a->setBoard(this);
        a->setCell(theBoard.at(0).at(i));
        theBoard.at(0).at(i)->setPiece(a);
        p1Pieces.emplace_back(a);
    }
}
char Board::getState(int row, int col) const {
    Cell *current = theBoard.at(row).at(col);
    if (current->hasPiece()){
        return current->getPiece()->getName();
    }
    int fw = current->isFirewall();
    if (fw==1){
        return 'm';
    }
    if (fw==2){
        return 'w';
    }
    if (current->isServer()){
        return 's';
    }
    return '.';
}

void Board::movePiece(char name, string direction){
    Piece * currentPiece = nullptr;
    if(name >= 65 && name <= 72){
        currentPiece = p2Pieces.at(name - 65);
    } else if (name >= 97 && name <= 104){
        currentPiece = p1Pieces.at(name - 97);
    } else {
        return;
    }
    Cell * currentCell = currentPiece->getCell();
    int row = currentCell->getRow();
    int col = currentCell->getCol();
    if (direction == "up"){
        currentPiece->setCell(theBoard.at(row - 1).at(col));
        theBoard.at(row - 1).at(col)->setPiece(currentPiece);
    } else if (direction == "down"){
        currentPiece->setCell(theBoard.at(row + 1).at(col));
        theBoard.at(row + 1).at(col)->setPiece(currentPiece);
    } else if (direction == "left"){
        currentPiece->setCell(theBoard.at(row).at(col - 1));
        theBoard.at(row).at(col - 1)->setPiece(currentPiece);
    } else if (direction == "right"){
        currentPiece->setCell(theBoard.at(row).at(col + 1));
        theBoard.at(row).at(col + 1)->setPiece(currentPiece);
    }
    currentCell->setPiece(nullptr);
    return;
}
