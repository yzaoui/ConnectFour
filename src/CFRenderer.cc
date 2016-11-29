#include "CFRenderer.h"

CFRenderer::CFRenderer(SDL_Renderer* renderer) : renderer_(renderer) {}

void CFRenderer::setRenderDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
	SDL_SetRenderDrawColor(renderer_, r, g, b, a);
}

void CFRenderer::clear() {
	SDL_RenderClear(renderer_);
}

void CFRenderer::present() {
	SDL_RenderPresent(renderer_);
}

void CFRenderer::render(SDL_Texture* texture, SDL_Rect* renderQuad) {
	SDL_RenderCopy(renderer_, texture, nullptr, renderQuad);
}

SDL_Texture* CFRenderer::createTextureFromSurface(SDL_Surface* surface) {
	return SDL_CreateTextureFromSurface(renderer_, surface);
}

void CFRenderer::close() {
	SDL_DestroyRenderer(renderer_);
}
