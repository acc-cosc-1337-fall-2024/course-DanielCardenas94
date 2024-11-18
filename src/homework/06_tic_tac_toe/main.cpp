#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include <iostream>
#include <memory>

using std::cout;
using std::cin;
using std::unique_ptr;
using std::make_unique;

int main() {
    TicTacToeManager manager;
    std::string player;
    char play_again = 'Y';
    int game_type;

    cout << "Welcome to TicTacToe!\n";

    while (play_again == 'Y' || play_again == 'y') {
        cout << "Choose game type:\n";
        cout << "1. TicTacToe 3 (3x3)\n";
        cout << "2. TicTacToe 4 (4x4)\n";
        cout << "Enter your choice (1 or 2): ";
        cin >> game_type;

        unique_ptr<TicTacToe> game;

        if (game_type == 1) {
            game = make_unique<TicTacToe3>();
        } else if (game_type == 2) {
            game = make_unique<TicTacToe4>();
        } else {
            cout << "Invalid choice. Please enter 1 or 2.\n";
            continue;
        }

        cout << "Enter first player (X or O): ";
        cin >> player;

        while (player != "X" && player != "O") {
            cout << "Invalid input. Please enter X or O: ";
            cin >> player;
        }

        game->start_game(player);

        while (!game->game_over()) {
            int position;
            game->display_board();
            cout << "Player " << game->get_player() << ", enter a position (1-" << game->get_pegs().size() << "): ";
            cin >> position;

            while (position < 1 || position > game->get_pegs().size() || game->get_pegs()[position - 1] != " ") {
                cout << "Invalid position. Please choose an empty position between 1 and " << game->get_pegs().size() << ": ";
                cin >> position;
            }

            game->mark_board(position);
        }

        game->display_board();
        cout << "Game over! Winner: " << game->get_winner() << "\n";

        manager.save_game(game);

        int x_wins, o_wins, ties;
        manager.get_winner_totals(x_wins, o_wins, ties);
        cout << "Scoreboard:\n";
        cout << "X wins: " << x_wins << "\n";
        cout << "O wins: " << o_wins << "\n";
        cout << "Ties: " << ties << "\n";

        cout << "Do you want to play again? (Y/N): ";
        cin >> play_again;
    }

    cout << "Game history:\n";
    cout << manager;

    return 0;
}
