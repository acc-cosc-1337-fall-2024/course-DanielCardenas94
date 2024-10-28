#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Verify Test Configuration", "verification") {
    REQUIRE(true == true);
}

TEST_CASE("Test game over if 9 slots are selected") {
    TicTacToe game;
    game.start_game("X");

    int positions[] = {1, 2, 3, 4, 5, 7, 6, 9, 8};
    for (int i = 0; i < 9; ++i) {
        game.mark_board(positions[i]);
        if (i < 8) {
            REQUIRE(game.game_over() == false);  
        } else {
            REQUIRE(game.game_over() == true);   
        }
    }
}
