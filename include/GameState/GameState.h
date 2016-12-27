#ifndef _GAMESTATE_GAMESTATE_H
#define _GAMESTATE_GAMESTATE_H

#include "GameState/GameStateManager.h"
#include "CFRenderer.h"

class GameStateManager;

enum class StateID {TITLE, BOARD};

class GameState {
public:
	virtual ~GameState();
	virtual void handleEvents() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
protected:
	GameState(GameStateManager&, CFRenderer&);
	void changeState(StateID);
	GameStateManager& stateManager_;
	CFRenderer& renderer_;
};

#endif
