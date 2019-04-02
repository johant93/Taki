//###################################################
//##########Yehonatan Shaag 308357953################
//##########Johann Thuillier 336104120 ################
//###################################################

    #ifndef GAME_H
    #define GAME_H
    #include "Player.h"
    #include "Card.h"
    #include <vector>

    class Game {
        
    private: //private members and functions

        std::vector<Player> players;
        bool direction;
        Player* current_player;
        Card current_card;
        bool gameOver;
        int num_Of_Players;
        int num_Of_Cards;
        int turn;

    public: //public members and functions
        
        
        Game(); //constructor
        void start();
        void setGameOver(bool gameOver);
        void printTurnOption();
        void nextTurn(bool flag);

    };
    #endif




