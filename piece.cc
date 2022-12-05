#include "piece.h"
using namespace std;

Piece::Piece(char n, string link, bool vir, int str, int player): name{n}, link{link}, isVirus{vir}, strength{str}, playerNum{player}, isVisible{false}, isBoosted{false}, isDownloaded{false} {}

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

bool Piece::virus() const{
    return isVirus;
}

void Piece::polarize() {
    if (isVirus) {
        link = "D" + to_string(strength);
    }
    else {
        link = "V" + to_string(strength);
    }
    isVirus = !isVirus;
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

void Piece::changeName(char newName) {
    name = newName;
}

bool Piece::getBoosted(){
    return isBoosted;
}

void Piece::setBoosted(bool val){
    cout << name << " just got boosted!" << endl;
    isBoosted = val;
}

bool Piece::getDownloaded(){
    return isDownloaded;
}

void Piece::setDownloaded(bool d){
    isDownloaded = d;
}

