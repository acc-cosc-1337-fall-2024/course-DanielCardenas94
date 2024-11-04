//cpp

#include "tic_tac_toe.h"
#include <iostream>

void TicTacToe::start_game(std::string first_player) {
    player = first_player;
    clear_board();
}

void TicTacToe::mark_board(int position) {
    pegs[position - 1] = player;
    set_next_player();
}

std::string TicTacToe::get_player() const {
    return player;
}

void TicTacToe::display_board() const {
    for (int i = 0; i < pegs.size(); i += 3) {
        std::cout << pegs[i] << " | " << pegs[i + 1] << " | " << pegs[i + 2] << "\n";
    }
}

std::string TicTacToe::get_winner() const {
    return winner;
}

bool TicTacToe::game_over() {
    if (check_row_win() || check_column_win() || check_diagonal_win()) {
        set_winner();
        return true;
    } else if (check_board_full()) {
        winner = "C";  // C represents tie
        return true;
    }
    return false;
}

void TicTacToe::set_next_player() {
    player = (player == "X") ? "O" : "X";
}

bool TicTacToe::check_board_full() const {
    for (const auto& peg : pegs) {
        if (peg == " ") return false;
    }
    return true;
}

void TicTacToe::clear_board() {
    std::fill(pegs.begin(), pegs.end(), " ");
}

void TicTacToe::set_winner() {
    winner = (player == "X") ? "O" : "X";
}

// Win-checking functions
bool TicTacToe::check_column_win() const {
    return (pegs[0] == pegs[3] && pegs[3] == pegs[6] && pegs[0] != " ") ||
           (pegs[1] == pegs[4] && pegs[4] == pegs[7] && pegs[1] != " ") ||
           (pegs[2] == pegs[5] && pegs[5] == pegs[8] && pegs[2] != " ");
}

bool TicTacToe::check_row_win() const {
    return (pegs[0] == pegs[1] && pegs[1] == pegs[2] && pegs[0] != " ") ||
           (pegs[3] == pegs[4] && pegs[4] == pegs[5] && pegs[3] != " ") ||
           (pegs[6] == pegs[7] && pegs[7] == pegs[8] && pegs[6] != " ");
}

bool TicTacToe::check_diagonal_win() const {
    return (pegs[0] == pegs[4] && pegs[4] == pegs[8] && pegs[0] != " ") ||
           (pegs[6] == pegs[4] && pegs[4] == pegs[2] && pegs[6] != " ");
}
