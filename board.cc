#include "board.h"
#include <vector>
#include <memory>
#include <string>
#include "player.h"
#include "piece.h"
using namespace std;

bool Board::getAbilityUsed() {
    return abilityUsed;
}

void Board::setAbilityUsed(bool val) {
    abilityUsed = val;
}


bool Board::useAbility(int ability, int playerNum, istream &in) {
    if (1 > ability || ability > 5) {
        return false;
    }
    if (abilityUsed) {
        return false;
    }
    if (playerNum == 1 && p1->getAbilities().at(ability - 1)->used()) {
        return false;
    }
    else if (playerNum == 2 && p2->getAbilities().at(ability - 1)->used()) {
        return false;
    }
    shared_ptr<Player> player;
    shared_ptr<Player> opponent;
    if (playerNum == 1) {
        player = p1;
        opponent = p2;
    } else if (playerNum == 2) {
        player = p2;
        opponent = p1;
    }
    char token;
    string name = player->getAbilities().at(ability - 1)->getAbility();
    if (!name.compare("Linkboost")) {
        in >> token;
        int index = player->searchToken(token);
        if (index == -1) {
            return false;
        }
        player->getPieces().at(index)->setBoosted(true);
    }
    else if (!name.compare("Firewall")) {
        int row;
        int col;
        in >> row;
        in >> col;
        if (row > 8 || row < 0 || col > 8 || col < 0) {
            return false;
        }
        if (theBoard.at(row).at(col)->isFirewall() || theBoard.at(row).at(col)->isServer() || theBoard.at(row).at(col)->hasPiece()) {
            return false;
        }
        theBoard.at(row).at(col)->setFirewall(playerNum);
    }
    else if (!name.compare("Download")) {
        in >> token;
        int index = opponent->searchToken(token);
        if (index == -1) {
            return false;
        }
        if (opponent->getPieces().at(index)->getUmbrella()) {
            player->getAbilities().at(ability - 1)->usedAbility();
            cout << "Has an umbrella" << endl;
            return true;
        }
        if (opponent->getPieces().at(index)->virus()) {
            player->downloadVirus();
        } else {
            player->downloadData();
        }
        int row = opponent->getPieces().at(index)->getRow();
        int col = opponent->getPieces().at(index)->getCol();
        opponent->getPieces().at(index)->setDownloaded(true);
        theBoard.at(row).at(col)->setPiece(nullptr);
    }
    else if (!name.compare("Scan")) {
        in >> token;
        if (token >= 65 && token <= 72) {
            int index = p2->searchToken(token);
            if (index == -1) {
                return false;
            }
            if (playerNum == 1 && p2->getPieces().at(index)->getUmbrella()) {
                player->getAbilities().at(ability - 1)->usedAbility();
                cout << "Has an umbrella" << endl;
                return true;
            }
            p2->getPieces().at(index)->setVisibility(true);
        } else if (token >= 97 && token <= 104) {
            int index = p1->searchToken(token);
            if (index == -1) {
                return false;
            }
            if (playerNum == 2 && p1->getPieces().at(index)->getUmbrella()) {
                player->getAbilities().at(ability - 1)->usedAbility();
                cout << "Has an umbrella" << endl;
                return true;
            }
            p1->getPieces().at(index)->setVisibility(true);
        }
    }
    else if (!name.compare("Polarize")) {
        in >> token;
        if (token >= 65 && token <= 72) {
            int index = p2->searchToken(token);
            if (index == -1) {
                return false;
            }
            if (playerNum == 1 && p2->getPieces().at(index)->getUmbrella()) {
                player->getAbilities().at(ability - 1)->usedAbility();
                cout << "Has an umbrella" << endl;
                return true;
            }
            p2->getPieces().at(index)->polarize();
        } else if (token >= 97 && token <= 104) {
            int index = p1->searchToken(token);
            if (index == -1) {
                return false;
            }
            if (playerNum == 2 && p1->getPieces().at(index)->getUmbrella()) {
                player->getAbilities().at(ability - 1)->usedAbility();
                cout << "Has an umbrella" << endl;
                return true;
            }
            p1->getPieces().at(index)->polarize();
        }
    }
    else if (!name.compare("Umbrella")) {
        in >> token;
        int index = player->searchToken(token);
        if (index == -1) {
            return false;
        }
        player->getPieces().at(index)->setUmbrella(true);
    }
    else if (!name.compare("Cement")) {
        in >> token;
        int index = opponent->searchToken(token);
        if (index == -1) {
            return false;
        }
        if (opponent->getPieces().at(index)->getUmbrella()) {
            player->getAbilities().at(ability - 1)->usedAbility();
            cout << "Has an umbrella" << endl;
            return true;
        }
        shared_ptr<Piece> p = opponent->getPieces().at(index);
        p->cementPiece();
        cementedPieces.emplace_back(p);
    }
    else if (!name.compare("Hurricane")) {
        //Hurricane
        cout << "HURRICANE WARNING!" << endl;
        int side;
        if (playerNum == 1) {
            side = 4;
            p2->hurricaned();
        } else {
            side = 0;
            p1->hurricaned();
        }
        for (int i = side; i < side + 4; ++i) {
            for (int j = 0; j < 8; ++j) {
                theBoard.at(i).at(j)->setHurricaned(true);
            }
        }

    }
    player->getAbilities().at(ability - 1)->usedAbility();
    return true;
}

