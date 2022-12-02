#include <iostream>
#include <string>
#include "observer.h"
#include "board.h"
#include "addText.h"
using namespace std;

addText::addText(Board *s): subject{s} {
  subject->attach(this);
}

addText::~addText() {
  subject->detach(this);
}

void addText::notify() {
  cout << "Player " << ":" << endl;
  cout << "Downloaded: " << ", " << endl;
  cout << "Abilities: " << endl;
  cout << "a: " << "b: " << "c: " << "d: " << endl;
  cout << "e: " << "f: " << "g: " << "h: " << endl;
  cout << "========" << endl;
  for (int i = 0; i < 8; ++i){
      for (int j = 0; j < 8; ++j){
          cout << subject->getState(i,j);
      }
      cout << endl;
  }
  cout << "========" << endl;
  cout << "Player " << ":" << endl;
  cout << "Downloaded: " << ", " << endl;
  cout << "Abilities: " << endl;
  cout << "A: " << "B: " << "C: " << "D: " << endl;
  cout << "E: " << "F: " << "G: " << "H: " << endl;
}


