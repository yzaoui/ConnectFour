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
	playerTurn_ = Box::yellow;
}

Box GameBoard::getBox(int x, int y) {
	return boxes_[x][y];
}

void GameBoard::play(int column) {
	int emptyBox = getColumnEmptyBox(column);

	if (emptyBox >= 0) {
		if (playerTurn_ == Box::yellow) {
			boxes_[column][emptyBox] = Box::yellow;

			playerTurn_ = Box::red;
		} else {
			boxes_[column][emptyBox] = Box::red;

			playerTurn_ = Box::yellow;
		}
	}
}

int GameBoard::getColumnEmptyBox(int column) {
	for (int i = NUM_BOXES_VERTICAL - 1; i >= 0; i--) {
		if (boxes_[column][i] == Box::empty) {
			return i;
		}
	}

	return -1;
}
