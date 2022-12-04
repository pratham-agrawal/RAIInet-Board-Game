#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include <map>
#include "piece.h"
#include "ability.h"
#include <iostream>
#include <cstring>

class Player {
    std::vector<Piece *> pieces;
    int dataDownloaded;
    int virusDownloaded;
    std::vector<Ability *> abilities;
    public:
        Player();
        ~Player();
        std::vector<Piece *> getPieces();
        std::vector<Ability *> getAbilities();
        int abilityCount();
        void addPiece(Piece *p);
        void downloadData();
        void downloadVirus();
        int getData();
        int getVirus();
        void addAbility(std::string ability, int id);
        void useAbility(int ability);
        void shufflePieces(int playerNum);
        void printAbilities();
};

#endif