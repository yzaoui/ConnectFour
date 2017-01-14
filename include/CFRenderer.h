#ifndef _CFRENDERER_H
#define _CFRENDERER_H

#include <SDL_render.h>

#include "CFWindow.h"

class CFWindow;

class CFRenderer {
	friend class CFWindow;
public:
	/**
	 * Set the color used for drawing operations (Rect, Line, and Clear).
	 *
	 * @param r The red component used to draw on the rendering target.
	 * @param g The green component used to draw on the rendering target.
	 * @param b The blue component used to draw on the rendering target.
	 * @param a The alpha component used to draw on the rendering target.
	 */
	void setRenderDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

	/**
	 * Clear the rendering target with the drawing color.
	 */
	void clear();

	/**
	 * Update the screen with the rendering performed.
	 */
	void present();

	/**
	 * Copy an entire texture to a destination rectangle of the rendering target.
	 *
	 * @param texture    The source texture.
	 * @param renderQuad The source rectangle.
	 * @param renderQuad The destination rectangle.
	 */
	void render(SDL_Texture* texture, SDL_Rect* clip, SDL_Rect* renderQuad) const;

	/**
	 * Create a texture from an existing surface.
	 *
	 * @param  surface The surface containing pixel data used to fill the texture.
	 *
	 * @return         The created texture is returned.
	 */
	SDL_Texture* createTextureFromSurface(SDL_Surface* surface) const;

	/**
	 * Get the width of the window the renderer is in.
	 *
	 * @return The window width.
	 */
	int getWindowWidth() const;

	/**
	 * Get the height of the window the renderer is in.
	 *
	 * @return The window height.
	 */
	int getWindowHeight() const;

	/**
	 * Destroy rendering context for window, free associated textures.
	 */
	void close();
private:
	CFRenderer(SDL_Renderer*, CFWindow&);
	SDL_Renderer* renderer_;
	const CFWindow& window_;
};

#endif
