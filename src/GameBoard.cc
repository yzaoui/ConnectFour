#include "GameBoard.h"

GameBoard::GameBoard() {
	GameBoard::reset();
}

void GameBoard::reset() {
	for (int i = 0; i < NUM_BOXES_HORIZONTAL; i++) {
		for (int j = 0; j < NUM_BOXES_VERTICAL; j++) {
			boxes_[i][j] = Box::empty;
		}
	}
}

Box GameBoard::getBox(int x, int y) {
	return boxes_[x][y];
}
