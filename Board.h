#pragma once
#include <iostream>
#include <vector>

class Board {
public:
    Board(int N) {
        if (N <= 2) {
            throw "Error: Board size must be greater than 2.";
        }
        BOARD_SIZE = N;
        currentPlayer = 'X';
        board = std::vector<std::vector<char>>(BOARD_SIZE, std::vector<char>(BOARD_SIZE));
    }
    char getCurrentPlayer() {
        return currentPlayer;
    };
    void setCurrentPlayer(char player) {
        currentPlayer = player;
    };gi

    void insert(int num);
    bool ChekingIfRowIsFilled();
    void switchPlayer();
    void print();


private:
    int BOARD_SIZE;
    char currentPlayer;
    std::vector<std::vector<char>> board;
};