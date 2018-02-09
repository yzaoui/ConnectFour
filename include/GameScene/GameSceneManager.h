#ifndef _GAMESCENE_GAMESCENEMANAGER_H
#define _GAMESCENE_GAMESCENEMANAGER_H

#include <forward_list>
#include <SDL_events.h>

#include "GameScene/GameScene.h"
#include "CFRenderer.h"
#include "ResourceManager.h"

class GameScene;
enum class SceneID;

class GameSceneManager {
public:
	explicit GameSceneManager(CFRenderer&, ResourceManager&);
	virtual ~GameSceneManager();
	void handleEvent(SDL_Event &e);
	void render();
	void changeScene(SceneID);
	void pushScene(SceneID);
	bool isEmpty();
	void quit();
	bool onLoop();
private:
	std::forward_list<GameScene*> scenes_;
	CFRenderer& renderer_;
	ResourceManager resManager_;
	bool willExit_;
};

#endif
