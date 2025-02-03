#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <vector>

const char EMPTY = ' ';
const char WHITE = 'W';
const char BLACK = 'B';

class Gameplay {
private:
    std::vector<std::vector<char>> board;
    char currentPlayer;

    bool isValid(int x, int y);
    int countConsecutive(int x, int y, int dx, int dy, char player);

public:
    Gameplay();

    void makeMove(int x, int y);
    bool checkWin(int x, int y);
    bool isGameOver();
    char getCurrentPlayer();

    const std::vector<std::vector<char>>& getBoard() const; // API to retrieve board state
    void resetGame();  // API to reset game
};

#endif
