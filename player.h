#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include <map>
#include "piece.h"
#include <iostream>

class Player {
    std::vector<Piece *> pieces;
    int dataDownloaded;
    int virusDownloaded;
    public:
        Player();
        ~Player();
        std::vector<Piece *> getPieces();
        void addPiece(Piece *p);
        void downloadData();
        void downloadVirus();
        int getData();
        int getVirus();
};

#endif