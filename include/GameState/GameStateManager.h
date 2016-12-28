#ifndef _GAMESTATE_GAMESTATEMANAGER_H
#define _GAMESTATE_GAMESTATEMANAGER_H

#include <vector>

#include "GameState/GameState.h"
#include "CFRenderer.h"

class GameState;
enum class StateID;

class GameStateManager {
public:
	explicit GameStateManager(CFRenderer&);
	void handleEvents();
	void render();
	void changeState(StateID);
	void pushState(StateID);
	void emptyStates();
	bool isEmpty();
private:
	std::vector<GameState*> states_;
	CFRenderer& renderer_;
};

#endif
