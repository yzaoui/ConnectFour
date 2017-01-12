#include "GameScene/GameSceneManager.h"

#include "GameScene/SceneBoard.h"
#include "GameScene/SceneTitle.h"

GameSceneManager::GameSceneManager(CFRenderer& renderer) : renderer_(renderer) {}

void GameSceneManager::handleEvents() {
	scenes_.back()->handleEvents();
}

void GameSceneManager::render() {
	if (!GameSceneManager::isEmpty()) {
		for (auto i = scenes_.begin(); i != scenes_.end(); i++) {
			(*i)->render();
		}
	}
}

void GameSceneManager::pushScene(SceneID id) {
	switch(id) {
		case SceneID::TITLE:
			scenes_.push_back(new SceneTitle(*this, renderer_));
			break;
		case SceneID::BOARD:
			scenes_.push_back(new SceneBoard(*this, renderer_));
			break;
	}
}

void GameSceneManager::changeScene(SceneID id) {
	delete scenes_.back();
	scenes_.pop_back();

	GameSceneManager::pushScene(id);
}

void GameSceneManager::emptyScenes() {
	for (auto i = scenes_.begin(); i != scenes_.end(); i++) {
		delete *i;
	}
	scenes_.clear();
}

bool GameSceneManager::isEmpty() {
	return scenes_.empty();
}
