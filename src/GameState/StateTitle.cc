#include "GameState/StateTitle.h"

StateTitle::StateTitle(GameStateManager& stateManager, CFRenderer& renderer) :
	GameState(stateManager, renderer) {}

int StateTitle::handleEvents() {
	return 1;
}

void StateTitle::update() {}

void StateTitle::render() {}
