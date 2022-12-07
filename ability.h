#ifndef ABILITY_H
#define ABILITY_H
#include <string>
#include <vector>
#include "piece.h"
#include "player.h"
#include <iostream>

class Ability {
    std::string ability;
    int id;
    bool beenUsed;
    public:
        Ability(std::string ability, int id);
        ~Ability();
        bool used();
        void usedAbility();
        int getId();
        std::string getAbility();
};

#endif
