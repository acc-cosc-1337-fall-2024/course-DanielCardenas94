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

private:
    std::string player;
    std::vector<std::string> pegs = std::vector<std::string>(9, " ");
    void set_next_player();
    bool check_board_full();
    void clear_board();
};

#endif
