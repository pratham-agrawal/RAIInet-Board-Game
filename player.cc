#include <string>
#include <vector>
#include <iostream>
#include "player.h"
#include "piece.h"
#include <algorithm>
#include <random>
using namespace std;

Player::Player(): dataDownloaded{0}, virusDownloaded{0} {
    vector<shared_ptr <Piece>> pieces;
    vector<char> abilities;
}

// void Player::setPieces(int playerNum) {
//     string token;
//     bool isVirus = false;
//     int strength;
//     for (char i = 'a'; i <= 'h'; ++i) {
//         token = myPieces.at(i);
//         if (token[0] == 'v' || token[0] == 'V') {
//             isVirus = true;
//         }
//         strength = int(token[1] - '0');
//         Piece *p = new Piece(i, isVirus, strength, playerNum);
//         pieces.emplace_back(p);
//     }
// }

void Player::addPiece(shared_ptr <Piece> p) {
    pieces.emplace_back(p);
}


Player::~Player() {
    // abilities.clear();
    pieces.clear();
    cout << "Player deleted: " << endl;
}

vector<shared_ptr <Piece>> Player::getPieces() {
    return pieces;
}

void Player::downloadData(){
    dataDownloaded++;
}

void Player::downloadVirus(){
    virusDownloaded++;
}

int Player::getData(){
    return dataDownloaded;
}

int Player::getVirus(){
    return virusDownloaded;
}

vector<char> Player::getAbilities(){
    return abilities;
}

void Player::shufflePieces(int playerNum) {
    shuffle(pieces.begin(), pieces.end(), random_device());
    char ascii;
    if (playerNum == 1) {
        ascii = 'a';
    }
    else {
        ascii = 'A';
    }
    for (int i = 0; i < 8; ++i) {
        pieces.at(i)->changeName(ascii + i);
    }
}




