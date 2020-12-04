#pragma once
#include "iostream"
#include "ctime"
#include "cstdlib"
#include "vector"
#include "TicTacToe.h"
#include "Player.h"
#include "HumanPlayer.h"

using namespace std;

struct ttt_move {
    int index;
    long score;
};




class ComputerAI : public Player {
public:
    //Minimax for move decision making
    ttt_move minimax(TicTacToe state, char curr_player) {
        char max_player = this->getSymbol();
        char other_player = (curr_player == 'X') ? 'O' : 'X';
        ttt_move best, current;

        //Base condition for win - lose
        if (state.whoWon() == other_player) {
            best.score = state.allPossibleMoves().size() + 1;
            if (other_player != max_player) {
                best.score = -best.score;
            }    
            return best;
        }
        // base condtion for draw
        if (!state.isMovePossible()) {
            best.score = 0;
            return best;
        }

        if (curr_player == max_player) {
            best.score = -1000000;
        }  
        else {
            best.score = 1000000;
        }

        //Fill a vector with all free moves available
        vector<int> move_set = state.allPossibleMoves();

        //Do move and check next best move
        for (int i = 0; i < move_set.size(); i++) {
            state.doMove(curr_player, move_set[i]);
            current = minimax(state, other_player);
            state.setChar(' ', move_set[i]);
            state.resetWinner();
            current.index = move_set[i];

            if (curr_player == max_player) {
                if (current.score > best.score) {
                    best = current;
                }
            }
            else {
                if (current.score < best.score) {
                    best = current;
                }
            }
        }
        return best;
    };


    //Constructor
    ComputerAI(char s) : Player(s) {}

    //getMove() Over-ride
    int getMove(TicTacToe game) {
        ttt_move move;
        srand(time(0));

        //If computer is starting, pick a random spot
        if (game.allPossibleMoves().size() == 9) {
            move.index = rand() % 9;
        }

        //If not starting, choose the best location
        else {
            move = minimax(game, getSymbol());
        }

        return move.index;
    }
};