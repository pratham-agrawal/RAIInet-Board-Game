#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include "board.h"
#include "addText.h"
#include "subject.h"
#include "observer.h"
#include "cell.h"
using namespace std;

bool readFromFile(string file){
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


int main () {
  Board b;
  b.basic_setup();
  addText * text = new addText(&b);
  
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

