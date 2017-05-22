#ifndef _GAMESCENE_SCENETITLE_H
#define _GAMESCENE_SCENETITLE_H

#include "GameScene/GameScene.h"
#include "CFRenderer.h"
#include "CFTexture.h"

class SceneTitle : public GameScene {
public:
	SceneTitle(GameSceneManager&, CFRenderer&);
	void handleEvents();
	void update();
	void render();
private:
	CFTexture title_;
	CFTexture background_;
};

#endif