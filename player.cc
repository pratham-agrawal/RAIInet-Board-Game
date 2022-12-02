#include <string>
#include <vector>
#include <iostream>
#include "player.h"
#include "piece.h"
using namespace std;

Player::Player(): dataDownloaded{0}, virusDownloaded{0} {
    vector<Piece> pieces;
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

Player::~Player() {
    // abilities.clear();
    pieces.clear();
    cout << "Player deleted: " << endl;
}

vector<Piece *> Player::getPieces() {
    return pieces;
}

