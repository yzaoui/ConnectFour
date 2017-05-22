#ifndef _BUTTON_H
#define _BUTTON_H

#include <SDL_events.h>
#include <SDL_rect.h>
#include <unordered_map>

#include "CFTexture.h"

enum class ButtonID {DEFAULT, HOVER};

class Button {
public:
	Button(CFTexture*);
	void setXY(int x, int y);
	void render();
	void handleEvent(SDL_Event*);
	int getWidth();
	int getHeight();
private:
	CFTexture* texture_;
	SDL_Rect rect_;
	std::unordered_map<ButtonID, SDL_Rect> maps_;
	int x_, y_, w_, h_;
};

#endif //_BUTTON_H
