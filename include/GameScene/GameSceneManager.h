#ifndef _GAMESCENE_GAMESCENEMANAGER_H
#define _GAMESCENE_GAMESCENEMANAGER_H

#include <vector>

#include "GameScene/GameScene.h"
#include "CFRenderer.h"

class GameScene;
enum class SceneID;

class GameSceneManager {
public:
	explicit GameSceneManager(CFRenderer&);
	void handleEvents();
	void render();
	void changeScene(SceneID);
	void pushScene(SceneID);
	void emptyScenes();
	bool isEmpty();
private:
	std::vector<GameScene*> scenes_;
	CFRenderer& renderer_;
};

#endif
