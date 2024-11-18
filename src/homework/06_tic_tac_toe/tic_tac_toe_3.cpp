#include "tic_tac_toe_3.h"

// Check for a win by column
bool TicTacToe3::check_column_win() {
    for (int col = 0; col < 3; ++col) {
        if (pegs[col] != " " &&
            pegs[col] == pegs[col + 3] &&
            pegs[col] == pegs[col + 6]) {
            return true;
        }
    }
    return false;
}

// Check for a win by row
bool TicTacToe3::check_row_win() {
    for (int row = 0; row < 3; ++row) {
        int index = row * 3;
        if (pegs[index] != " " &&
            pegs[index] == pegs[index + 1] &&
            pegs[index] == pegs[index + 2]) {
            return true;
        }
    }
    return false;
}

// Check for a win by diagonal
bool TicTacToe3::check_diagonal_win() {
    if (pegs[0] != " " &&
        pegs[0] == pegs[4] &&
        pegs[0] == pegs[8]) {
        return true;
    }
    if (pegs[2] != " " &&
        pegs[2] == pegs[4] &&
        pegs[2] == pegs[6]) {
        return true;
    }
    return false;
}









