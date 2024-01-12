#ifndef BOARD_H
#define BOARD_H

#include <iostream>

class Board {
private:
    char board[3][3];
    char player;

public:
    Board();  // Constructor

    // Places the players peice in the ith row and jth coloumn; (0, 0) is top left
    void placePeice(int i, int j);

    // Switches turns
    void switchTurn();

    // Checks if a player has won
    bool checkForWin();

    // Checks if a board is full
    bool isFull();

    // Returns the current player (X or O)
    char getPlayer();

    // Outputs the current state of the board
    friend std::ostream& operator<<(std::ostream& out, const Board& b);
};

#endif //BOARD_H