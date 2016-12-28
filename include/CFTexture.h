#ifndef _CFTEXTURE_H
#define _CFTEXTURE_H

#include <SDL_pixels.h>
#include <SDL_render.h>
#include <SDL_surface.h>
#include <string>

#include "CFRenderer.h"

class CFTexture {
public:
	CFTexture(CFRenderer&);
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
	 * Load texture from text.
	 *
	 * @param  textureText The text to load.
	 * @param  textColor   The color of the text to load.
	 *
	 * @return             Whether the texture was successfully loaded.
	 */
	bool loadFromRenderedText(std::string textureText, SDL_Color textColor);

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

private:
	void load(SDL_Surface* surface);

	/**
	 * Destroy texture.
	 */
	void close();

	SDL_Texture* texture_;
	const CFRenderer& renderer_;
	int width_;
	int height_;
};

#endif
