#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include <map>
#include "piece.h"
#include <iostream>
#include <memory>

class Player {
    std::vector<std::shared_ptr <Piece>> pieces;
    int dataDownloaded;
    int virusDownloaded;
    std::vector<char> abilities;
    public:
        Player();
        ~Player();
        std::vector<std::shared_ptr <Piece>> getPieces();
        void addPiece(std::shared_ptr <Piece>);
        void downloadData();
        void downloadVirus();
        int getData();
        int getVirus();
        std::vector<char> getAbilities();
        void shufflePieces(int playerNum);
};

#endif