#include "GameScene/SceneTitle.h"

#include <SDL_events.h>
#include <SDL_keyboard.h>
#include <SDL_mouse.h>
#include <SDL_rect.h>

SceneTitle::SceneTitle(CFRenderer& renderer, GameSceneManager& sceneManager, ResourceManager& resManager) :
	GameScene(renderer, sceneManager, resManager), title_(renderer), background_(renderer), start_(nullptr), quit_(nullptr) {
		background_.loadFromFile("C4Background.png");
		background_.setScale(4);
		title_.loadFromFile("C4Connect4.png");
        start_ = Button(resManager.load("MenuButton.png"));
        quit_ = Button(resManager.load("MenuButtonDefault.png"));
	}

void SceneTitle::handleEvents() {
	SDL_Event e;

	while (SDL_PollEvent(&e) != 0) {
		if (e.type == SDL_MOUSEBUTTONDOWN) {
			sceneManager_.changeScene(SceneID::BOARD);
		} else if (e.type == SDL_QUIT ||
			(e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)) {
			sceneManager_.emptyScenes();
		}
	}
}

void SceneTitle::update() {}

void SceneTitle::render() {
	/*************************
	 * RENDER BACKGROUND
	 ************************/
	int windowW = renderer_.getWindowWidth();
	int windowH = renderer_.getWindowHeight();
	static const int tileW = background_.getWidth();
	static const int tileH = background_.getHeight();

	// The number of tiles is the amount of tiles that can fit horizontally and vertically,
	// while adding an extra row and column to make room for the scrolling animation.
	// The ratio should be rounded up to the nearest integer.
	const int numTilesX = ((windowW % tileW) ? windowW / tileW + 1 : windowW / tileW) + 1;
	const int numTilesY = ((windowH % tileH) ? windowH / tileH + 1 : windowH / tileH) + 1;

	static int frameCount = 0;

	for (int x = 0; x < numTilesX; x++) {
		for (int y = 0; y < numTilesY; y++) {
			background_.render(x * tileW - frameCount, y * tileH - frameCount);
		}
	}

	if (++frameCount > tileW) {
		frameCount = 0;
	}

	/*************************
	 * RENDER TITLE
	 ************************/
	title_.render((int) ((windowW - title_.getWidth()) * (0.5)), (int) ((windowH - title_.getHeight()) * (0.25)));

	/*************************
	 * RENDER BUTTONS
	 ************************/
	start_.setXY((windowW - start_.getWidth()) / 2, (windowH - start_.getHeight()) / 2);
	start_.render();
}
