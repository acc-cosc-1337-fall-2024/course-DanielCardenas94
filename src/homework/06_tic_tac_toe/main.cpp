#include "tic_tac_toe.h"
#include <iostream>
#include <string>

int main() {
    TicTacToe game;
    std::string first_player;
    char play_again;

    do {
        // Prompt for first player
        do {
            std::cout << "Enter the first player (X or O): ";
            std::cin >> first_player;
        } while (first_player != "X" && first_player != "O");

        game.start_game(first_player);

        // Game loop
        while (!game.game_over()) {
            int position;
            game.display_board();
            std::cout << "Player " << game.get_player() << ", enter a position (1-9): ";
            std::cin >> position;

            game.mark_board(position);
        }

        // Display the winner
        game.display_board();
        std::string winner = game.get_winner();
        if (winner == "C") {
            std::cout << "It's a tie!\n";
        } else {
            std::cout << "The winner is " << winner << "!\n";
        }

        // Ask if user wants to play again
        std::cout << "Do you want to play another game? (y/n): ";
        std::cin >> play_again;

    } while (play_again == 'y' || play_again == 'Y');

    return 0;
}

