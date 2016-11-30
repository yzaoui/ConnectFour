#ifndef _GAMEBOARD_H
#define _GAMEBOARD_H

enum class Box {
	empty, yellow, red
};

const int NUM_BOXES_HORIZONTAL = 7;
const int NUM_BOXES_VERTICAL = 6;

class GameBoard {
public:
	GameBoard();
	void reset();
	Box getBox(int x, int y);
private:
	Box boxes_[NUM_BOXES_HORIZONTAL][NUM_BOXES_VERTICAL];
};

#endif
