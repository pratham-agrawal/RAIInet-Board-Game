#include "board.h"
#include <vector>
#include <memory>
using namespace std;

Board::Board(){
    for (int i=0; i<8; i++){
        vector<Cell *> vect;
        theBoard.emplace_back(vect);
        for (int j=0; j<8; ++j) {
            //auto temp = make_unique<Cell>(i, j); 
			//theBoard.at(i).emplace_back(temp);
            theBoard.at(i).emplace_back(new Cell(i,j));
			theBoard.at(i).at(j)->setBoard(this);
		}
	}

}

void Board::basic_setup(){
    theBoard.at(0).at(3)->setServer(1);
    theBoard.at(0).at(4)->setServer(1);
    theBoard.at(7).at(3)->setServer(2);
    theBoard.at(7).at(4)->setServer(2);
    
    for(int i = 0; i < 3; i++){
        Piece * A = new Piece(i+65, false, 0, false);
        A->setBoard(this);
        A->setCell(theBoard.at(7).at(i));
        theBoard.at(7).at(i)->setPiece(A);

        Piece * a = new Piece(i+97, false, 0, false);
        A->setBoard(this);
        A->setCell(theBoard.at(0).at(i));
        theBoard.at(0).at(i)->setPiece(a);
    }

    for(int i = 3; i < 5; i++){
        Piece * A = new Piece(i+65, false, 0, false);
        A->setBoard(this);
        A->setCell(theBoard.at(6).at(i));
        theBoard.at(6).at(i)->setPiece(A);

        Piece * a = new Piece(i+97, false, 0, false);
        A->setBoard(this);
        A->setCell(theBoard.at(1).at(i));
        theBoard.at(1).at(i)->setPiece(a);
    }

    for(int i = 5; i < 8; i++){
        Piece * A = new Piece(i+65, false, 0, false);
        A->setBoard(this);
        A->setCell(theBoard.at(7).at(i));
        theBoard.at(7).at(i)->setPiece(A);

        Piece * a = new Piece(i+97, false, 0, false);
        A->setBoard(this);
        A->setCell(theBoard.at(0).at(i));
        theBoard.at(0).at(i)->setPiece(a);
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
