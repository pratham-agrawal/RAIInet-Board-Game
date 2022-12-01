#include "piece.h"
using namespace std;

Piece::Piece(char n, bool vir, int str, bool player): name{n}, isVirus{vir}, strength{str}, playerNum{player}{}

char Piece::getName() const{
    return name;
}

bool Piece::playerTwo() const{
    return playerNum - 1;
}

bool Piece::Virus() const{
    return isVirus;
}

void Piece::setVirus(bool vir){
    isVirus = vir;
}

void Piece::setBoard(Board * b){
    b = b;
}

void Piece::setCell(Cell * c){
    cell = c;
}
