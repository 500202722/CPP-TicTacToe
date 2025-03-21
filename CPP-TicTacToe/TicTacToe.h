#pragma once
#include "Game.h"

class TicTacToe : public Game
{
private:
    char m_board[9];
    int m_currentPlayer; // player 1 == 0, player 2 == 1

public:
    TicTacToe();
    bool IsGameOver() const override;
    void TakeTurn() override;
    void Display() const override;

private:
    bool CheckForWin() const;
    bool CheckForTie() const;
    void SwitchPlayer();
};
