#include "GameScene/GameScene.h"

GameScene::GameScene(CFRenderer& renderer, GameSceneManager& sceneManager, ResourceManager& resManager) :
	renderer_(renderer), sceneManager_(sceneManager), resManager_{resManager} {}

GameScene::~GameScene() {}
