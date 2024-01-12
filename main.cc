#include <string>
#include <iostream>
#include "board.h"

using namespace std;

int main() {

    Board gameBoard;

    while(1) {
        cout << "Player " << gameBoard.getPlayer() << " Is playing" << endl;
        cout << "Enter the coordinates where you want to place your peice: ";

        // Placing peice at given coordinates
        int i, j;
        cin >> i >> j;
        gameBoard.placePeice(i, j);

        cout << gameBoard;

        // If the player has won
        if (gameBoard.checkForWin()) {
            cout << "Player " << gameBoard.getPlayer() << " Has won!" << endl;
            break;
        }

        // If the game board is full
        if (gameBoard.isFull()) {
            cout << "We have a draw!" << endl;
            break;
        }

        gameBoard.switchTurn();
    }
    
}