#ifndef _GAMESCENE_GAMEScene_H
#define _GAMESCENE_GAMEScene_H

#include "GameScene/GameSceneManager.h"
#include "CFRenderer.h"

class GameSceneManager;

enum class SceneID {TITLE, BOARD};

class GameScene {
public:
	virtual ~GameScene();
	virtual void handleEvents() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
protected:
	GameScene(GameSceneManager&, CFRenderer&);
	void changeScene(SceneID);
	GameSceneManager& sceneManager_;
	CFRenderer& renderer_;
};

#endif
