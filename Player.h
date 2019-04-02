#ifndef PLAYER_H
#define PLAYER_H

#include <string>
//###################################################
//##########Yehonatan Shaag 308357953################
//##########Johann Thuillier 336104120 ################
//###################################################

#include <iostream>
#include <random>
#include "Card.h"

using namespace std;
class Player {
private:
    string name;
    int num_of_cards;
    vector<Card> cards;
    void generateCards();

public:
    
    int getNum_of_cards() const;
    bool play(Card&);
    int checkChoice(int choice,Card& card);
    const vector<Card> &getCards() const;
    
    //constructor
    Player(const Player&);
    Player(string name,int numCards);
    friend ostream& operator<<(ostream& os, const Player& player);
    Player& operator=(const Player& other);
    
};
#endif



