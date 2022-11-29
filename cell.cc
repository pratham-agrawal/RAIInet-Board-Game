#include "cell.h"

Cell::Cell(int row, int col) : row{row}, col{col} {}

int Cell::hasPiece(){
    /*
    if (piece == Null){
        return true;
    }
    return false;
    */
}


int Cell::isFirewall(){
    return firewall;
}

int Cell::isFirewall(){
    return firewall;
}

int Cell::isServer(){
    return server;
}

int Cell::getRow(){
    return row;
}

int Cell::getCol(){
    return col;
}
