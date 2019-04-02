//###################################################
//##########Yehonatan Shaag 308357953################
//##########Johann Thuillier 336104120 ################
//###################################################

#include "Game.h"

using namespace std;

Game::Game() {
    direction = true;
    gameOver = false;
    turn = 0;
    cout<<"how many players?\n";
    cin>>num_Of_Players;
    if(num_Of_Players<0){
        cout<<"illegal operation"<<endl;
        exit(0);
    }
    cout<<"how many cards?\n";
    cin>>num_Of_Cards;
    if(num_Of_Cards<0){
        cout<<"illegal operation"<<endl;
        exit(0);
    }
    for (int i=1; i<=num_Of_Players; i++) {
        string name;
        cout<<"player number "<<i<<" name?\n";
        cin>>name;
        Player player(name,num_Of_Cards);
        Game::players.push_back(player);
    }
    current_card = Card::generate_card();
    current_player = &players[turn];
}

void Game::start(){
    while (!gameOver) {
        printTurnOption();
        bool flag = current_player->play(current_card);
        if(current_player->getNum_of_cards()==0) gameOver = true;
        else nextTurn(flag);
    }
    cout<<*current_player<<" wins!"<<endl;
}

void Game::printTurnOption(){
    cout<<"current: "<<current_card<<endl;
    cout<<*current_player<<", your turn-"<<endl<<"Your cards: ";
    for(int i=0;i<current_player->getCards().size();i++){
        cout<<"("<<i+1<<")"<<current_player->getCards()[i]<<" ";
    }
    cout<<endl;
}

void Game::nextTurn(bool flag){
    if(flag){
        switch (current_card.get_sign()) {
            case sign::STOP:
                if (direction) turn = (turn + 2) % players.size();
                else turn = (turn + players.size() - 2) % players.size();
                break;
                
            case sign::CD:
                direction = !direction;
                if (direction) turn = (turn + 1) % players.size();
                else turn = (turn + players.size() - 1) % players.size();
                break;
                
            case sign::PLUS:
                return;
                break;
                
            default:
                if (direction) turn = (turn + 1) % players.size();
                else turn = (turn + players.size() - 1) % players.size();
                break;
        }
    }
    else {
        if (direction) turn = (turn + 1) % players.size();
        else turn = (turn + players.size() - 1) % players.size();
    }
    current_player = &players[turn];
}













