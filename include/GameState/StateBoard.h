#ifndef _GAMESTATE_STATEBOARD_H
#define _GAMESTATE_STATEBOARD_H

#include "GameState/GameState.h"
#include "CFRenderer.h"
#include "CFTexture.h"
#include "GameBoard.h"

class StateBoard : public GameState {
public:
	StateBoard(GameStateManager&, CFRenderer&);
	void handleEvents();
	void update();
	void render();
private:
	GameBoard board_;
	CFTexture boxEmpty_;
	CFTexture boxYellow_;
	CFTexture boxRed_;

	int BOX_SIZE;
	int NUM_BOXES_HORIZONTAL;
	int NUM_BOXES_VERTICAL;
	int BOARD_OFFSET_WIDTH;
	int BOARD_OFFSET_HEIGHT;
};

#endif
