#include "CFRenderer.h"

CFRenderer::CFRenderer(SDL_Renderer* renderer, CFWindow& window) : renderer_(renderer), window_(window) {}

void CFRenderer::setRenderDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
	SDL_SetRenderDrawColor(renderer_, r, g, b, a);
}

void CFRenderer::clear() {
	SDL_RenderClear(renderer_);
}

void CFRenderer::present() {
	SDL_RenderPresent(renderer_);
}

void CFRenderer::render(SDL_Texture* texture, SDL_Rect* clip, SDL_Rect* renderQuad) const {
	SDL_RenderCopy(renderer_, texture, clip, renderQuad);
}

SDL_Texture* CFRenderer::createTextureFromSurface(SDL_Surface* surface) const {
	return SDL_CreateTextureFromSurface(renderer_, surface);
}

int CFRenderer::getWindowWidth() const {
	return window_.getWidth();
}

int CFRenderer::getWindowHeight() const {
	return window_.getHeight();
}

void CFRenderer::close() {
	SDL_DestroyRenderer(renderer_);
	renderer_ = nullptr;
}
