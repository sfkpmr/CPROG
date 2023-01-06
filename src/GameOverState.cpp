#include "GameOverState.h"
#include "Text.h"
#include "Engine.h"
#include "Sprite.h"
#include <iostream>

namespace cwing {

	GameOverState::GameOverState(): GameState() {

	}

	std::unique_ptr<GameState> GameOverState::getInstance() {
		return std::make_unique<GameOverState>();
	}

	void GameOverState::enterState() {
		Sprite* gOver = Text::getIntance(295, 100, "GAME OVER!", 60);
		Sprite* pAgain = Text::getIntance(310, 450, "Press ESC to Quit", 40);
		ge.add(gOver);
		ge.add(pAgain);	
	}

	void GameOverState::updateState() {
		
	}

	void GameOverState::exitState() {
		for (Sprite* s : ge.getSprites()) {
			if(s->getSpriteType() == "text" || s->getSpriteType() == "score"){
				ge.remove(s);
			}
		}
	}

	void GameOverState::stateEvents(SDL_Event& event) {
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
			ge.getQuit() = true;
		}
	}

	void GameOverState::renderState() {
		for (Sprite* s : ge.getSprites()) {
			s->draw();
		}
	}

	GameOverState::~GameOverState() {
		std::cout << "GameOverState dest" << std::endl;
	}
}

