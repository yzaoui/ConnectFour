#include "GameState/GameStateManager.h"

#include "GameState/StateBoard.h"

GameStateManager::GameStateManager(CFRenderer& renderer) : renderer_(renderer) {}

void GameStateManager::handleEvents() {
	int code = states_[0]->handleEvents();

	if (code == 0) {
		delete states_[0];
		states_.pop_back();
	}
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
		case StateID::BOARD:
			states_.push_back(new StateBoard(renderer_));
			break;
	}
}

bool GameStateManager::isEmpty() {
	return states_.empty();
}
