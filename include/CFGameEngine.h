#ifndef _CFGAMEENGINE_H
#define _CFGAMEENGINE_H

#include <vector>
#include <SDL_events.h>

#include "GameScene/GameSceneManager.h"
#include "CFRenderer.h"
#include "CFWindow.h"
#include "ResourceManager.h"

class CFGameEngine {
public:
	CFGameEngine();
	~CFGameEngine();
	bool OnInit();
	void OnEvent(SDL_Event& e);
	bool OnLoop();
	void OnRender();
	void OnCleanup();

	int OnExecute();
private:
	CFWindow* window_;
	CFRenderer* renderer_;
	ResourceManager* resManager_;
	GameSceneManager* sceneManager_;
};

#endif
