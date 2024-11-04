// h

#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <string>
#include <vector>

class TicTacToe {
public:
    bool game_over();
    void start_game(std::string first_player);
    void mark_board(int position);
    std::string get_player() const;
    void display_board() const;
    std::string get_winner() const;

private:
    std::string player;
    std::vector<std::string> pegs = std::vector<std::string>(9, " ");
    std::string winner;

    void set_next_player();
    bool check_board_full() const;
    void clear_board();
    void set_winner();

    // New private functions 
    bool check_column_win() const;
    bool check_row_win() const;
    bool check_diagonal_win() const;
};

#endif


