#ifndef _CFWINDOW_H
#define _CFWINDOW_H

#include <SDL_video.h>

#include "CFRenderer.h"

class CFRenderer;

class CFWindow {
public:
	explicit CFWindow(const char* title, int width = 640, int height = 480);
	~CFWindow();

	/**
	 * Create CFRenderer with hardware acceleration and vsync enabled.
	 *
	 * @return CFRenderer to render to.
	 */
	CFRenderer* createRenderer();

	/**
	 * Get the current width of the window.
	 *
	 * @return The current width of the window.
	 */
	int getWidth() const;

	/**
	 * Get the current height of the window.
	 *
	 * @return The height of the window.
	 */
	int getHeight() const;

	/**
	 * Destroy window.
	 */
	void close();
private:
	SDL_Window* window_;
};

#endif
