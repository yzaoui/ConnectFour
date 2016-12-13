#ifndef _CFGAMEENGINE_H
#define _CFGAMEENGINE_H

#include <vector>

#include "CFRenderer.h"
#include "CFWindow.h"

class CFGameEngine {
public:
	CFGameEngine();
	~CFGameEngine();
	void run();
private:
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	CFWindow* window_;
	CFRenderer* renderer_;
};

#endif
