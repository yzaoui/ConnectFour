#include "GameScene/SceneBoard.h"

#include <SDL.h>

SceneBoard::SceneBoard(CFRenderer& renderer, GameSceneManager& sceneManager, ResourceManager& resManager) :
	GameScene(renderer, sceneManager, resManager), boxEmpty_(renderer),
	boxYellow_(renderer), boxRed_(renderer) {
	boxEmpty_.loadFromFile("C4Empty.png");
	boxYellow_.loadFromFile("C4Yellow.png");
	boxRed_.loadFromFile("C4Red.png");

	BOX_SIZE = boxEmpty_.getWidth();
	NUM_BOXES_HORIZONTAL = board_.getBoxesHorizontal();
	NUM_BOXES_VERTICAL = board_.getBoxesVertical();
	BOARD_OFFSET_WIDTH = (renderer_.getWindowWidth() - BOX_SIZE * NUM_BOXES_HORIZONTAL) / 2;
	BOARD_OFFSET_HEIGHT = (renderer_.getWindowHeight() - BOX_SIZE * NUM_BOXES_VERTICAL) / 2;
}

void SceneBoard::handleEvent(SDL_Event &e) {
	if (e.type == SDL_QUIT) {
		sceneManager_.quit();
	} else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
		sceneManager_.changeScene(SceneID::TITLE);
	} else if (e.type == SDL_MOUSEBUTTONDOWN) {
		int mouseX;
		SDL_GetMouseState(&mouseX, nullptr);

		if (mouseX > BOARD_OFFSET_WIDTH && mouseX < renderer_.getWindowWidth() - BOARD_OFFSET_WIDTH) {
			board_.play((mouseX - BOARD_OFFSET_WIDTH) / BOX_SIZE);
		}
	}
}

void SceneBoard::update() {

}

void SceneBoard::render() {
	for (int x = 0; x < NUM_BOXES_HORIZONTAL; x++) {
		for (int y = 0; y < NUM_BOXES_VERTICAL; y++) {
			switch (board_.getBox(x, y)) {
				case Box::empty:
					boxEmpty_.render(BOARD_OFFSET_WIDTH + x * BOX_SIZE, BOARD_OFFSET_HEIGHT + y * BOX_SIZE);
					break;
				case Box::yellow:
					boxYellow_.render(BOARD_OFFSET_WIDTH + x * BOX_SIZE, BOARD_OFFSET_HEIGHT + y * BOX_SIZE);
					break;
				case Box::red:
					boxRed_.render(BOARD_OFFSET_WIDTH + x * BOX_SIZE, BOARD_OFFSET_HEIGHT + y * BOX_SIZE);
					break;
			}
		}
	}
}
