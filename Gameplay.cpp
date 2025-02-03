#include "Gameplay.h"
#include <iostream>

using namespace std;

//Black goes first
Gameplay::Gameplay() : board(15, vector<char>(15, EMPTY)), currentPlayer(BLACK) {}

bool Gameplay::isValid(int x, int y) {
    return (x >= 0 && x < 15 && y >= 0 && y < 15 && board[x][y] == EMPTY);
}

void Gameplay::makeMove(int x, int y) {
    if (!isValid(x, y)) return;
    board[x][y] = currentPlayer;
    currentPlayer = (currentPlayer == BLACK) ? WHITE : BLACK;
}

bool Gameplay::checkWin(int x, int y) {
    return (countConsecutive(x, y, 1, 0, board[x][y]) >= 5 || // Horizontal ¡ú
        countConsecutive(x, y, 0, 1, board[x][y]) >= 5 || // Vertical ¡ý
        countConsecutive(x, y, 1, 1, board[x][y]) >= 5 || // Diagonal ¨K
        countConsecutive(x, y, 1, -1, board[x][y]) >= 5); // Anti-Diagonal ¨L
}

int Gameplay::countConsecutive(int x, int y, int dx, int dy, char player) {
    int count = 1;
    for (int i = 1; i < 5; i++) {
        int nx = x + i * dx, ny = y + i * dy;
        if (nx < 0 || ny < 0 || nx >= 15 || ny >= 15 || board[nx][ny] != player) break;
        count++;
    }
    for (int i = 1; i < 5; i++) {
        int nx = x - i * dx, ny = y - i * dy;
        if (nx < 0 || ny < 0 || nx >= 15 || ny >= 15 || board[nx][ny] != player) break;
        count++;
    }
    return count;
}

bool Gameplay::isGameOver() {
    for (const auto& row : board)
        for (char cell : row)
            if (cell == EMPTY) return false;
    return true;
}

const vector<vector<char>>& Gameplay::getBoard() const {
    return board;
}

void Gameplay::resetGame() {
    board.assign(15, vector<char>(15, EMPTY));
    currentPlayer = BLACK;
}

char Gameplay::getCurrentPlayer() {
    return currentPlayer;
}
