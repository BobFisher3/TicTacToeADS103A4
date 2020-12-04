#pragma once
#include "iostream"
#include "ctime"
#include "cstdlib"
#include "vector"

using namespace std;

//This class controls the board logic
class TicTacToe
{
    char board[3][3];
    char winner;

public:
    //Constructor
    TicTacToe() { 
        reset(); 
    }

    //Reset - Draws a new board by looping through and drawing spaces
    void resetBoard() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }    
        }
    }

    //Sets winner back to null
    void resetWinner() { winner = ' '; }

    //Call this when a reset is required - saves extra lines of code
    void reset(){
        resetBoard();
        resetWinner();
    }

    //Setters and Getters
    void setChar(char symbol, int i) {
        board[i / 3][i % 3] = symbol; 
    }

    void setChar(char symbol, int i, int j) { 
        board[i][j] = symbol; 
    }

    char getChar(int i) { 
        return board[i / 3][i % 3]; 
    }

    char getChar(int i, int j) { 
        return board[i][j]; 
    }

    char whoWon() { 
        return winner; 
    }

    //Possible Moves - Loops through board and checks which tiles have been filled
    bool isMovePossible() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    return true;
                }
            }
        }
        return false;
    }
    
    //Fills a vector with the possible move locations
    vector<int> allPossibleMoves() {
        vector<int> move_set;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    move_set.push_back(3 * i + j);
                }
            }
        }
        return move_set;
    }

    //Check Winner - Loops through the board and checks if there is 3 of the same symbol in a row
    bool checkWinner(char symbol) {
        //Horizontal Check
        for (int i = 0; i < 3; i++){
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == symbol) {
                return true;
            }
        }

        //Vertical Check
        for (int i = 0; i < 3; i++) {
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == symbol) {
                return true;
            }
        }

        //Diagonal One Check
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] == symbol) {
            return true;
        }   

        //Diagonal Two Check
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] == symbol) {
            return true;
        }
        return false;
    }

    //Do Move
    void doMove(char symbol, int index) {
        int i = index / 3, j = index % 3;
        board[i][j] = symbol;

        if (checkWinner(symbol)) {
            winner = symbol;
        }       
    }

    void printBoard() {
        for (int i = 0; i <= 6; i += 3) {
            cout << "\n " << getChar(i) << " | " << getChar(i + 1) << " | " << getChar(i + 2);
        }
    }
};
