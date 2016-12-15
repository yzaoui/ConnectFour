#ifndef _GAMESTATE_GAMESTATEMANAGER_H
#define _GAMESTATE_GAMESTATEMANAGER_H

#include <vector>

#include "GameState/GameState.h"
#include "CFRenderer.h"

class GameStateManager {
public:
	void handleEvents();
	void render();
	void pushState(StateID, CFRenderer&);
	bool isEmpty();
private:
	std::vector<GameState*> states_;
};

#endif