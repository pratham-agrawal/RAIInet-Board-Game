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

void Player::addPiece(shared_ptr <Piece> p) {
    pieces.emplace_back(p);
}

vector<shared_ptr <Ability>> Player::getAbilities() {
    return abilities;
}

Player::~Player() {
    abilities.clear();
    pieces.clear();
}

vector<shared_ptr <Piece>> Player::getPieces() {
    return pieces;
}

void Player::downloadData(){
    ++dataDownloaded;
}

void Player::downloadVirus(){
    ++virusDownloaded;
}

int Player::getData() {
    return dataDownloaded;
}

int Player::getVirus() {
    return virusDownloaded;
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

int Player::searchToken(char c) {
    int index = 0;
    while (index < 8) {
        if (pieces.at(index)->getName() == c) {
            return index;
        }
        ++index;
    }
    return -1;
}

void Player::addAbility(string ability, int id) {
    shared_ptr <Ability> a = make_shared<Ability>(ability, id);
    abilities.push_back(a);
}

int Player::abilityCount() {
    int count = 5;
    for (int i = 0; i < 5; ++i) {
        if (abilities.at(i)->used()) {
            --count;
        }
    }
    return count;
}

void Player::printAbilities() {
    for (int i = 0; i < 5; ++i) {
        cout << "ID: " << abilities.at(i)->getId() << endl;
        cout << "Ability: " << abilities.at(i)->getAbility() << endl;
        bool used = abilities.at(i)->used();
        if (used) {
            cout << "This ability card has been used." << endl;
        }
        else {
            cout << "This ability card has not yet been used." << endl;
        }
    }
}
