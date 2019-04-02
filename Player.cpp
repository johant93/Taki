//###################################################
//##########Yehonatan Shaag 308357953################
//##########Johann Thuillier 336104120 ################
//###################################################

#include "Player.h"

using namespace std;

Player::Player(const Player& other){
    this->name = other.name;
    this->num_of_cards = other.getNum_of_cards();
    this->cards = other.cards;
}

Player::Player(string name, int num_of_cards){
    Player::name = name;
    Player::num_of_cards = num_of_cards;
    Player::generateCards();
}

void Player::generateCards(){
    for (int i=0; i<num_of_cards; i++)
        cards.push_back(Card::generate_card());
}

Player& Player::operator=(const Player& other){
    if (this!= &other) {
        this->num_of_cards = other.num_of_cards;
        this->name = other.name;
        this->cards = other.cards;
    }
 return *this;
}

ostream& operator<<(ostream& os,const Player& player){
    os << player.name ;
    return os;
}

const vector<Card> &Player::getCards() const {
    return cards;
}

int Player::checkChoice(int choice, Card& card) {
    if (choice>this->num_of_cards||choice<1) return 3;
    else{
        if(card.is_legal(this->getCards()[choice-1])) return 1;
        return 2;
    }
}

bool Player::play(Card & card){
    int choice = 0, action = 2;
    while(action==2){
        cin >> choice;
        action = checkChoice(choice, card);
        if (action==2)
           cout<<"You can't put "<<this->getCards()[choice-1]<<" on "<<card<<endl;
    }
    if (action==1) {
        card = this->getCards()[choice-1];
        cards.erase(cards.begin()+choice-1);
        num_of_cards = getCards().size();
        return true;
    }
    else {
        cards.push_back(Card::generate_card());
        num_of_cards = getCards().size();
        return false;
    }
}

int Player::getNum_of_cards() const {
    return num_of_cards;
}






