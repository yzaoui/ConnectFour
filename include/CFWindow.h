#ifndef _CFWINDOW_H
#define _CFWINDOW_H

#include <SDL_video.h>

#include "CFRenderer.h"

class CFRenderer;

class CFWindow {
public:
	CFWindow(const char* title, int width, int height);
	~CFWindow();

	CFRenderer* createRenderer();
	void close();
private:
	SDL_Window* window_;
};

#endif
