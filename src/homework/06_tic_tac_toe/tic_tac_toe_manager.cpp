//cpp

#include "tic_tac_toe_manager.h"

void TicTacToeManager::save_game(std::unique_ptr<TicTacToe>& game) {
    update_winner_count(game->get_winner());
    games.push_back(std::move(game));
}

void TicTacToeManager::get_winner_totals(int& x_wins, int& o_wins, int& tie_count) const {
    x_wins = x_win;
    o_wins = o_win;
    tie_count = ties;
}

void TicTacToeManager::update_winner_count(const std::string& winner) {
    if (winner == "X") {
        x_win++;
    } else if (winner == "O") {
        o_win++;
    } else {
        ties++;
    }
}

std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager) {
    for (const auto& game : manager.games) {
        out << *game << "\n";
    }
    return out;
}
