#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include "board.h"
#include "addText.h"
#include "addGraphics.h"
#include "subject.h"
#include "observer.h"
#include "player.h"
#include "cell.h"
#include <cstring>
#include "ability.h"
#include "piece.h"
#include <random>
#include <algorithm>

bool readFromFile(std::string file, std::shared_ptr <Board> b, std::shared_ptr <Player> player1, std::shared_ptr <Player> player2);

std::string charToAbility(char c);

void setupLinks(std::string file, std::shared_ptr <Player> player, int playerNum);

bool game_setup(int argc, char* argv[], std::shared_ptr <Player> player1, std::shared_ptr <Player> player2);

#endif