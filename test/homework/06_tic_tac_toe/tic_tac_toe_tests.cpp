#include "tic_tac_toe.h"
#include "catch.hpp"

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
    game.mark_board(5); game.mark_board(4);
    game.mark_board(8);
    REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by third column") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(3); game.mark_board(1);
    game.mark_board(6); game.mark_board(4);
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


