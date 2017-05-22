#include "CFTexture.h"

#include <SDL_image.h>
#include <SDL_ttf.h>

#include "res_path.h"

CFTexture::CFTexture(const CFRenderer& renderer) : renderer_(renderer), texture_(nullptr), width_(0), height_(0), scale_(1) {}

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

bool CFTexture::loadFromFile(std::string imageFileName) {
	CFTexture::close();

	std::string path = getResourcePath() + imageFileName;

	SDL_Surface* imgSurface = IMG_Load(path.c_str());

	if (imgSurface == nullptr) {
		//Log error: IMG_Load
		return false;
	} else {
		CFTexture::load(imgSurface);
	}

	return (texture_ != nullptr);
}

bool CFTexture::loadFromRenderedText(std::string fontFileName, std::string text, SDL_Color textColor, int pointSize) {
	CFTexture::close();

	std::string path = getResourcePath() + fontFileName;
	static TTF_Font* font = TTF_OpenFont(path.c_str(), pointSize);

	if (font == nullptr) {
		//Log error: TTF_OpenFont
		return false;
	}

	SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), textColor);

	if (textSurface == nullptr) {
		//Log error: TTF_RenderText_Solid
		return false;
	} else {
		CFTexture::load(textSurface);
	}

	return (texture_ != nullptr);
}

void CFTexture::render(int x, int y, SDL_Rect* clip) {
	SDL_Rect renderQuad = {x, y, this->getWidth(), this->getHeight()};

	if (clip != nullptr) {
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	renderer_.render(texture_, clip, &renderQuad);
}

void CFTexture::setScale(double scale) {
	if (scale == 0) {
		//TODO: error
	} else {
		scale_ = scale;
	}
}

int CFTexture::getWidth() const {
	return (int) (width_ * scale_);
}

int CFTexture::getHeight() const {
	return (int) (height_ * scale_);
}
