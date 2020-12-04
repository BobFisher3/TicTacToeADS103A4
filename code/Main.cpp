#include "iostream"
#include "ctime"
#include "cstdlib"
#include "vector"
#include "TicTacToe.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerAI.h"

using namespace std;

//Game engine  
void play(TicTacToe game, Player* x_player, Player* o_player) {
    char letter = 'X';
    int index;
    game.reset();
    //When user enters inout, checks to see if space is taken
    while (game.isMovePossible()) {
        if (letter == 'O') {
            index = o_player->getMove(game);
        }

        else {
            index = x_player->getMove(game);
        }
        game.doMove(letter, index);
        cout << endl;
        //Prints out the move played
        cout<< letter << " makes move to " << index + 1 << endl;
        //Redraw board after move
        game.printBoard();
        cout << endl;

        //Checks to see if there is a winner after a move
        if (game.checkWinner(letter))
        {
            cout << endl;
            cout << letter << " wins !";
            return;
        }

        letter = (letter == 'X') ? 'O' : 'X';
    }
    //If all moves are made and there is no win condition, decide draw
    cout<< endl;
    cout<< "Draw";
}
int main() {
    TicTacToe game;

    char ch;
    int mode;

    HumanPlayer x_human('P1');
    HumanPlayer o_human('P2');
    ComputerAI x_AI('C1');
    ComputerAI o_AI('C2');

    Player* x = nullptr;
    Player * o = nullptr;

    //Display option for game mode and get user input. Options for play going first and 2nd as well as 2 player mode
    do {
        cout << endl;
        cout << "Select game mode :" << endl;
        cout<< "1. Human v/s Human" << endl;
        cout<< "2. Human v/s Computer" << endl;
        cout<< "3. Computer v/s Human" << endl;
        cout<< "4. Computer v/s Computer" << endl;
        cout<< endl;
        cout<< "Mode : ";
        cin >> mode;

        //Sets the mode to be played
        switch (mode) {
        case 1:
            x = &x_human;
            o = &o_human;
            break;

        case 2:
            x = &x_human;
            o = &o_AI;
            break;

        case 3:
            x = &x_AI;
            o = &o_human;
            break;

        case 4:
            x = &x_AI;
            o = &o_AI;
            break;

        //Error if invalid selection
        default:
            cout << "Wrong choice";
        }

        play(game, x, o);

        //Ask if user wants to play again
        cout << endl;
        cout<< "Play again (y/n) : ";
        cin >> ch;

    } while (ch == 'y' || ch == 'Y');

    //If player does not select y, game will exit
    return 0;
}