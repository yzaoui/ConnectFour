#ifndef _GAMESCENE_SCENEBOARD_H
#define _GAMESCENE_SCENEBOARD_H

#include "GameScene/GameScene.h"
#include "CFRenderer.h"
#include "CFTexture.h"
#include "GameBoard.h"

class SceneBoard : public GameScene {
public:
	SceneBoard(GameSceneManager&, CFRenderer&);
	void handleEvents();
	void update();
	void render();
private:
	GameBoard board_;
	CFTexture boxEmpty_;
	CFTexture boxYellow_;
	CFTexture boxRed_;

	int BOX_SIZE;
	int NUM_BOXES_HORIZONTAL;
	int NUM_BOXES_VERTICAL;
	int BOARD_OFFSET_WIDTH;
	int BOARD_OFFSET_HEIGHT;
};

#endif
