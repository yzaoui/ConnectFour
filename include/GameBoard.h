#ifndef _GAMEBOARD_H
#define _GAMEBOARD_H

#include <vector>

enum class Box {
	empty, yellow, red
};

class GameBoard {
public:
	explicit GameBoard(int boxesHorizontal = 7, int boxesVertical = 6, int boxesToWin = 4);

	/**
	 * Reset game board to all empty boxes, change player turn to yellow, set no winner.
	 */
	void reset();

	/**
	 * Get box type at given coordinate.
	 *
	 * @param  x The x-coordinate of the queried box.
	 * @param  y The y-coordinate of the queried box.
	 *
	 * @return   The type of the queried box.
	 */
	Box getBox(int x, int y) const;

	/**
	 * Get the amount of horizontal boxes in game board.
	 *
	 * @return The amount of horizontal boxes.
	 */
	int getBoxesHorizontal() const;

	/**
	 * Get the amount of vertical boxes in game board.
	 *
	 * @return The amount of vertical boxes.
	 */
	int getBoxesVertical() const;

	/**
	 * The current player plays a disc into the given column.
	 *
	 * @param column The column to insert a disc into.
	 */
	void play(int column);
private:
	/**
	 * Get the first available box in a given column.
	 *
	 * @param  column The column to query an empty box from.
	 *
	 * @return        The row of the first empty box, or -1 if none are available.
	 */
	int getColumnEmptyBox(int column);

	/**
	 * Check if the current player is a winner.
	 *
	 * @return Whether the current player won.
	 */
	bool checkWin() const;

	/**
	 * Change current player to the next player.
	 */
	void nextPlayer();

	/**
	 * Keep track of consecutive boxes of the same color.
	 *
	 * @param  x                The x-coordinate of the queried box.
	 * @param  y                The y-coordinate of the queried box.
	 * @param  consecutiveBoxes The counter of consecutive boxes.
	 *
	 * @return                  Whether the current amount of consecutive
	 *                          boxes has reached the amount to win.
	 */
	bool consecutiveBoxWin(int x, int y, int& consecutiveBoxes) const;

	std::vector<std::vector<Box>> boxes_;
	Box playerTurn_;
	bool won_;
	int boxesHorizontal_;
	int boxesVertical_;
	int boxesToWin_;
};

#endif
