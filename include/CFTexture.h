#ifndef _CFTEXTURE_H
#define _CFTEXTURE_H

#include <SDL_render.h>
#include <string>

#include "CFRenderer.h"

class CFTexture {
public:
	CFTexture(CFRenderer*&);
	~CFTexture();
	void close();

	bool loadFromFile(std::string fileName);
	void render(int x, int y, SDL_Rect* clip = nullptr);

	int getWidth() const;
	int getHeight() const;
private:
	SDL_Texture* texture_;
	CFRenderer*& renderer_;
	int width_;
	int height_;
};

#endif
