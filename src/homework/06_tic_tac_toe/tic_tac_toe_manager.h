//h

#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

#include "tic_tac_toe.h"
#include <vector>
#include <memory>
#include <iostream>

class TicTacToeManager {
private:
    std::vector<std::unique_ptr<TicTacToe>> games;
    int x_win{0};
    int o_win{0};
    int ties{0};

    void update_winner_count(const std::string& winner);

public:
    void save_game(std::unique_ptr<TicTacToe>& game);
    void get_winner_totals(int& x_wins, int& o_wins, int& tie_count) const;

    friend std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager);
};

#endif // TIC_TAC_TOE_MANAGER_H
