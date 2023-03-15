

#include "TicTacToe.h"

TicTacToe::TicTacToe()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            board[i][j] = '-';
        }
    }
}

void TicTacToe::drawBoard() const {
    std::cout << "Tic Tac Toe Game" << std::endl;
    std::cout << "  1 2 3" << std::endl;
    for (int i = 0; i < ROWS; i++)
    {
        std::cout << i + 1 << " ";
        for (int j = 0; j < COLS; j++)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void TicTacToe::playerMove(char player) {
    int row, col;
    std::cout << "Player " << player << ", enter row and column numbers (e.g. 1 2): ";
    std::cin >> row >> col;

    while (row < 1 || row > ROWS || col < 1 || col > COLS || board[row - 1][col - 1] != '-') {
        std::cout << "Invalid move. Please enter row and column numbers again: ";
        std::cin >> row >> col;
    }

    board[row - 1][col - 1] = player;
}

bool TicTacToe::boardFull() const {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == '-') {
                return false; // if any cell is empty, return false
            }
        }
    }
    return true; // if all cells are filled, return true
}

char TicTacToe::checkWin() const {
    //check rows
    for (int i = 0; i < ROWS; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-')
        {
            return board[i][0];
        }
    }

    //check columns
    for (int i = 0; i < COLS; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-')
        {
            return board[0][i];
        }
    }

    //check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-')
    {
        return board[0][0];
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-')
    {
        return board[0][2];
    }

    return '/';
}

void TicTacToe::play() {
    drawBoard();
    char currentPlayer = 'X';
    while (true)
    {
        playerMove(currentPlayer);
        drawBoard();
        char winner = checkWin();
        if (winner != '/')
        {
            std::cout << "Player " << winner << " wins!" << std::endl;
            break;
        }
        else if (boardFull())
        {
            std::cout << "Tie game!" << std::endl;
            break;
        }
        else
        {
            currentPlayer = currentPlayer == 'X' ? 'O' : 'X';
        }
    }
}



