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

int CFWindow::getWidth() const {
	int width;
	SDL_GetWindowSize(window_, &width, nullptr);

	return width;
}

int CFWindow::getHeight() const {
	int height;
	SDL_GetWindowSize(window_, nullptr, &height);

	return height;
}

void CFWindow::close() {
	SDL_DestroyWindow(window_);
	window_ = nullptr;
}
