#include <string>
#include <vector>
#include <iostream>
#include "player.h"
#include "piece.h"
#include "ability.h"
#include <algorithm>
#include <random>
using namespace std;

Ability::Ability(string ability, int id): ability{ability}, id{id}, beenUsed{false} {}

Ability::~Ability() {}

string Ability::getAbility() {
    return ability;
}

int Ability::getId() {
    return id;
}

void Ability::usedAbility() {
    beenUsed = true;
}

bool Ability::used() {
    return beenUsed;
}

