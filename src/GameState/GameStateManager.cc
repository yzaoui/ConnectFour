#include "GameState/GameStateManager.h"

#include "GameState/StateBoard.h"

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

void GameStateManager::pushState(StateID id, CFRenderer& renderer) {
	switch(id) {
		case StateID::BOARD:
			states_.push_back(new StateBoard(renderer));
	}
}

bool GameStateManager::isEmpty() {
	return states_.empty();
}
