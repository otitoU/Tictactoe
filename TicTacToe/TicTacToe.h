#pragma once


#pragma once
#include <iostream>

class TicTacToe {
public:
    TicTacToe();

    void drawBoard() const;
    void playerMove(char player);
    char checkWin() const;
    void play();
    bool boardFull() const;

private:
    static const int ROWS = 3;
    static const int COLS = 3;
    char board[ROWS][COLS];
};
