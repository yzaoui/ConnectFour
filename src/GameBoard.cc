#include "GameBoard.h"

#include <algorithm>

GameBoard::GameBoard(int boxesHorizontal, int boxesVertical, int boxesToWin) :
	boxesHorizontal_(boxesHorizontal),
	boxesVertical_(boxesVertical),
	boxesToWin_(boxesToWin)
{
	GameBoard::reset();
}

void GameBoard::reset() {
	boxes_.resize(boxesHorizontal_, std::vector<Box>(boxesVertical_));

	for (int i = 0; i < boxesHorizontal_; i++) {
		for (int j = 0; j < boxesVertical_; j++) {
			boxes_[i][j] = Box::empty;
		}
	}

	playerTurn_ = Box::yellow;
	won_ = false;
}

Box GameBoard::getBox(int x, int y) const {
	return boxes_[x][y];
}

int GameBoard::getBoxesHorizontal() const {
	return boxesHorizontal_;
}

int GameBoard::getBoxesVertical() const {
	return boxesVertical_;
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
	for (int i = boxesVertical_ - 1; i >= 0; i--) {
		if (boxes_[column][i] == Box::empty) {
			return i;
		}
	}

	return -1;
}

bool GameBoard::checkWin() const {
	int consecutiveBoxes;

	/* Check Horizontal */
	for (int y = boxesVertical_ - 1; y >= 0; y--) {
		consecutiveBoxes = 0;
		for (int x = 0; x < boxesHorizontal_; x++) {
			if (consecutiveBoxWin(x, y, consecutiveBoxes)) {
				return true;
			}
		}
	}

	/* Check Vertical */
	for (int x = 0; x < boxesHorizontal_; x++) {
		consecutiveBoxes = 0;
		for (int y = boxesVertical_ - 1; y >= 0; y--) {
			if (consecutiveBoxWin(x, y, consecutiveBoxes)) {
				return true;
			}
		}
	}

	/* Check Ascending Diagonal */
	// Bottom Right Portion
	for (int x = boxesHorizontal_ - 1; x >= 0; x--) {
		consecutiveBoxes = 0;
		for (int d = 0; d < std::min(boxesHorizontal_ - x, boxesVertical_); d++) {
			if (consecutiveBoxWin(x + d, boxesVertical_ - 1 - d, consecutiveBoxes)) {
				return true;
			}
		}
	}
	//Top Left Portion
	//	Starting at the second-to-last row because the last row is convered in
	//	the previous loop.
	for (int y = boxesVertical_ - 2; y >= 0; y--) {
		consecutiveBoxes = 0;
		for (int d = 0; d < std::min(y + 1, boxesHorizontal_); d++) {
			if (consecutiveBoxWin(0 + d, y - d, consecutiveBoxes)) {
				return true;
			}
		}
	}

	/* Check Descending Diagonal */
	// Bottom Left Portion
	for (int x = 0; x < boxesHorizontal_; x++) {
		consecutiveBoxes = 0;
		for (int d = 0; d < std::min(x + 1, boxesVertical_); d++) {
			if (consecutiveBoxWin(x - d, boxesVertical_ - 1 - d, consecutiveBoxes)) {
				return true;
			}
		}
	}
	//Top Right Portion
	//	Starting at the second row because the first row is covered in
	//	the previous loop.
	for (int y = boxesVertical_ - 2; y >= 0; y--) {
		consecutiveBoxes = 0;
		for (int d = 0; d < std::min(boxesHorizontal_, y + 1); d++) {
			if (consecutiveBoxWin(boxesHorizontal_ - 1 - d, y - d, consecutiveBoxes)) {
				return true;
			}
		}
	}

	return false;
}

bool GameBoard::consecutiveBoxWin(int x, int y, int& consecutiveBoxes) const {
	if (boxes_[x][y] == playerTurn_) {
		consecutiveBoxes++;
	} else {
		consecutiveBoxes = 0;
	}

	if (consecutiveBoxes == boxesToWin_) {
		return true;
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
