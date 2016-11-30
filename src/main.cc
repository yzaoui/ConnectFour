#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "CFTexture.h"
#include "CFWindow.h"
#include "GameBoard.h"

CFWindow* window;
CFRenderer* renderer;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

void init() {
	/* Initialize SDL */
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		throw "Error: SDL_Init";
	}

	/* Linear Texture Filtering */
	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
		std::cout << "Warning: SDL_SetHint" << std::endl;
	}

	window = new CFWindow("Connect Four", SCREEN_WIDTH, SCREEN_HEIGHT);

	renderer = window->createRenderer();
	renderer->setRenderDrawColor(0xFF, 0xFF, 0xFF, 0xFF);

	/* Initialize PNG loading */
	const int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags)) {
		//Log error
	}
}

void close() {
	renderer->close();
	renderer = nullptr;

	window->close();
	window = nullptr;

	SDL_Quit();
}

int main(int argc, char** argv) {
	try {
		init();

		bool quit = false;
		SDL_Event e;

		GameBoard board;

		CFTexture boxEmpty(renderer);
		boxEmpty.loadFromFile("C4Empty.png");
		CFTexture boxYellow(renderer);
		boxYellow.loadFromFile("C4Yellow.png");
		CFTexture boxRed(renderer);
		boxRed.loadFromFile("C4Red.png");

		const int BOX_SIZE = boxEmpty.getWidth();
		const int BOARD_OFFSET_WIDTH = (SCREEN_WIDTH - BOX_SIZE * NUM_BOXES_HORIZONTAL) / 2;
		const int BOARD_OFFSET_HEIGHT = (SCREEN_HEIGHT - BOX_SIZE * NUM_BOXES_VERTICAL) / 2;

		uint8_t frameTime;

		while (!quit) {
			frameTime = SDL_GetTicks();

			/***************
			 * INPUT
			 ***************/

			while (SDL_PollEvent(&e) != 0) {
				if (e.type == SDL_QUIT) {
					quit = true;
				}
			}

			/***************
			 * RENDERING
			 ***************/

			renderer->clear();

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

			renderer->present();

			/***************
			 * TIMING
			 ***************/

			int ticks = SDL_GetTicks() - frameTime;

			if (ticks < 1000.0 / 60.0) {
				SDL_Delay(1000.0 / 60.0 - ticks);
			}
		}
	} catch (const char*& e) {
		std::cout << e << std::endl;
	}

	close();
	return 0;
}
