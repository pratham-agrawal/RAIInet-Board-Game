#include <iostream>
#include <vector>
#include <memory>
using namespace std;

int main () {
  string command;

  while (cin >> command) {
    if (command == "quit" ) {
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

    }
    else if (command == "sequence") {
      string file;
      cin >> file;
      cout << "Executing action from file: " << file << endl;
    }
  }
}

