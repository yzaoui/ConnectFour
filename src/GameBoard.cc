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
	won_ = false;
}

Box GameBoard::getBox(int x, int y) const {
	return boxes_[x][y];
}

void GameBoard::play(int column) {
	if(!won_) {

		int emptyBox = getColumnEmptyBox(column);

		if (emptyBox >= 0) {
			boxes_[column][emptyBox] = playerTurn_;
		}

		if (!(won_ = GameBoard::checkWin())) {
			GameBoard::nextPlayer();
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

bool GameBoard::checkWin() const {
	int consecutiveBoxes;

	/* Check Horizontal */
	for (int y = NUM_BOXES_VERTICAL - 1; y >= 0; y--) {
		consecutiveBoxes = 0;
		for (int x = 0; x < NUM_BOXES_HORIZONTAL; x++) {
			if (boxes_[x][y] == playerTurn_) {
				consecutiveBoxes++;
			} else {
				consecutiveBoxes = 0;
			}

			if (consecutiveBoxes == NUM_BOXES_WIN) {
				return true;
			}
		}
	}

	/* Check Vertical */
	for (int x = 0; x < NUM_BOXES_HORIZONTAL; x++) {
		consecutiveBoxes = 0;
		for (int y = NUM_BOXES_VERTICAL - 1; y >= 0; y--) {
			if (boxes_[x][y] == playerTurn_) {
				consecutiveBoxes++;
			} else {
				consecutiveBoxes = 0;
			}

			if (consecutiveBoxes == NUM_BOXES_WIN) {
				return true;
			}
		}
	}

	return false;
}

void GameBoard::nextPlayer() {
	if (playerTurn_ == Box::yellow) {
		playerTurn_ = Box::red;
	} else if (playerTurn_ == Box::red) {
		playerTurn_ = Box::yellow;
	}
}
