#include "GameState/GameState.h"

GameState::GameState(GameStateManager& stateManager, CFRenderer& renderer) :
	stateManager_(stateManager), renderer_(renderer) {}

GameState::~GameState() {}
