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
#include "helper.h"
using namespace std;

int main (int argc, char* argv[]) {
  shared_ptr <Player> player1 = make_shared<Player>();
  shared_ptr <Player> player2 = make_shared<Player>();
  //Player *player1 = new Player();
  //Player *player2 = new Player();
  bool graphics = game_setup(argc, argv, player1, player2);
  shared_ptr <Board> b = make_shared<Board>(player1, player2, 1);
  //Board *b = new Board(player1, player2, 1);
  b->basic_setup();
  shared_ptr <addText> text = make_shared<addText>(b);
  //addText * text = new addText(b);
  shared_ptr <addGraphics> display;
  if (graphics) {
    display = make_shared<addGraphics>(b);
  }
  string command;
  bool ended = false;
  while (cin >> command) {
    if (command == "quit") {
      //cout << "Game is quit" << endl;
      break;
    }
    else if (command == "move") {
      char link;
      string direction;
      cin >> link >> direction;
      //cout << "We want to move link: " << link << " direction: " << direction << endl;
      bool valid = b->movePiece(link, direction);
      if (valid) {
        b->updateCemented();
        b->updateHurricane();
        b->setAbilityUsed(false); 
      }
      if (b->getPlayerTurn() == 1 && valid) {
        b->setTurn(2);
      }
      else if(valid){
        b->setTurn(1);
      }
    }
    else if (command == "abilities") {
      if (b->getPlayerTurn() == 1) {
        player1->printAbilities();
      }
      else {
        player2->printAbilities();
      }
    }
    else if (command == "ability") {
      int ability;
      std::cin >> ability;
      //cout << "Executing ability: " << ability << endl;
      if (!b->useAbility(ability, b->getPlayerTurn())) {
        cout << "Invalid Input: Please Try Again" << endl;
      } else {
        b->setAbilityUsed(true);
      }
    }
    else if (command == "board") {
      b->displayBoard();
    }
    else if (command == "sequence") {
      ended = false;
      string infile;
      cin >> infile;
      ended = readFromFile(infile, b, player1, player2);
      if(ended) break;      
    }
    if (b->seeWinner() == 1){
      cout << "Player 1 has won the game" << endl;
      break;
    }
    else if (b->seeWinner() == 2){
      cout << "Player 1 has won the game" << endl;
      break;
    }
  }
}

