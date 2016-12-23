#include "CFGameEngine.h"

#include <iostream>

#include "SDL.h"
#include "SDL_image.h"

#include "GameState/GameState.h"
#include "CFRenderer.h"
#include "CFTexture.h"
#include "GameBoard.h"

CFGameEngine::CFGameEngine() : window_(nullptr), renderer_(nullptr) {
	/* Initialize SDL */
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		//Error: SDL_Init
	}

	/* Linear Texture Filtering */
	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
		//Warning: SDL_SetHint
	}

	window_ = new CFWindow("Connect Four");

	renderer_ = window_->createRenderer();
	renderer_->setRenderDrawColor(0xFF, 0xFF, 0xFF, 0xFF);

	/* Initialize PNG loading */
	const int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags)) {
		//Log error
	}
}

CFGameEngine::~CFGameEngine() {
	renderer_->close();
	renderer_ = nullptr;

	window_->close();
	window_ = nullptr;

	SDL_Quit();
}

void CFGameEngine::run() {
	GameStateManager stateManager(*renderer_);

	stateManager.pushState(StateID::BOARD);

	uint8_t frameTime;

	while (true) {
		frameTime = SDL_GetTicks();

		/***************
		 * INPUT
		 ***************/

		stateManager.handleEvents();

		if (stateManager.isEmpty()) {
			break;
		}

		/***************
		 * RENDERING
		 ***************/

		renderer_->clear();

		stateManager.render();

		renderer_->present();

		/***************
		 * TIMING
		 ***************/

		uint8_t ticks = SDL_GetTicks() - frameTime;

		if (ticks < 1000.0 / 60.0) {
			SDL_Delay(1000.0 / 60.0 - ticks);
		}
	}
}
