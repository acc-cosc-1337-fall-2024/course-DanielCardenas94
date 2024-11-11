#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include <iostream>

int main() {
    TicTacToeManager manager;
    char play_again;
    
    do {
        TicTacToe game;
        std::string first_player;
        std::cout << "Enter first player (X or O): ";
        std::cin >> first_player;
        game.start_game(first_player);

        while (!game.game_over()) {
            std::cout << game;
            std::cin >> game;
        }

        std::cout << "Game Over! Winner: " << game.get_winner() << "\n";
        manager.save_game(game);

        int x_wins, o_wins, ties;
        manager.get_winner_total(o_wins, x_wins, ties);
        std::cout << "Scores: X wins: " << x_wins << ", O wins: " << o_wins << ", Ties: " << ties << "\n";

        std::cout << "Play again? (y/n): ";
        std::cin >> play_again;
    } while (play_again == 'y' || play_again == 'Y');

    return 0;
}
