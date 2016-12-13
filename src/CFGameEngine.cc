#include "CFGameEngine.h"

#include <iostream>

#include "CFRenderer.h"
#include "CFTexture.h"
#include "GameBoard.h"
#include "SDL.h"
#include "SDL_image.h"

CFGameEngine::CFGameEngine() : window_(nullptr), renderer_(nullptr) {
	/* Initialize SDL */
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		//Error: SDL_Init
	}

	/* Linear Texture Filtering */
	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
		//Warning: SDL_SetHint
	}

	window_ = new CFWindow("Connect Four", SCREEN_WIDTH, SCREEN_HEIGHT);

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
	bool quit = false;
	SDL_Event e;

	GameBoard board;

	CFTexture boxEmpty(renderer_);
	boxEmpty.loadFromFile("C4Empty.png");
	CFTexture boxYellow(renderer_);
	boxYellow.loadFromFile("C4Yellow.png");
	CFTexture boxRed(renderer_);
	boxRed.loadFromFile("C4Red.png");

	const int BOX_SIZE = boxEmpty.getWidth();
	const int NUM_BOXES_HORIZONTAL = board.getBoxesHorizontal();
	const int NUM_BOXES_VERTICAL = board.getBoxesVertical();
	const int BOARD_OFFSET_WIDTH = (SCREEN_WIDTH - BOX_SIZE * NUM_BOXES_HORIZONTAL) / 2;
	const int BOARD_OFFSET_HEIGHT = (SCREEN_HEIGHT - BOX_SIZE * NUM_BOXES_VERTICAL) / 2;

	uint8_t frameTime;

	while (!quit) {
		frameTime = SDL_GetTicks();

		/***************
		 * INPUT
		 ***************/

		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT ||
				(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)) {
				quit = true;
			} else if (e.type == SDL_MOUSEBUTTONDOWN) {
				int x;
				SDL_GetMouseState(&x, nullptr);

				if (x > BOARD_OFFSET_WIDTH && x < SCREEN_WIDTH - BOARD_OFFSET_WIDTH) {
					board.play((x - BOARD_OFFSET_WIDTH) / BOX_SIZE);
				}
			}
		}

		/***************
		 * RENDERING
		 ***************/

		renderer_->clear();

		for (int x = 0; x < NUM_BOXES_HORIZONTAL; x++) {
			for (int y = 0; y < NUM_BOXES_VERTICAL; y++) {
				switch (board.getBox(x, y)) {
					case Box::empty:
						boxEmpty.render(BOARD_OFFSET_WIDTH + x * BOX_SIZE, BOARD_OFFSET_HEIGHT + y * BOX_SIZE);
						break;
					case Box::yellow:
						boxYellow.render(BOARD_OFFSET_WIDTH + x * BOX_SIZE, BOARD_OFFSET_HEIGHT + y * BOX_SIZE);
						break;
					case Box::red:
						boxRed.render(BOARD_OFFSET_WIDTH + x * BOX_SIZE, BOARD_OFFSET_HEIGHT + y * BOX_SIZE);
						break;
				}
			}
		}

		renderer_->present();

		/***************
		 * TIMING
		 ***************/

		int ticks = SDL_GetTicks() - frameTime;

		if (ticks < 1000.0 / 60.0) {
			SDL_Delay(1000.0 / 60.0 - ticks);
		}
	}
}
