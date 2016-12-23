#ifndef _GAMESTATE_GAMESTATE_H
#define _GAMESTATE_GAMESTATE_H

#include "CFRenderer.h"

enum class StateID {BOARD};

class GameState {
public:
	virtual ~GameState();
	virtual int handleEvents() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
protected:
	GameState(CFRenderer&);
	CFRenderer& renderer_;
};

#endif
