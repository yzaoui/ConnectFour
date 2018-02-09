#ifndef _GAMESCENE_GAMEScene_H
#define _GAMESCENE_GAMEScene_H

#include "GameScene/GameSceneManager.h"
#include "CFRenderer.h"
#include "ResourceManager.h"

class GameSceneManager;

enum class SceneID {TITLE, BOARD};

class GameScene {
	friend GameSceneManager;
public:
	virtual ~GameScene();
	virtual void handleEvent(SDL_Event &e) = 0;
	virtual void update() = 0;
	virtual void render() = 0;
protected:
	GameScene(CFRenderer&, GameSceneManager&, ResourceManager&);
	void changeScene(SceneID);
	CFRenderer& renderer_;
	GameSceneManager& sceneManager_;
	ResourceManager& resManager_;
private:
	void markForDeletion();
	bool isMarkedForDeletion();
	bool toDelete_;
};

#endif
