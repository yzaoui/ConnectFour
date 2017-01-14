#ifndef _GAMESCENE_SCENETITLE_H
#define _GAMESCENE_SCENETITLE_H

#include "GameScene/GameScene.h"
#include "CFRenderer.h"
#include "CFTexture.h"
#include "ResourceManager.h"

class SceneTitle : public GameScene {
public:
	SceneTitle(CFRenderer&, GameSceneManager&, ResourceManager&);
	void handleEvents();
	void update();
	void render();
private:
	CFTexture title_;
	CFTexture background_;
};

#endif
