#include <string>
#include <vector>
#include <iostream>
#include "player.h"
#include "piece.h"
#include <algorithm>
#include <random>
#include <cstring>
using namespace std;

Player::Player(): dataDownloaded{0}, virusDownloaded{0} {
    vector<Piece *> pieces;
    vector<char> abilities;
    vector<char> usedAbilities;
}

void Player::addPiece(Piece *p) {
    pieces.emplace_back(p);
}

Player::~Player() {
    abilities.clear();
    pieces.clear();
    cout << "Player deleted: " << endl;
}

vector<Piece *> Player::getPieces() {
    return pieces;
}

vector<Ability *> Player::getAbilities() {
    return abilities;
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

void Player::addAbility(string ability, int id) {
    Ability *a = new Ability(ability, id);
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

void Player::useAbility(int ability) {
    char token;
    string name = abilities.at(ability - 1)->getAbility();
    if (!name.compare("Linkboost")) {
        cin >> token;
        int index = 0;
        while (index < 5) {
            if (pieces.at(index)->getName() == token) {
                break;
            }
            ++index;
        }
        pieces.at(index)->setBoosted(true);
    }
    else if (!name.compare("Firewall")) {
        //firewall
    }
    else if (!name.compare("Download")) {
        //download
    }
    else if (!name.compare("Scan")) {
        //scan
    }
    else if (!name.compare("Polarize")) {
        //polarize
    }
    abilities.at(ability - 1)->usedAbility();
}

