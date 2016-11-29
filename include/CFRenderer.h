#ifndef _CFRENDERER_H
#define _CFRENDERER_H

#include <SDL_render.h>

#include "CFWindow.h"

class CFWindow;

class CFRenderer {
	friend class CFWindow;
public:
	void setRenderDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

	void clear();
	void present();

	void close();
private:
	CFRenderer(SDL_Renderer*);
	SDL_Renderer* renderer_;
};

#endif
