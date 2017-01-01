#include "GameState/StateTitle.h"

#include <SDL_events.h>
#include <SDL_keyboard.h>
#include <SDL_mouse.h>
#include <SDL_rect.h>

StateTitle::StateTitle(GameStateManager& stateManager, CFRenderer& renderer) :
	GameState(stateManager, renderer), title_(renderer), background_(renderer) {
		background_.loadFromFile("C4Background.png");
		title_.loadFromFile("C4Connect4.png");
	}

void StateTitle::handleEvents() {
	SDL_Event e;

	while (SDL_PollEvent(&e) != 0) {
		if (e.type == SDL_MOUSEBUTTONDOWN) {
			stateManager_.changeState(StateID::BOARD);
		} else if (e.type == SDL_QUIT ||
			(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)) {
			stateManager_.emptyStates();
		}
	}
}

void StateTitle::update() {}

void StateTitle::render() {
	/*************************
	 * RENDER BACKGROUND
	 ************************/
	int windowW = renderer_.getWindowWidth();
	int windowH = renderer_.getWindowHeight();
	static const int tileW = background_.getWidth();
	static const int tileH = background_.getHeight();

	//The number of tiles is the amount of tiles that can fit horizontally and vertically,
	//while adding an extra row and column to make room for the scrolling animation.
	const int numTilesX = (windowW / tileW) + 1;
	const int numTilesY = (windowH / tileH) + 1;

	static int frameCount = 0;

	for (int x = 0; x < numTilesX; x++) {
		for (int y = 0; y < numTilesY; y++) {
			background_.render(x * tileW - frameCount, y * tileH - frameCount);
		}
	}

	if (++frameCount > tileW) {
		frameCount = 0;
	}

	/*************************
	 * RENDER TITLE
	 ************************/
	title_.render((windowW - title_.getWidth()) * (0.5), (windowH - title_.getHeight()) * (0.25));
}
