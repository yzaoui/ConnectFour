#include "CFTexture.h"

#include <SDL_image.h>
#include <SDL_ttf.h>

#include "res_path.h"

CFTexture::CFTexture(CFRenderer& renderer) : renderer_(renderer) {
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

void CFTexture::load(SDL_Surface* surface) {
	//Create texture from surface
	texture_ = renderer_.createTextureFromSurface(surface);

	if (texture_ == nullptr) {
		//Log error: SDL_CreateTextureFromSurface
	} else {
		width_ = surface->w;
		height_ = surface->h;
	}

	//Free old surface
	SDL_FreeSurface(surface);
}

bool CFTexture::loadFromFile(std::string fileName) {
	CFTexture::close();

	std::string path = getResourcePath() + fileName;

	SDL_Surface* imgSurface = IMG_Load(path.c_str());

	if (imgSurface == nullptr) {
		//Log error: IMG_Load
	} else {
		CFTexture::load(imgSurface);
	}

	return (texture_ != nullptr);
}

bool CFTexture::loadFromRenderedText(std::string textureText, SDL_Color textColor) {
	CFTexture::close();

	SDL_Surface* textSurface;// = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);

	if (textSurface == nullptr) {
		//Log error: TTF_RenderText_Solid
	} else {
		CFTexture::load(textSurface);
	}

	return (texture_ != nullptr);
}

void CFTexture::render(int x, int y, SDL_Rect* clip) {
	SDL_Rect renderQuad = {x, y, width_, height_};

	if (clip != nullptr) {
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	renderer_.render(texture_, clip, &renderQuad);
}

int CFTexture::getWidth() const {
	return width_;
}

int CFTexture::getHeight() const {
	return height_;
}
