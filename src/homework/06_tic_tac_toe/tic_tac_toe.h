// h

#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <vector>
#include <string>
#include <iostream>

class TicTacToe {
protected:
    std::vector<std::string> pegs;
    std::string player;
    std::string winner;

    virtual bool check_column_win() = 0;
    virtual bool check_row_win() = 0;
    virtual bool check_diagonal_win() = 0;
    bool check_board_full();

    void set_winner();
    void set_next_player();

public:
    TicTacToe(int size) : pegs(size * size, " ") {}

    void start_game(std::string first_player);
    void mark_board(int position);
    std::string get_player() const { return player; }
    std::string get_winner() const { return winner; }
    bool game_over();

    void display_board() const;
    const std::vector<std::string>& get_pegs() const { return pegs; }

    friend std::ostream& operator<<(std::ostream& out, const TicTacToe& game);
    friend std::istream& operator>>(std::istream& in, TicTacToe& game);
};

#endif // TIC_TAC_TOE_H
