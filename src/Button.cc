#include "Button.h"

Button::Button(CFTexture* texture) : texture_(texture), x_(0), y_(0), w_(200), h_(50) {
	maps_.insert({ButtonID::DEFAULT, {0, 0, 200, 50}});
	maps_.insert({ButtonID::HOVER, {200, 0, 200, 50}});
	rect_ = maps_.at(ButtonID::DEFAULT);
}

void Button::setXY(int x, int y) {
	x_ = x;
	y_ = y;
}

void Button::render() {
	this->texture_->render(x_, y_, &rect_);
}

void Button::handleEvent(SDL_Event* e) {
	if (e->type == SDL_MOUSEMOTION) {
		int x, y;
		SDL_GetMouseState(&x, &y);

		if (x > x_ && x < x_ + w_ && y > y_ && y < y_ + h_) {
			rect_ = maps_.at(ButtonID::HOVER);
		} else {
			rect_ = maps_.at(ButtonID::DEFAULT);
		}
	}
}

int Button::getWidth() {
	return this->w_;
}

int Button::getHeight() {
	return this->h_;
}