void Board::updateHurricane() {
    if (p1->isHurricane()) {
        p1->decreaseHurricane();
    }
    if (p2->isHurricane()) {
        p2->decreaseHurricane();
    }
    if (p1->getHurricaneCount() == 0) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 8; ++j) {
                theBoard.at(i).at(j)->setHurricaned(false);
            }
        }
    }
    if (p2->getHurricaneCount() == 0) {
        for (int i = 4; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                theBoard.at(i).at(j)->setHurricaned(false);
            }
        }
    }
}


Board::Board(shared_ptr <Player> player1, shared_ptr <Player> player2, int playT): p1{player1}, p2{player2}, playerTurn{playT}, abilityUsed{false} {
    //Create empty cells
    for (int i=0; i<8; i++){
        vector<shared_ptr<Cell>> vect;
        theBoard.emplace_back(vect);
        for (int j=0; j<8; ++j) {
            shared_ptr <Cell> temp = make_shared<Cell>(i,j);
            //Cell * temp = new Cell{i,j};
            theBoard.at(i).emplace_back(temp);
			//theBoard.at(i).at(j)->setBoard(this);
		}
	}
    vector<shared_ptr <Piece>> cementedPieces;
}

void Board::basic_setup() {
    //creates servers
    theBoard.at(0).at(3)->setServer(1);
    theBoard.at(0).at(4)->setServer(1);
    theBoard.at(7).at(3)->setServer(2);
    theBoard.at(7).at(4)->setServer(2);

    for (int i = 0; i < 8; ++i) {
        int top = 0;
        int bottom = 7;
        if (i > 2 && i < 5) {
            top = 1;
            bottom = 6;
        }

        //p1->getPieces().at(i)->setBoard(this);
        //p1->getPieces().at(i)->setCell(theBoard.at(top).at(i));
        p1->getPieces().at(i)->setRow(top);
        p1->getPieces().at(i)->setCol(i);
        theBoard.at(top).at(i)->setPiece(p1->getPieces().at(i));

        //p2->getPieces().at(i)->setBoard(this);
        //p2->getPieces().at(i)->setCell(theBoard.at(bottom).at(i));
        p2->getPieces().at(i)->setRow(bottom);
        p2->getPieces().at(i)->setCol(i);
        theBoard.at(bottom).at(i)->setPiece(p2->getPieces().at(i));
    }
}



char Board::getState(int row, int col) const {
    shared_ptr <Cell> current = theBoard.at(row).at(col);
    if (current->isHurricaned()) {
        return '?';
    }
    if (current->hasPiece()){
        return current->getPiece()->getName();
    }
    int fw = current->isFirewall();
    if (fw == 1) {
        return 'm';
    }
    if (fw == 2) {
        return 'w';
    }
    if (current->isServer()){
        return 's';
    }
    return '.';
}

