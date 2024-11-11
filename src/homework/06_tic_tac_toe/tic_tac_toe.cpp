//cpp

#include "tic_tac_toe.h"

void TicTacToe::start_game(std::string first_player) {
    player = first_player;
    clear_board();
}

void TicTacToe::mark_board(int position) {
    pegs[position - 1] = player;
    set_next_player();
}

bool TicTacToe::game_over() {
    if (check_row_win() || check_column_win() || check_diagonal_win()) {
        set_winner();
        return true;
    }
    else if (check_board_full()) {
        winner = "C";
        return true;
    }
    return false;
}

bool TicTacToe::check_board_full() {
    for (const auto& peg : pegs) {
        if (peg == " ") {
            return false;
        }
    }
    return true;
}

bool TicTacToe::check_column_win() {
    return (pegs[0] == player && pegs[3] == player && pegs[6] == player) ||
           (pegs[1] == player && pegs[4] == player && pegs[7] == player) ||
           (pegs[2] == player && pegs[5] == player && pegs[8] == player);
}

bool TicTacToe::check_row_win() {
    return (pegs[0] == player && pegs[1] == player && pegs[2] == player) ||
           (pegs[3] == player && pegs[4] == player && pegs[5] == player) ||
           (pegs[6] == player && pegs[7] == player && pegs[8] == player);
}

bool TicTacToe::check_diagonal_win() {
    return (pegs[0] == player && pegs[4] == player && pegs[8] == player) ||
           (pegs[2] == player && pegs[4] == player && pegs[6] == player);
}

void TicTacToe::set_winner() {
    winner = (player == "X") ? "O" : "X";
}

void TicTacToe::set_next_player() {
    player = (player == "X") ? "O" : "X";
}

void TicTacToe::clear_board() {
    for (auto& peg : pegs) {
        peg = " ";
    }
}

std::istream& operator>>(std::istream& in, TicTacToe& game) {
    int position;
    std::cout << "Enter position to mark (1-9): ";
    in >> position;
    game.mark_board(position);
    return in;
}

std::ostream& operator<<(std::ostream& out, const TicTacToe& game) {
    out << game.pegs[0] << "|" << game.pegs[1] << "|" << game.pegs[2] << "\n";
    out << "-+-+-\n";
    out << game.pegs[3] << "|" << game.pegs[4] << "|" << game.pegs[5] << "\n";
    out << "-+-+-\n";
    out << game.pegs[6] << "|" << game.pegs[7] << "|" << game.pegs[8] << "\n";
    return out;
}
