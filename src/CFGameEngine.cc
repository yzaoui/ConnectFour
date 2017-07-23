#include "CFGameEngine.h"

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "GameScene/GameScene.h"
#include "CFRenderer.h"
#include "CFTexture.h"
#include "GameBoard.h"

CFGameEngine::CFGameEngine() : window_(nullptr), renderer_(nullptr), resManager_(nullptr) {
	/* Initialize SDL */
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		//Error: SDL_Init
	}

	/* Linear Texture Filtering */
	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0")) {
		//Warning: SDL_SetHint
	}

	window_ = new CFWindow("Connect Four");

	renderer_ = window_->createRenderer();
	renderer_->setRenderDrawColor(0xFF, 0xFF, 0xFF, 0xFF);

	/* Initialize PNG loading */
	const int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags)) {
		//Log error: IMG_Init
	}

	/* Initialize SDL_ttf */
	if (TTF_Init() == -1) {
		//Log error: TTF_Init
	}

	resManager_ = new ResourceManager(*renderer_);
}

CFGameEngine::~CFGameEngine() {
	delete resManager_;
	resManager_ = nullptr;

	//TODO: RAII
	renderer_->close();
	renderer_ = nullptr;

	window_->close();
	window_ = nullptr;

	SDL_Quit();
}

void CFGameEngine::run() {
	GameSceneManager sceneManager(*renderer_, *resManager_);

	sceneManager.pushScene(SceneID::TITLE);

	Uint32 frameTime;

	while (true) {
		frameTime = SDL_GetTicks();

		/***************
		 * INPUT
		 ***************/

		sceneManager.handleEvents();

		if (sceneManager.isEmpty()) {
			break;
		}

		/***************
		 * RENDERING
		 ***************/

		renderer_->clear();

		sceneManager.render();

		renderer_->present();

		/***************
		 * TIMING
		 ***************/

		Uint32 ticks = SDL_GetTicks() - frameTime;

		if (ticks < 1000.0 / 60.0) {
			SDL_Delay((Uint32) (1000.0 / 60.0 - ticks));
		}
	}
}
