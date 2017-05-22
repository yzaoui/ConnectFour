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
	 * @param  imageFileName The name of the image file.
	 *
	 * @return          Whether the texture was successfully loaded.
	 */
	bool loadFromFile(std::string imageFileName);

	/**
	 * Load texture from text.
	 *
	 * @param  fontFileName The name of the font file.
	 * @param  text         The text to load.
	 * @param  textColor    The color of the text to load.
	 * @param  pointSize    The font size.
	 *
	 * @return              Whether the texture was successfully loaded or not.
	 */
	bool loadFromRenderedText(std::string fontFileName, std::string text, SDL_Color textColor, int pointSize);

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
	 * Scale the underlying texture.
	 *
	 * @param scale The scale to stretch the texture's width and height.
	 */
	void setScale(double scale);

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

	const CFRenderer& renderer_;
	SDL_Texture* texture_;
	int width_;
	int height_;
	double scale_;
};

#endif
