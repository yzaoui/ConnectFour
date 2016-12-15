#ifndef _CFGAMEENGINE_H
#define _CFGAMEENGINE_H

#include <vector>

#include "GameState/GameStateManager.h"
#include "CFRenderer.h"
#include "CFWindow.h"

class CFGameEngine {
public:
	CFGameEngine();
	~CFGameEngine();
	void run();
private:
	CFWindow* window_;
	CFRenderer* renderer_;
	GameStateManager stateManager_;
};

#endif
