#include "piece.h"
using namespace std;

Piece::Piece(char n, string link, bool vir, int str, int player): name{n},  link{link}, isVirus{vir}, strength{str}, playerNum{player}, isVisible{false} {}

char Piece::getName() const{
    return name;
}

std::string Piece::getLink() const {
    return link;
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

int Piece::getStrength() {
    return strength;
}

Cell* Piece::getCell(){
    return cell;
}
