#include "piece.h"
using namespace std;

Piece::Piece(char n, string link, bool vir, int str, int player): name{n},  link{link}, isVirus{vir}, strength{str}, playerNum{player}, isVisible{false} {}

char Piece::getName() const{
    return name;
}

std::string Piece::getLink() const {
    return link;
}

int Piece::getPlayer(){
    return playerNum;
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



int Piece::getStrength() {
    return strength;
}


int Piece::getRow(){
    return row;
}

int Piece::getCol(){
    return col;
}

void Piece::setRow(int r){
    row = r;
}

void Piece::setCol(int c){
    col = c;
}

void Piece::setVisibility(bool vis){
    isVisible = vis;
}

bool Piece::getVisibility(){
    return isVisible;
}

string Piece::getLinkName(){
    return link;
}



/*
void Piece::setBoard(Board * b){
    b = b;
}

void Piece::setCell(Cell * c){
    cell = c;
}

Cell* Piece::getCell(){
    return cell;
}

void Piece::flipReveled(){
    isRevealed = !(isRevealed);
}

bool Piece::getRevealed(){
    return isRevealed;
}
*/
