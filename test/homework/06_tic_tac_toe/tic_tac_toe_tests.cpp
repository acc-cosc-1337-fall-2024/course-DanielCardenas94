#include "src/homework/06_tic_tac_toe/tic_tac_toe_3.h"
#include "src/homework/06_tic_tac_toe/tic_tac_toe_4.h"
#include "catch.hpp"
#include <memory>

// Test TicTacToe3 - Win by Rows, Columns, and Diagonals
TEST_CASE("Test TicTacToe3: Win by first column") {
    std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe3>();
    game->start_game("X");
    game->mark_board(1);
    game->mark_board(2);
    game->mark_board(4);
    game->mark_board(5);
    game->mark_board(7);
    REQUIRE(game->game_over() == true);
    REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test TicTacToe3: Win by first row") {
    std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe3>();
    game->start_game("O");
    game->mark_board(1);
    game->mark_board(4);
    game->mark_board(2);
    game->mark_board(5);
    game->mark_board(3);
    REQUIRE(game->game_over() == true);
    REQUIRE(game->get_winner() == "O");
}

TEST_CASE("Test TicTacToe3: Win by diagonal") {
    std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe3>();
    game->start_game("X");
    game->mark_board(1);
    game->mark_board(2);
    game->mark_board(5);
    game->mark_board(3);
    game->mark_board(9);
    REQUIRE(game->game_over() == true);
    REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test TicTacToe3: Tie game") {
    std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe3>();
    game->start_game("X");
    game->mark_board(1); game->mark_board(2); game->mark_board(3);
    game->mark_board(5); game->mark_board(4); game->mark_board(6);
    game->mark_board(8); game->mark_board(7); game->mark_board(9);
    REQUIRE(game->game_over() == true);
    REQUIRE(game->get_winner() == "C");
}

// Test TicTacToe4 - Win by Rows, Columns, and Diagonals
TEST_CASE("Test TicTacToe4: Win by first column") {
    std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe4>();
    game->start_game("X");
    game->mark_board(1);
    game->mark_board(2);
    game->mark_board(5);
    game->mark_board(3);
    game->mark_board(9);
    game->mark_board(4);
    game->mark_board(13);
    REQUIRE(game->game_over() == true);
    REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test TicTacToe4: Win by first row") {
    std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe4>();
    game->start_game("O");
    game->mark_board(1);
    game->mark_board(5);
    game->mark_board(2);
    game->mark_board(6);
    game->mark_board(3);
    game->mark_board(7);
    game->mark_board(4);
    REQUIRE(game->game_over() == true);
    REQUIRE(game->get_winner() == "O");
}

TEST_CASE("Test TicTacToe4: Win by diagonal") {
    std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe4>();
    game->start_game("X");
    game->mark_board(1);
    game->mark_board(2);
    game->mark_board(6);
    game->mark_board(3);
    game->mark_board(11);
    game->mark_board(4);
    game->mark_board(16);
    REQUIRE(game->game_over() == true);
    REQUIRE(game->get_winner() == "X");
}

TEST_CASE("Test TicTacToe4: Tie game") {
    std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe4>();
    game->start_game("X");
    for (int i = 1; i <= 16; ++i) {
        game->mark_board(i);
    }
    REQUIRE(game->game_over() == true);
    REQUIRE(game->get_winner() == "C");
}
