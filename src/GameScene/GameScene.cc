#include "GameScene/GameScene.h"

GameScene::GameScene(CFRenderer& renderer, GameSceneManager& sceneManager, ResourceManager& resManager) :
	renderer_(renderer), sceneManager_(sceneManager), resManager_{resManager}, toDelete_(false) {}

GameScene::~GameScene() {}

void GameScene::markForDeletion() {
	toDelete_ = true;
}

bool GameScene::isMarkedForDeletion() {
	return toDelete_;
}
