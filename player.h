#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include <map>
#include "piece.h"
#include "ability.h"
#include <iostream>
#include <memory>
#include <cstring>

class Player {
    std::vector<std::shared_ptr <Piece>> pieces;
    int dataDownloaded;
    int virusDownloaded;
    std::vector<std::shared_ptr <Ability>> abilities;
    bool hurricane;
    int hurricaneCounter;
    public:
        Player();
        ~Player();
        std::vector<std::shared_ptr <Piece>> getPieces();
        void addPiece(std::shared_ptr <Piece>);
        std::vector<std::shared_ptr <Ability>> getAbilities();
        void setPieces(std::vector<std::shared_ptr <Piece>> p);
        int abilityCount();
        void downloadData();
        void downloadVirus();
        int getData();
        int getVirus();
        void addAbility(std::string ability, int id);
        void printAbilities();
        int searchToken(char c);
        void shufflePieces(int playerNum);
        bool isHurricane();
        void hurricaned();
        void decreaseHurricane();
        int getHurricaneCount();
};

#endif