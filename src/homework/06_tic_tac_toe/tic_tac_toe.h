// h

#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <vector>
#include <string>

class TicTacToe {
    friend std::istream& operator>>(std::istream& in, TicTacToe& game);
    friend std::ostream& operator<<(std::ostream& out, const TicTacToe& game);

private:
    std::vector<std::string> pegs{9, " "};
    std::string player;
    std::string winner;

    bool check_board_full();
    bool check_column_win();
    bool check_row_win();
    bool check_diagonal_win();
    void set_winner();
    void set_next_player();
    void clear_board();

public:
    void start_game(std::string first_player);
    void mark_board(int position);
    bool game_over();
    std::string get_winner() const { return winner; }
    std::string get_player() const { return player; }
};

#endif


