#pragma once
#include "iostream"
#include "ctime"
#include "cstdlib"
#include "vector"
#include "TicTacToe.h"

using namespace std;

class Player {
    char symbol;

public:
    //Constructor
    Player(char s) { 
        symbol = s; 
    }

    //Getter
    char getSymbol() { 
        return symbol; 
    }

    //Virtual Function
    virtual int getMove(TicTacToe game) = 0;
};