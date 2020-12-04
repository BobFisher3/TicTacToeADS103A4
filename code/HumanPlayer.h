#pragma once
#include "iostream"
#include "ctime"
#include "cstdlib"
#include "vector"
#include "TicTacToe.h"
#include "Player.h"

using namespace std;

class HumanPlayer : public Player {
public:
    //Constructor
    HumanPlayer(char s) : Player(s) {}

    //GetMove() over-ride
    int getMove(TicTacToe game) {
        int index;
        while (1) {
            cout << "\nEnter index: ";
            cin >> index;

            if (game.getChar(index - 1) == ' ') {
                return index - 1;
            }      

            //Error if invalid move
            cout << "Wrong Move";
        }
    }
};