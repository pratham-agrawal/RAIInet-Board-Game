#include "board.h"
#include <vector>
#include <memory>
using namespace std;

Board::Board(){
    for (int i=0; i<8; i++){
        vector<Cell> vect;
        theBoard.emplace_back(vect);
        for (int j=0; j<8; ++j) {
            //auto temp = make_unique<Cell>(i, j); 
			//theBoard.at(i).emplace_back(temp);
            theBoard.at(i).emplace_back(Cell(i,j));
			theBoard.at(i).at(j).setBoard(this);
		}
	}
    theBoard.at(0).at(3).setServer(1);
    theBoard.at(0).at(4).setServer(1);
    theBoard.at(7).at(3).setServer(2);
    theBoard.at(7).at(4).setServer(2);
}

char Board::getState(int row, int col) const {
    int piece = theBoard.at(row).at(col).hasPiece();
    if (piece){
        return (piece + 48);
    }
    int fw = theBoard.at(row).at(col).isFirewall();
    if (fw==1){
        return 'm';
    }
    if (fw==2){
        return 'w';
    }
    if (theBoard.at(row).at(col).isServer()){
        return 's';
    }
    return '.';
}
