#include "helper.h"
using namespace std;

bool readFromFile(string file, shared_ptr <Board> b, shared_ptr <Player> player1, shared_ptr <Player> player2) {
    ifstream in(file);
    string fileCommand;
    for ( ;; ){
        in >> fileCommand;
        //cout << fileCommand;
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
        else if (fileCommand == "abilities") {
          if (b->getPlayerTurn() == 1) {
            player1->printAbilities();
          }
          else {
            player2->printAbilities();
          }
        }
        else if (fileCommand == "ability") {
            int ability;
            in >> ability;
            //cout << "Executing ability: " << ability << endl;
            if (!b->useAbility(ability, b->getPlayerTurn(), in)) {
              cout << "Invalid Input: Please Try Again" << endl;
            } else {
              b->setAbilityUsed(true);
          }
        }
        else if (fileCommand == "board") {
            b->displayBoard();
        }
        if (b->seeWinner() == 1){
        cout << "Player 1 has won the game" << endl;
        return true;
        break;
        }
        else if (b->seeWinner() == 2){
        cout << "Player 1 has won the game" << endl;
        return true;
        break;
        }
    }
    return false;
}

string charToAbility(char c) {
  if (c == 'L') {
      return "Linkboost";
  }
  else if (c == 'F') {
      return "Firewall";
  }
  else if (c == 'D') {
      return "Download";
  }
  else if (c == 'S') {
      return "Scan";
  }
  else if (c == 'P') {
    return "Polarize";
  }
  else if (c == 'C') {
    return "Cement";
  }
  else if (c == 'U') {
    return "Umbrella";
  }
  else if (c == 'H') {
    return "Hurricane";
  }
  else {
    cout << "Ability not found: " << c << endl;
    exit(1);
  }
}

void setupLinks(string file, shared_ptr <Player> player, int playerNum) {
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
    shared_ptr <Piece> p = make_shared<Piece>(ascii, token, isVirus, strength, playerNum);;
    //Piece *p = new Piece(ascii, token, isVirus, strength, playerNum);
    // cout << "Piece Created: This is my strength: " << p->getStrength() << endl;
    player->addPiece(p);
    ++ascii;
  }
}

bool game_setup(int argc, char* argv[], std::shared_ptr <Player> player1, std::shared_ptr <Player> player2) {
  bool ability1 = false;
  bool ability2 = false;
  bool link1 = false;
  bool link2 = false;
  bool graphics = false;
  string order;
  char ability;
  string word;
  string placement_file;
  int cmd_line_arg = 1;

  while (cmd_line_arg < argc) {
    if (!strcmp(argv[cmd_line_arg], "-ability1")) {
      ability1 = true;
      ++cmd_line_arg;
      order = argv[cmd_line_arg];
      for (int i = 0; i < 5; ++i) {
        ability = order[i];
        word = charToAbility(ability);
        player1->addAbility(word, i + 1);
      }
    }
    else if (!strcmp(argv[cmd_line_arg], "-ability2")) {
      ability2 = true;
      ++cmd_line_arg;
      order = argv[cmd_line_arg];
      for (int i = 0; i < 5; ++i) {
        ability = order[i];
        word = charToAbility(ability);
        player2->addAbility(word, i + 1);
      }
    }
    else if (!strcmp(argv[cmd_line_arg], "-link1")) {
      link1 = true;
      ++cmd_line_arg;
      placement_file = argv[cmd_line_arg];
      setupLinks(placement_file, player1, 1);
    }
    else if (!strcmp(argv[cmd_line_arg], "-link2")) {
      link2 = true;
      ++cmd_line_arg;
      placement_file = argv[cmd_line_arg];
      setupLinks(placement_file, player2, 2);
    }
    else if (!strcmp(argv[cmd_line_arg], "-graphics")) {
      graphics = true;
    }
    ++cmd_line_arg;
  }
  if (!ability1) {
    order = "LFDSP";
    for (int i = 0; i < 5; ++i) {
      ability = order[i];
      word = charToAbility(ability);
      player1->addAbility(word, i + 1);
    }
  }
  if (!ability2) {
    order = "LFDSP";
    for (int i = 0; i < 5; ++i) {
      ability = order[i];
      word = charToAbility(ability);
      player2->addAbility(word, i + 1);
    }
  }
  if (!link1) {
    bool isVirus = false;
    char ascii = 'a';
    string token;
    vector<string> links = {"D1", "D2", "D3", "D4", "V1", "V2", "V3", "V4"};
    for (int j = 0; j < 4; ++j) {
      shared_ptr <Piece> p = make_shared<Piece>(ascii + j, links.at(j), isVirus, j + 1, 1);
      //Piece *p = new Piece(ascii + j, links.at(j), isVirus, j + 1, 1);
      player1->addPiece(p);
    }
    isVirus = true;
    for (int i = 4; i < 8; ++i) {
      shared_ptr <Piece> p = make_shared<Piece>(ascii + i, links.at(i), isVirus, i - 3, 1);
      //Piece *p = new Piece(ascii + i, links.at(i), isVirus, i - 3, 1);
      player1->addPiece(p);
    }
    player1->shufflePieces(1);
  }
  if (!link2) {
    bool isVirus = false;
    char ascii = 'A';
    string token;
    vector<string> links = {"D1", "D2", "D3", "D4", "V1", "V2", "V3", "V4"};
    for (int j = 0; j < 4; ++j) {
      shared_ptr <Piece> p = make_shared<Piece>(ascii + j, links.at(j), isVirus, j + 1, 2);
      //Piece *p = new Piece(ascii + j, links.at(j), isVirus, j + 1, 2);
      player2->addPiece(p);
    }
    isVirus = true;
    for (int i = 4; i < 8; ++i) {
      shared_ptr <Piece> p = make_shared<Piece>(ascii + i, links.at(i), isVirus, i - 3, 2);
      //Piece *p = new Piece(ascii + i, links.at(i), isVirus, i - 3, 2);
      player2->addPiece(p);
    }
    player2->shufflePieces(2);
  }
  return graphics;
}
