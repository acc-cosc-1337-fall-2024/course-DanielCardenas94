#include "tic_tac_toe_4.h"

// Check for a win by column
bool TicTacToe4::check_column_win() {
    for (int col = 0; col < 4; ++col) {
        if (pegs[col] != " " &&
            pegs[col] == pegs[col + 4] &&
            pegs[col] == pegs[col + 8] &&
            pegs[col] == pegs[col + 12]) {
            return true;
        }
    }
    return false;
}

// Check for a win by row
bool TicTacToe4::check_row_win() {
    for (int row = 0; row < 4; ++row) {
        int index = row * 4;
        if (pegs[index] != " " &&
            pegs[index] == pegs[index + 1] &&
            pegs[index] == pegs[index + 2] &&
            pegs[index] == pegs[index + 3]) {
            return true;
        }
    }
    return false;
}

// Check for a win by diagonal
bool TicTacToe4::check_diagonal_win() {
    // Check top-left to bottom-right diagonal
    if (pegs[0] != " " &&
        pegs[0] == pegs[5] &&
        pegs[0] == pegs[10] &&
        pegs[0] == pegs[15]) {
        return true;
    }
    // Check top-right to bottom-left diagonal
    if (pegs[3] != " " &&
        pegs[3] == pegs[6] &&
        pegs[3] == pegs[9] &&
        pegs[3] == pegs[12]) {
        return true;
    }
    return false;
}



