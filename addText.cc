#include <iostream>
#include <string>
#include "observer.h"
#include "board.h"
#include "addText.h"
#include "ability.h"
using namespace std;

addText::addText(shared_ptr<Board> s): subject{s} {
  subject->attach(this);
}

addText::~addText() {
  subject->detach(this);
}

void addText::notify() {
  shared_ptr<Player> p1 = subject->getP1();
  shared_ptr<Player> p2 = subject->getP2();
  cout << "Player " << "1" << ":" << endl;
  cout << "Downloaded: " << p1->getData() << "D, " << p1->getVirus() << "V" << endl;
  cout << "Abilities: " << p1->abilityCount() << endl;
  for (int i = 0; i < 8; i++) {
    cout << p1->getPieces().at(i)->getName() << ": ";
    if(subject->getPlayerTurn() == 1 || p1->getPieces().at(i)->getVisibility()){ 
      cout << p1->getPieces().at(i)->getLinkName();
    } else{
      cout << '?';
    }
    cout << " ";
    if (i == 3){
      cout << endl;
    }
  }
  cout << endl;
  //cout << "a: " << "b: " << "c: " << "d: " << endl;
  //cout << "e: " << "f: " << "g: " << "h: " << endl;
  cout << "========" << endl;
  for (int i = 0; i < 8; ++i){
      for (int j = 0; j < 8; ++j) {
          cout << subject->getState(i,j);
      }
      cout << endl;
  }
  cout << "========" << endl;
  cout << "Player " << "2" << ":" << endl;
  cout << "Downloaded: " << p2->getData() << "D, " << p2->getVirus() << "V" << endl;
  cout << "Abilities: " << p2->abilityCount() << endl;
  for (int i = 0; i < 8; i++){
    cout << p2->getPieces().at(i)->getName() << ": ";
    if(subject->getPlayerTurn() == 2 || p2->getPieces().at(i)->getVisibility()){ 
      cout << p2->getPieces().at(i)->getLinkName();
    } else{
      cout << '?';
    }
    cout << " ";
    if (i == 3){
      cout << endl;
    }
  }
  cout << endl;
  //cout << "A: " << "B: " << "C: " << "D: " << endl;
  //cout << "E: " << "F: " << "G: " << "H: " << endl;
}


