#include "GameScene/GameSceneManager.h"

#include "GameScene/SceneBoard.h"
#include "GameScene/SceneTitle.h"

GameSceneManager::GameSceneManager(CFRenderer& renderer, ResourceManager& resManager) :
	renderer_(renderer), resManager_(resManager), willExit_(false) {}

GameSceneManager::~GameSceneManager() {
	for (auto &scene : scenes_) {
		delete scene;
	}
	scenes_.clear();
}

void GameSceneManager::handleEvent(SDL_Event& e) {
	for (auto &scene : scenes_) {
		if (!scene->isMarkedForDeletion()) {
			scene->handleEvent(e);
		} else {
			delete scene;
			scenes_.remove(scene);
		}
	}
}

void GameSceneManager::render() {
	if (!GameSceneManager::isEmpty()) {
		for (auto &scene : scenes_) {
			if (!scene->isMarkedForDeletion()) {
				scene->render();
			}
		}
	}
}

void GameSceneManager::pushScene(SceneID id) {
	switch(id) {
		case SceneID::TITLE:
			scenes_.push_front(new SceneTitle(renderer_, *this, resManager_));
			break;
		case SceneID::BOARD:
			scenes_.push_front(new SceneBoard(renderer_, *this, resManager_));
			break;
	}
}

void GameSceneManager::changeScene(SceneID id) {
	scenes_.front()->markForDeletion();

	this->pushScene(id);
}

bool GameSceneManager::isEmpty() {
	return scenes_.empty();
}

void GameSceneManager::quit() {
	willExit_ = true;
}

bool GameSceneManager::onLoop() {
	if (willExit_) return false;

	for (auto &scene : scenes_) {
		if (scene->isMarkedForDeletion()) {
			delete scene;
			scenes_.remove(scene);
		}
	}

	return true;
}
