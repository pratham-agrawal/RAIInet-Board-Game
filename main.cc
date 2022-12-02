#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include "board.h"
#include "addText.h"
#include "subject.h"
#include "observer.h"
#include "player.h"
#include "cell.h"
#include <cstring>
#include "piece.h"
using namespace std;

bool readFromFile(string file) {
    ifstream in(file);
    string fileCommand;
    for ( ;; ){
        in >> fileCommand;
        if (in.fail()) return false;
        if (fileCommand == "quit"){
            cout << "Game is quit" << endl;
            return true;
            break;
        }
        else if (fileCommand == "move") {
            char link;
            string direction;
            in >> link >> direction;
            cout << "We want to move link: " << link << " direction: " << direction << endl;
        }
        else if (fileCommand == "abilities") {
            cout << "The abilities are: " << endl;
        }
        else if (fileCommand == "ability") {
            int ability;
            in >> ability;
            cout << "Executing ability: " << ability << endl;
        }
        else if (fileCommand == "board") {
            cout << "Here is the board: " << endl;
        }
    }
}

void setupLinks(string file, Player *player, int playerNum) {
  ifstream in(file);
  string token;
  char ascii;
  if (playerNum == 1) {
    ascii = 'a';
  } else {
    ascii = 'A';
  }
  while (in >> token) {
    bool isVirus = false;
    int strength;
    if (token[0] == 'v' || token[0] == 'V') {
      isVirus = true;
    }
    strength = int(token[1] - '0');
    Piece *p = new Piece(ascii, isVirus, strength, playerNum);
    player->getPieces().emplace_back(p);
    cout << player->getPieces().size() << endl;
    ++ascii;
  }
}

void game_setup(int argc, char* argv[], Player *player1, Player *player2) {
  bool ability1 = false;
  bool ability2 = false;
  bool link1 = false;
  bool link2 = false;
  bool graphics = false;
  string order;
  string placement_file;
  int cmd_line_arg = 1;

  while (cmd_line_arg < argc) {
    if (!strcmp(argv[cmd_line_arg], "-ability1")) {
      ability1 = true;
      ++cmd_line_arg;
      order = argv[cmd_line_arg];
    }
    else if (!strcmp(argv[cmd_line_arg], "-ability2")) {
      ability2 = true;
      ++cmd_line_arg;
      order = argv[cmd_line_arg];
    }
    else if (!strcmp(argv[cmd_line_arg], "-link1")) {
      cout << "link 1" << endl;
      link1 = true;
      ++cmd_line_arg;
      placement_file = argv[cmd_line_arg];
      cout << placement_file << endl;
      setupLinks(placement_file, player1, 1);
    }
    else if (!strcmp(argv[cmd_line_arg], "-link2")) {
      cout << "link 2" << endl;
      link2 = true;
      ++cmd_line_arg;
      placement_file = argv[cmd_line_arg];
      cout << placement_file << endl;
      setupLinks(placement_file, player2, 2);
    }
    else if (!strcmp(argv[cmd_line_arg], "-graphics")) {
      graphics = true;
      // enable graphics
    }
    ++cmd_line_arg;
  }
  if (!ability1) {
    order = "LFDSP";
  }
  if (!ability2) {
    order = "LFDSP";
  }
  if (!link1) {
    // string random = randomize();
  }
  if (!link2) {
    // string random = randomize();
  }
}

int main (int argc, char* argv[]) {
  Player *player1 = new Player();
  Player *player2 = new Player();
  game_setup(argc, argv, player1, player2);
  Board *b = new Board(player1, player2);
  b->basic_setup();
  addText * text = new addText(b);
  string command;
  bool ended = false;
  while (cin >> command) {
    if (command == "quit") {
      cout << "Game is quit" << endl;
      break;
    }
    else if (command == "move") {
      char link;
      string direction;
      cin >> link >> direction;
      cout << "We want to move link: " << link << " direction: " << direction << endl;
      b->movePiece(link, direction);
    }
    else if (command == "abilities") {
      cout << "The abilities are: " << endl;
    }
    else if (command == "ability") {
      int ability;
      std::cin >> ability;
      cout << "Executing ability: " << ability << endl;

    }
    else if (command == "board") {
      cout << "Here is the board: " << endl;
      text->notify();
    }
    else if (command == "sequence") {
      ended = false;
      string infile;
      cin >> infile;
      ended = readFromFile(infile);
      if(ended) break;      
    }
  }
  delete text;
}

