#ifndef _CFTEXTURE_H
#define _CFTEXTURE_H

#include <SDL_render.h>
#include <string>

#include "CFRenderer.h"

class CFTexture {
public:
	CFTexture(CFRenderer*&);
	~CFTexture();

	/**
	 * Load texture from file, assuming the working directory
	 * is "bin/" and resources are in "../res/".
	 *
	 * @param  fileName The name of the image file, including extension if necessary.
	 *
	 * @return          Whether the texture was successfully loaded.
	 */
	bool loadFromFile(std::string fileName);

	/**
	 * Render the current texture at a given position, or optionally passing
	 * a clip of the texture.
	 *
	 * @param x    The x-coordinate to render the texture to.
	 * @param y    The y-coordinate to render the texture to.
	 * @param clip The optional clip to render a portion of the texture.
	 */
	void render(int x, int y, SDL_Rect* clip = nullptr);

	/**
	 * Get the width of the texture.
	 *
	 * @return The texture's width.
	 */
	int getWidth() const;

	/**
	 * Get the height of the texture.
	 *
	 * @return The texture's height.
	 */
	int getHeight() const;

	/**
	 * Destroy texture.
	 */
	void close();
private:
	SDL_Texture* texture_;
	CFRenderer*& renderer_;
	int width_;
	int height_;
};

#endif
