#include "GameScene/GameScene.h"

GameScene::GameScene(GameSceneManager& sceneManager, CFRenderer& renderer) :
	sceneManager_(sceneManager), renderer_(renderer) {}

GameScene::~GameScene() {}
