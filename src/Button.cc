#include "Button.h"

Button::Button(CFTexture* texture) : texture_(texture), x_(0), y_(0), w_(200), h_(50), state_(ButtonID::DEFAULT) {
	maps_.insert({ButtonID::DEFAULT, {0, 0, 200, 50}});
	maps_.insert({ButtonID::HOVER, {200, 0, 200, 50}});
	rect_ = maps_.at(state_);
}

void Button::setXY(int x, int y) {
	x_ = x;
	y_ = y;
}

void Button::render() {
	this->texture_->render(x_, y_, &rect_);
}

bool Button::handleEvent(const SDL_Event& e) {
	if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN) {
		int x, y;
		SDL_GetMouseState(&x, &y);

		// If within button bounds
		if (x > x_ && x < x_ + w_ && y > y_ && y < y_ + h_) {
			if (e.type == SDL_MOUSEBUTTONDOWN) {
				this->onClick_();
			} else {
				if (state_ != ButtonID::HOVER) {
					rect_ = maps_.at(state_ = ButtonID::HOVER);
				}
			}

			return true;
		}

		if (state_ != ButtonID::DEFAULT)
		rect_ = maps_.at(state_ = ButtonID::DEFAULT);
	}

	return false;
}

int Button::getWidth() {
	return this->w_;
}

int Button::getHeight() {
	return this->h_;
}

void Button::addClickEvent(std::function<void ()> onClick) {
	this->onClick_ = std::move(onClick);
}
