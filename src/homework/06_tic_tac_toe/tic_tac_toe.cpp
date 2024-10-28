//cpp

#include "tic_tac_toe.h"
#include <iostream>

bool TicTacToe::game_over() {
    return check_board_full();
}

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

void TicTacToe::set_next_player() {
    player = (player == "X") ? "O" : "X";
}

bool TicTacToe::check_board_full() {
    for (const auto& peg : pegs) {
        if (peg == " ") return false;
    }
    return true;
}

void TicTacToe::clear_board() {
    std::fill(pegs.begin(), pegs.end(), " ");
}

