#ifndef _GAMESTATE_STATETITLE_H
#define _GAMESTATE_STATETITLE_H

#include "GameState/GameState.h"
#include "CFRenderer.h"

class StateTitle : public GameState {
public:
	StateTitle(GameStateManager&, CFRenderer&);
	int handleEvents();
	void update();
	void render();
};

#endif
