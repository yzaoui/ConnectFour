#ifndef _BUTTON_H
#define _BUTTON_H

#include <functional>
#include <SDL_events.h>
#include <SDL_rect.h>
#include <unordered_map>

#include "CFTexture.h"

enum class ButtonID {DEFAULT, HOVER};

class Button {
public:
	explicit Button(CFTexture*);
	void setXY(int x, int y);
	void render();
	bool handleEvent(const SDL_Event&);
	int getWidth();
	int getHeight();

	void addClickEvent(std::function<void ()>);

private:
	CFTexture* texture_;
	SDL_Rect rect_;
	std::unordered_map<ButtonID, SDL_Rect> maps_;
	int x_, y_, w_, h_;
	std::function<void ()> onClick_;
	ButtonID state_;
};

#endif //_BUTTON_H
