#ifndef _GAMESTATE_STATETITLE_H
#define _GAMESTATE_STATETITLE_H

#include "GameState/GameState.h"
#include "CFRenderer.h"
#include "CFTexture.h"

class StateTitle : public GameState {
public:
	StateTitle(GameStateManager&, CFRenderer&);
	void handleEvents();
	void update();
	void render();
private:
	CFTexture title_;
};

#endif
