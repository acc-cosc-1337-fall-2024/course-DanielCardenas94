#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

TEST_CASE("Test first player set to X") {
    TicTacToe game;
    game.start_game("X");
    REQUIRE(game.get_player() == "X");
}

TEST_CASE("Test first player set to O") {
    TicTacToe game;
    game.start_game("O");
    REQUIRE(game.get_player() == "O");
}

TEST_CASE("Test game over if 9 slots are selected (tie)") {
    TicTacToe game;
    game.start_game("X");
    for (int i = 1; i <= 9; ++i) {
        game.mark_board(i);
    }
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "C");
}

// Column win test cases
TEST_CASE("Test win by first column") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(1); game.mark_board(2);
    game.mark_board(4); game.mark_board(5);
    game.mark_board(7);
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by second column") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(2); game.mark_board(1);
    game.mark_board(5); game.mark_board(3);
    game.mark_board(8);
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by third column") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(3); game.mark_board(1);
    game.mark_board(6); game.mark_board(2);
    game.mark_board(9);
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
}

// Row win test cases
TEST_CASE("Test win by first row") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(1); game.mark_board(4);
    game.mark_board(2); game.mark_board(5);
    game.mark_board(3);
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by second row") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(4); game.mark_board(1);
    game.mark_board(5); game.mark_board(2);
    game.mark_board(6);
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by third row") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(7); game.mark_board(1);
    game.mark_board(8); game.mark_board(2);
    game.mark_board(9);
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
}

// Diagonal win test cases
TEST_CASE("Test win diagonally from top left") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(1); game.mark_board(2);
    game.mark_board(5); game.mark_board(3);
    game.mark_board(9);
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win diagonally from bottom left") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(7); game.mark_board(1);
    game.mark_board(5); game.mark_board(2);
    game.mark_board(3);
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
}

// Testing TicTacToeManager for win tracking
TEST_CASE("Test TicTacToeManager get winner total function") {
    TicTacToeManager manager;
    TicTacToe game1, game2, game3;

    game1.start_game("X");
    game1.mark_board(1); game1.mark_board(4);
    game1.mark_board(2); game1.mark_board(5);
    game1.mark_board(3); // X wins
    REQUIRE(game1.game_over() == true);
    manager.save_game(game1);

    game2.start_game("O");
    game2.mark_board(1); game2.mark_board(4);
    game2.mark_board(2); game2.mark_board(5);
    game2.mark_board(3); game2.mark_board(7); // O wins
    REQUIRE(game2.game_over() == true);
    manager.save_game(game2);

    game3.start_game("X");
    for (int i = 1; i <= 9; ++i) {
        game3.mark_board(i);
    } // Tie
    REQUIRE(game3.game_over() == true);
    manager.save_game(game3);

    int x_wins, o_wins, ties;
    manager.get_winner_total(o_wins, x_wins, ties);

    REQUIRE(x_wins == 1);
    REQUIRE(o_wins == 1);
    REQUIRE(ties == 1);
}
