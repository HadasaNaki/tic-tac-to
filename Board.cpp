#include "Board.h"
#include <string>

void Board::switchPlayer() {
    if (getCurrentPlayer() == 'X')
        setCurrentPlayer('O');
    else
        setCurrentPlayer('X');
}

void Board::insert(int num) {
    int row = num / BOARD_SIZE;
    int col = num % BOARD_SIZE;

    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
        throw ("Error: Invalid value.\n");
    }

    if (board[row][col] == 'O' || board[row][col] == 'X') {
        std::cerr << "Error: Full location.\n";
        switchPlayer();
        return;
    }

    board[row][col] = getCurrentPlayer();
}

void Board::print() {
    std::cout << std::endl;

    for (size_t i = 0; i < BOARD_SIZE; i++) {
        std::cout << "   ";
        for (size_t j = 0; j < BOARD_SIZE; j++) {
            std::cout << "----";
        }
        std::cout << "-" << std::endl;

        for (size_t j = 0; j < BOARD_SIZE; j++) {
            std::cout << "| " << board[i][j] << " ";
        }
        std::cout << "|" << std::endl;
    }

    std::cout << "   ";
    for (size_t j = 0; j < BOARD_SIZE; j++) {
        std::cout << "----";
    }
    std::cout << "-" << std::endl;
}

bool Board::ChekingIfRowIsFilled() {
    size_t counter_col = 0;
    size_t counter_row = 0;
    size_t counter_slant_r = 0;
    size_t counter_slant_l = 0;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == getCurrentPlayer()) counter_col++;
            if (board[j][i] == getCurrentPlayer()) counter_row++;
        }
        if (counter_col == BOARD_SIZE || counter_row == BOARD_SIZE) {
            return true;
        }

        counter_col = 0;
        counter_row = 0;

        if (board[i][i] == getCurrentPlayer()) counter_slant_r++;
        if (board[i][BOARD_SIZE - i - 1] == getCurrentPlayer()) counter_slant_l++;
    }

    if (counter_slant_r == BOARD_SIZE || counter_slant_l == BOARD_SIZE) {
        return true;
    }
    return false;
}