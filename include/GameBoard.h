#ifndef _GAMEBOARD_H
#define _GAMEBOARD_H

enum class Box {
	empty, yellow, red
};

const int NUM_BOXES_HORIZONTAL = 7;
const int NUM_BOXES_VERTICAL = 6;
const int NUM_BOXES_WIN = 4;

class GameBoard {
public:
	GameBoard();
	void reset();
	Box getBox(int x, int y) const;
	void play(int column);
private:
	Box boxes_[NUM_BOXES_HORIZONTAL][NUM_BOXES_VERTICAL];
	Box playerTurn_;
	bool won_;
	int getColumnEmptyBox(int column);
	bool checkWin() const;
	void nextPlayer();
	bool consecutiveBoxWin(int x, int y, int& consecutiveBoxes) const;
};

#endif
