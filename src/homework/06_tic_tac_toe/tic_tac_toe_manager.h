//h

#ifndef TICTACTOEMANAGER_H
#define TICTACTOEMANAGER_H

#include <vector>
#include "tic_tac_toe.h"

class TicTacToeManager {
private:
    std::vector<TicTacToe> games;
    int x_wins{0};
    int o_wins{0};
    int ties{0};

    void update_winner_count(std::string winner);

public:
    void save_game(TicTacToe b);
    void get_winner_total(int& o, int& x, int& t) const;
};

#endif
