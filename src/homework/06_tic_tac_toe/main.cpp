#include <iostream>
#include "tic_tac_toe.h"

int main() {
    TicTacToe game;
    std::string first_player;
    
    std::cout << "Enter the first player (X or O): ";
    std::cin >> first_player;
    game.start_game(first_player);
    
    char continue_game;
    do {
        // Main game loop until the board is full
        while (!game.game_over()) {
            int position;
            std::cout << "Player " << game.get_player() << ", enter a position (1-9): ";
            std::cin >> position;
            
            game.mark_board(position);
            game.display_board();
        }
        
        // Prompt to play again or quit
        std::cout << "Game over. Do you want to play again? (y/n): ";
        std::cin >> continue_game;
        
        if (continue_game == 'y') {
            std::cout << "Enter the first player (X or O): ";
            std::cin >> first_player;
            game.start_game(first_player);
        }
    } while (continue_game == 'y');

    return 0;
}
