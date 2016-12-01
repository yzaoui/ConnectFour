#include "CFWindow.h"

CFWindow::CFWindow(const char* title, int width, int height) : window_(nullptr) {
	window_ = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	//Check if window_ is null
}

CFWindow::~CFWindow() {
	close();
}

CFRenderer* CFWindow::createRenderer() {
	SDL_Renderer* renderer = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (renderer == nullptr) {
		throw "Error: SDL_CreateRenderer";
	}

	return new CFRenderer(renderer);
}

void CFWindow::close() {
	SDL_DestroyWindow(window_);
}
