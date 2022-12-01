#include "piece.h"
using namespace std;

Piece::Piece(Board *b, Cell *c, char n, bool vir, int str, bool player): b{b}, cell{c}, name{n}, isVirus{vir}, strength{str}, playerNum{player}{}

bool Piece::playerTwo() const{
    return playerNum - 1;
}

bool Piece::Virus() const{
    return isVirus;
}

void Piece::setVirus(bool vir){
    isVirus = vir;
}