bool Board::movePiece(char name, string direction){
    //Set player and piece
    int player_num = 0;
    shared_ptr <Piece> currentPiece = nullptr;
    shared_ptr <Player> player = nullptr;
    shared_ptr <Player> opponent = nullptr;
    
    if(name >= 65 && name <= 72 && playerTurn == 2){
        currentPiece = p2->getPieces().at(name - 65);
        player_num = 2;
        player = p2;
        opponent = p1;
    } else if (name >= 97 && name <= 104 && playerTurn == 1){
        currentPiece = p1->getPieces().at(name - 97);
        player_num = 1;
        player = p1;
        opponent = p2;
    } else {
        cout << "invalid piece" << endl;
        return false;
    }

    if (currentPiece->getDownloaded()){
        cout << "Piece not on board" << endl;
        return false;
    }

    if (currentPiece->isCemented()) {
        cout << "This is a cemented Piece!" << endl;
        cout << "Please wait " << currentPiece->getCementCount() << " more turns to move piece." << endl;
        return false;
    }

    int oldX = currentPiece->getRow();
    int oldY = currentPiece->getCol();

    //Set target coordinates
    int newX = oldX;
    int newY = oldY;
    //int newX = currentPiece->getRow();
    //int newY = currentPiece->getCol();
    int moveAmount = 1 + currentPiece->getBoosted();
    //cout << currentPiece->getBoosted() << moveAmount << endl;
    if (direction == "up") {
        //newX --;
        newX -= moveAmount;
    }
    else if (direction == "down") {
        //newX ++;
        newX += moveAmount;
    }
    else if (direction == "left") {
        //newY --;
        newY -= moveAmount;
    }
    else if (direction == "right") {
        //newY ++;
        newY += moveAmount;
    }
    else {
        cout << "Invalid direction" << endl;
        return false;
    }

    //Check if moving off board
    if ((player_num == 1 && newX == 8) || (player_num == 2 && newX == -1)){
        cout << "Downloading own link" << endl;
        //REVEAL?
        if (currentPiece->virus()){
            player->downloadVirus();
        }
        else {
            player->downloadData();
        }
        currentPiece->setDownloaded(true);
        theBoard.at(oldX).at(oldY)->setPiece(nullptr);
        return true;
    }

    if (newX < 0 || newX > 7 || newY < 0 || newY > 7){
        cout << "Attempting to move off board" << endl;
        return false;
        //throw ();
    }

    shared_ptr <Cell> targetCell = theBoard.at(newX).at(newY);
    
    //Check if server
    if (targetCell->isServer()) {
        if (targetCell->isServer() == player_num){
            cout << "Attempting to move onto own server" << endl;
            return false;
            //throw();
        }
        else {
            cout << "Oponents server downloaded your link" << endl;
            if (currentPiece->virus()){
                opponent->downloadVirus();
            }
            else {
                opponent->downloadData();
            }
            currentPiece->setDownloaded(true);
            theBoard.at(oldX).at(oldY)->setPiece(nullptr);
            return true;
        }
    }


    //Check if moving to square with piece
    if (targetCell->hasPiece()){
        if (targetCell->hasPiece() == player_num){
            cout << "Attempting to move to square with own piece" << endl;
            return false;
            //throw ();
        }
        else {
            if (currentPiece->getStrength() >= targetCell->getPiece()->getStrength()){
                cout << "Your strength higher" << endl;
                if (targetCell->getPiece()->virus()){
                    player->downloadVirus();
                }
                else {
                    player->downloadData();
                }
                currentPiece->setVisibility(true);
                targetCell->getPiece()->setVisibility(true);
                targetCell->getPiece()->setDownloaded(true);
                targetCell->setPiece(nullptr);
                //remove from player?? set downloaded to true??
            }
            else {
                cout << "Your strength weaker" << endl;
                if (currentPiece->virus()){
                    opponent->downloadVirus();
                }
                else {
                    opponent->downloadData();
                }
                currentPiece->setVisibility(true);
                targetCell->getPiece()->setVisibility(true);
                theBoard.at(oldX).at(oldY)->setPiece(nullptr);
                return true;
                // remove from player?? set downloaded to true??
            }
        }
    }
    
    //move piece
    targetCell->setPiece(currentPiece);
    currentPiece->setRow(newX);
    currentPiece->setCol(newY);
    theBoard.at(oldX).at(oldY)->setPiece(nullptr);

    //Check if firewall
    if (targetCell->isFirewall() && targetCell->isFirewall() != player_num) {
        currentPiece->setVisibility(true);
        if (currentPiece->virus()){
            player->downloadVirus();
            targetCell->getPiece()->setDownloaded(true);
            targetCell->setPiece(nullptr);
        }
    }
    return true;
}

void Board::updateCemented() {
    for (int i = 0; i < cementedPieces.size(); ++i) {
        cementedPieces.at(i)->decreaseCement();
        if (cementedPieces.at(i)->getCementCount() == 0) {
            cementedPieces.erase(cementedPieces.begin() + i);
        }
    }
}

shared_ptr <Player> Board::getP1(){
    return p1;
}

shared_ptr <Player> Board::getP2(){
    return p2;
}

int Board::getPlayerTurn(){
    return playerTurn;
}

void Board::setTurn(int turn){
    playerTurn = turn;
}

void Board::displayBoard(){
    notifyObservers();
}

int Board::seeWinner(){
    if (p1->getData() == 4 || p2->getVirus() == 4){
        return 1;
    }
    else if (p2->getData() == 4 || p1->getVirus() == 4){
        return 2;
    }
    return 0;
}
