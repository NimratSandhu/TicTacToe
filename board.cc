#include <iostream>
#include <vector>
#include "board.h"


Board::Board() : player('X') {
    // Initialize the board with empty spaces
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

void Board::placePeice(int i, int j) {
    board[i][j] = player;
}

void Board::switchTurn(){
    player = (player == 'X'? 'O' : 'X');
}

bool Board::checkForWin() {
    // Checking for a horizontal or vertical win
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Checking for a vertical Win
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

bool Board::isFull() {
    for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') {
                    return false;  // If any cell is empty, the board is not full
                }
            }
        }
        return true;  // All cells are filled, so the board is full
}

char Board::getPlayer() {
    return this->player;
}

std::ostream& operator<<(std::ostream& out, const Board& b) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            out << " "<< b.board[i][j] << " " ;
            if (j < 2) {out << '|';}
        }
        out << '\n';
        if (i < 2) {out << "-----------";}
        out << '\n';
    }
    out << '\n';
    return out;
}




