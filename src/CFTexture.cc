#include "CFTexture.h"

#include <SDL_image.h>

#include "res_path.h"

CFTexture::CFTexture(CFRenderer*& renderer) : renderer_(renderer) {
	texture_ = nullptr;
	width_ = 0;
	height_ = 0;
}

CFTexture::~CFTexture() {
	CFTexture::close();
}

void CFTexture::close() {
	if (texture_ != nullptr) {
		SDL_DestroyTexture(texture_);
		texture_ = nullptr;
		width_ = 0;
		height_ = 0;
	}
}

bool CFTexture::loadFromFile(std::string fileName) {
	CFTexture::close();

	std::string path = getResourcePath() + fileName;

	SDL_Surface* surface = IMG_Load(path.c_str());

	if (surface == nullptr) {
		//Log error
	} else {
		//Create texture from surface
		texture_ = renderer_->createTextureFromSurface(surface);

		if (texture_ == nullptr) {
			//Log error
		} else {
			width_ = surface->w;
			height_ = surface->h;
		}

		//Free old surface
		SDL_FreeSurface(surface);
	}

	return (texture_ != nullptr);
}

void CFTexture::render(int x, int y, SDL_Rect* clip) {
	SDL_Rect renderQuad = {x, y, width_, height_};

	if (clip != nullptr) {
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	renderer_->render(texture_, &renderQuad);
}

