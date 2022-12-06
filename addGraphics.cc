#include <iostream>
#include <string>
#include "observer.h"
#include "board.h"
#include "addGraphics.h"
#include "window.h"

using namespace std;

addGraphics::addGraphics(shared_ptr<Board> s): subject{s}{
  subject->attach(this);
  //window = new Xwindow(200, 200);
  window = make_shared<Xwindow>(700, 850);

}

addGraphics::~addGraphics() {
  subject->detach(this);
  //delete window;
}

void addGraphics::notify() {
  window->fillRectangle(0, 0, 700, 850, 0);
  shared_ptr<Player> p1 = subject->getP1();
  shared_ptr<Player> p2 = subject->getP2();
  window->drawString(20, 20, "Player 1:");
  window->drawString(20, 40, "Downloaded: " + to_string(p1->getData()) + "D, " + to_string(p1->getVirus()) + "V");
  window->drawString(20, 60, "Abilities: " + to_string(p1->abilityCount()));
  int nextline = 0;
  int spacer = 0;
  for (int i = 0; i < 8; i++){
    string s(1, char(i+97));
    window->drawString(20 + spacer * 30, 80 + nextline*20, s + ": ");
    //cout << char(i+97) << ": ";
    if(subject->getPlayerTurn() == 1 || p1->getPieces().at(i)->getVisibility()){ 
      //cout << p1->getPieces().at(i)->getLinkName();
      window->drawString(35 + spacer * 30, 80 + nextline*20, p1->getPieces().at(i)->getLinkName());
    } else{
      //cout << '?';
      window->drawString(35 + spacer * 30, 80 + nextline*20, "?");
    }
    if (i == 3){
      nextline = 1;
      spacer = -1;
    }
    spacer++;
  }
  window->drawRectangle(19, 119, 561, 561);
  int locationX = 20;
  int locationY = 120;
  for (int i = 0; i < 8; i++){
    if (i % 2 == 0){
      locationX = 90;
    } else{
      locationX = 20;
    }
    for (int x = 0; x < 4; x++){
        window->fillRectangle((locationX + x*140), (locationY + i*70), 70, 70, 9);
    }
  }

  locationX = 35;
  locationY = 135;

  for (int i = 0; i < 8; i++){
    for (int x = 0; x < 8; x++){
      char current = subject->getState(i,x);
      if (current == '.') continue;
      else if(current == 'm') {
        window->fillRectangle(locationX + x*70, locationY + i*70, 40, 40, 7);
      } else if(current == 'w') {
        window->fillRectangle(locationX + x*70, locationY + i*70, 40, 40, 8);
      } else if (current == '?') {
        string letter(1, current);
        window->fillRectangle(locationX + x*70, locationY+ i*70, 40, 40, 5);
        window->drawString( 18 + locationX + x*70, 20 + locationY + i*70, letter);
      } else if(current == 's') {
        window->fillRectangle(locationX + x*70, locationY + i*70, 40, 40, 1);
      } else if(current >= 65 && current <= 72){
        string letter(1, current);
        window->fillRectangle(locationX + x*70, locationY + i*70, 40, 40, 2);
        window->drawString( 18 + locationX + x*70, 20 + locationY + i*70, letter);
      } else{
        string letter(1, current);
        window->fillRectangle(locationX + x*70, locationY + i*70, 40, 40, 4);
        window->drawString( 18 + locationX + x*70, 20 + locationY + i*70, letter);
      }
      }
    }

  window->drawString(20, 700, "Player 2:");
  window->drawString(20, 720, "Downloaded: " + to_string(p2->getData()) + "D, " + to_string(p2->getVirus()) + "V");
  window->drawString(20, 740, "Abilities: " + to_string(p2->abilityCount()));
  nextline = 0;
  spacer = 0;
  for (int i = 0; i < 8; i++){
    string s(1, char(i+65));
    window->drawString(20 + spacer * 30, 760 + nextline*20, s + ": ");
    //cout << char(i+97) << ": ";
    if(subject->getPlayerTurn() == 2 || p2->getPieces().at(i)->getVisibility()){ 
      //cout << p1->getPieces().at(i)->getLinkName();
      window->drawString(35 + spacer * 30, 760 + nextline*20, p2->getPieces().at(i)->getLinkName());
    } else{
      //cout << '?';
      window->drawString(35 + spacer * 30, 760 + nextline*20, "?");
    }
    if (i == 3){
      nextline = 1;
      spacer = -1;
    }
    spacer++;
  }
  /*
 for (int j = top; j <= bottom; ++j){
     for (int i = left; i <= right; ++i){
         char current = subject->getState(j,i);
         int locationY = (j - top) * 10;
         int locationX = (i - left) * 10;
         if (current >= 97 && current <= 122){
               window->fillRectangle(locationX, locationY, 10, 10, 2);
         } else if (current >= 65 && current <= 90){
            window->fillRectangle(locationX, locationY, 10, 10, 3);
         } else if (current >= 48 && current <= 57){
            window->fillRectangle(locationX, locationY, 10, 10, 4);
         } else if (current == 32){
            window->fillRectangle(locationX, locationY, 10, 10, 0);
         } else {
             window->fillRectangle(locationX, locationY, 10, 10, 1);
         }
     }
 }
 */
}


