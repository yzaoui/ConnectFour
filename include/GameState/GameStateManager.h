#ifndef _GAMESTATE_GAMESTATEMANAGER_H
#define _GAMESTATE_GAMESTATEMANAGER_H

#include <vector>

#include "GameState/GameState.h"
#include "CFRenderer.h"

class GameStateManager {
public:
	explicit GameStateManager(CFRenderer&);
	void handleEvents();
	void render();
	void pushState(StateID);
	bool isEmpty();
private:
	std::vector<GameState*> states_;
	CFRenderer& renderer_;
};

#endif
