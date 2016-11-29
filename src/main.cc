#include <iostream>
#include <SDL.h>

#include "CFWindow.h"

CFWindow* window;
CFRenderer* renderer;

void init() {
	/* Initialize SDL */
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		throw "Error: SDL_Init";
	}

	/* Linear Texture Filtering */
	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
		std::cout << "Warning: SDL_SetHint" << std::endl;
	}

	window = new CFWindow("Connect Four", 640, 480);

	renderer = window->createRenderer();
	renderer->setRenderDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
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

		while (!quit) {
			while (!SDL_PollEvent(&e) != 0) {
				if (e.type == SDL_QUIT) {
					quit = true;
				}
			}

			renderer->clear();
			renderer->present();
		}
	} catch (const char*& e) {
		std::cout << e << std::endl;
	}

	close();
	return 0;
}
