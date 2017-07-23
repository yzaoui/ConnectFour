#include "GameScene/GameSceneManager.h"

#include "GameScene/SceneBoard.h"
#include "GameScene/SceneTitle.h"

GameSceneManager::GameSceneManager(CFRenderer& renderer, ResourceManager& resManager) :
	renderer_(renderer), resManager_(resManager) {}

void GameSceneManager::handleEvents() {
	scenes_.back()->handleEvents();
}

void GameSceneManager::render() {
	if (!GameSceneManager::isEmpty()) {
		for (auto &scene : scenes_) {
			scene->render();
		}
	}
}

void GameSceneManager::pushScene(SceneID id) {
	switch(id) {
		case SceneID::TITLE:
			scenes_.push_back(new SceneTitle(renderer_, *this, resManager_));
			break;
		case SceneID::BOARD:
			scenes_.push_back(new SceneBoard(renderer_, *this, resManager_));
			break;
	}
}

void GameSceneManager::changeScene(SceneID id) {
	delete scenes_.back();
	scenes_.pop_back();

	this->pushScene(id);
}

void GameSceneManager::emptyScenes() {
	for (auto &scene : scenes_) {
		delete scene;
	}
	scenes_.clear();
}

bool GameSceneManager::isEmpty() {
	return scenes_.empty();
}
