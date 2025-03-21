#include "TicTacToe.h"
#include <iostream>
#include <cstdint>
#include <limits>

TicTacToe::TicTacToe()
{
    for (int i = 0; i < 9; ++i)
    {
        m_board[i] = ' ';
    }
    m_currentPlayer = 0;
}

bool TicTacToe::IsGameOver() const
{
    return CheckForWin() || CheckForTie();
}

void TicTacToe::TakeTurn()
{
    int position;
    while (true)
    {
        std::cout << "Player " << (m_currentPlayer + 1) << ", enter your move ( type 1-9 ) :";
        std::cin >> position;
        if (std::cin.fail() || position < 1 || position > 9)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please enter a digit between 1 and 9\n";
            continue;
        }


        if (m_board[position - 1] != ' ')
        {
            std::cout << "Spot taken. Please try a different number\n";
            continue;
        }

        break;
    }

    m_board[position - 1] = (m_currentPlayer == 0) ? 'X' : 'O';
    SwitchPlayer();
}

//display
void TicTacToe::Display() const
{
    system("cls"); // clear
    std::cout << "\n";
    for (int i = 0; i < 9; ++i)
    {
        std::cout << m_board[i];
        if ((i + 1) % 3 == 0)
        {
            std::cout << "\n";
            if (i < 8) std::cout << "-----\n";
        }
        else
        {
            std::cout << "|";
        }
    }
    std::cout << "\n";
}

bool TicTacToe::CheckForWin() const
{
    // rows
    for (int i = 0; i < 9; i += 3)
    {
        if (m_board[i] != ' ' && m_board[i] == m_board[i + 1] && m_board[i] == m_board[i + 2])
        {
            return true;
        }
    }
	// columns
    for (int i = 0; i < 3; ++i)
    {
        if (m_board[i] != ' ' && m_board[i] == m_board[i + 3] && m_board[i] == m_board[i + 6])
        {
            return true;
        }
    }

    // diagonal
    if (m_board[0] != ' ' && m_board[0] == m_board[4] && m_board[0] == m_board[8])
    {
        return true;
    }
    if (m_board[2] != ' ' && m_board[2] == m_board[4] && m_board[2] == m_board[6])
    {
        return true;
    }

    return false;
}

bool TicTacToe::CheckForTie() const
{
    for (int i = 0; i < 9; ++i)
    {
        if (m_board[i] == ' ')
        {
            return false;
        }
    }
    return true;
}

void TicTacToe::SwitchPlayer()
{
    m_currentPlayer = 1 - m_currentPlayer;
}