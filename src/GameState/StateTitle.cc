#include "GameState/StateTitle.h"

#include "SDL_events.h"
#include "SDL_mouse.h"
#include "SDL_keyboard.h"

StateTitle::StateTitle(GameStateManager& stateManager, CFRenderer& renderer) :
	GameState(stateManager, renderer), title_(renderer) {
		title_.loadFromFile("fields.png");
	}

void StateTitle::handleEvents() {
	SDL_Event e;

	while (SDL_PollEvent(&e) != 0) {
		if (e.type == SDL_MOUSEBUTTONDOWN) {
			stateManager_.changeState(StateID::BOARD);
		}
	}
}

void StateTitle::update() {}

void StateTitle::render() {
	title_.render(0, 0);
}
