#include"Gameplay.h"

using namespace std;

const char WHITE = 'W';
const char BLACK = 'B';

class GameManager {
private:
	Gameplay game;
	bool isRunning;
public:
	GameManager() : isRunning(true) {
		bool isPlayer1Turn = true;
		int x=0, y=0;
		if (rand() % 2 == 0) isPlayer1Turn = false;
		while (isRunning) {
			//display board
			if (isPlayer1Turn) {
				//player 1 turn return x and y
				game.makeMove(x, y);
			}
			else {
				//player 2 turn return x and y
				game.makeMove(x, y);
			}
			if (game.checkWin(x, y)) {
				//display winner
				isRunning = false;
			}
			else if (game.isGameOver()) {
				//display tie
				isRunning = false;
			}
			isPlayer1Turn = !isPlayer1Turn; //switch player
		}
	}
};