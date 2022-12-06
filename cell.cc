#include "cell.h"
using namespace std;

Cell::Cell(int row, int col) : row{row}, col{col}, firewall{0}, server{0}, piece{nullptr} {}

int Cell::hasPiece() const{
    if (piece == nullptr){
        return 0;
    }
    else {
        return (piece->getPlayer());
    }
}

bool Cell::setHurricaned(bool val) {
    hurricaned = val;
}

bool Cell::isHurricaned() {
    return hurricaned;
}


int Cell::isFirewall() const{
    return firewall;
}

int Cell::isServer() const{
    return server;
}

int Cell::getRow(){
    return row;
}

int Cell::getCol(){
    return col;
}

shared_ptr <Piece> Cell::getPiece(){
    return piece;
}

void Cell::setBoard(shared_ptr <Board> b){
    theBoard = b;
}

void Cell::setFirewall(int x){
    firewall = x;
}


void Cell::setServer(int x){
    server = x;
}

void Cell::setPiece(shared_ptr <Piece> p){
    piece = p;
}
