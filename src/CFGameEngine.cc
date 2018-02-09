#include "CFGameEngine.h"

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "GameScene/GameScene.h"
#include "CFRenderer.h"
#include "CFTexture.h"
#include "GameBoard.h"

CFGameEngine::CFGameEngine() : window_(nullptr), renderer_(nullptr), resManager_(nullptr), sceneManager_(nullptr) {}

CFGameEngine::~CFGameEngine() {
	delete resManager_;
	resManager_ = nullptr;

	//TODO: RAII
	renderer_->close();
	renderer_ = nullptr;

	window_->close();
	window_ = nullptr;

	delete sceneManager_;
	sceneManager_ = nullptr;

	SDL_Quit();
}

bool CFGameEngine::OnInit() {
	/* Initialize SDL */
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		//Error: SDL_Init
		return false;
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
	if ((IMG_Init(imgFlags) & imgFlags) == 0) {
		//Log error: IMG_Init
		return false;
	}

	/* Initialize SDL_ttf */
	if (TTF_Init() < 0) {
		//Log error: TTF_Init
		return false;
	}

	resManager_ = new ResourceManager(*renderer_);

	sceneManager_ = new GameSceneManager(*renderer_, *resManager_);

	return true;
}

void CFGameEngine::OnEvent(SDL_Event &e) {
	sceneManager_->handleEvent(e);
}

bool CFGameEngine::OnLoop() {
	return sceneManager_->onLoop();
}

void CFGameEngine::OnRender() {
	renderer_->clear();

	sceneManager_->render();

	renderer_->present();
}

void CFGameEngine::OnCleanup() {

}

int CFGameEngine::OnExecute() {
	if (!OnInit()) {
		return -1;
	}

	sceneManager_->pushScene(SceneID::TITLE);

	Uint32 frameTime;
	SDL_Event event{};

	while (true) {
		frameTime = SDL_GetTicks();

		/***************
		 * INPUT
		 ***************/

		while (SDL_PollEvent(&event) != 0) {
			OnEvent(event);
		}

		if (!OnLoop()) break;

		/***************
		 * RENDERING
		 ***************/

		OnRender();

		/***************
		 * TIMING
		 ***************/

		Uint32 ticks = SDL_GetTicks() - frameTime;

		if (ticks < 1000.0 / 60.0) {
			SDL_Delay((Uint32) (1000.0 / 60.0 - ticks));
		}
	}

	return 0;
}
