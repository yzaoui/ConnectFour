#include "GameState/GameStateManager.h"

#include "GameState/StateBoard.h"
#include "GameState/StateTitle.h"

GameStateManager::GameStateManager(CFRenderer& renderer) : renderer_(renderer) {}

void GameStateManager::handleEvents() {
	states_.back()->handleEvents();
}

void GameStateManager::render() {
	if (!GameStateManager::isEmpty()) {
		for (auto i = states_.begin(); i != states_.end(); i++) {
			(*i)->render();
		}
	}
}

void GameStateManager::pushState(StateID id) {
	switch(id) {
		case StateID::TITLE:
			states_.push_back(new StateTitle(*this, renderer_));
			break;
		case StateID::BOARD:
			states_.push_back(new StateBoard(*this, renderer_));
			break;
	}
}

void GameStateManager::changeState(StateID id) {
	delete states_.back();
	states_.pop_back();

	GameStateManager::pushState(id);
}

bool GameStateManager::isEmpty() {
	return states_.empty();
}
