#include "GameOverState.h"
#include "Text.h"
#include "Engine.h"
#include "Sprite.h"
#include "IntroState.h"
#include "System.h"
#include <iostream>

namespace cwing {

	GameOverState::GameOverState(): GameState() {
		//nextState = IntroState::getInstance();
	}

	std::unique_ptr<GameState> GameOverState::getInstance() {
		return std::make_unique<GameOverState>();
	}

	void GameOverState::enterState() {
		if(sys.getOrientation() == "H"){
			Sprite* gOver = Text::getIntance(295, 100, "GAME OVER!", 60);
			Sprite* pAgain = Text::getIntance(310, 450, "Press ESC to Quit", 40);
			ge.add(gOver);
			ge.add(pAgain);	
		} else {
			Sprite* gOver = Text::getIntance(145, 300, "GAME OVER!", 60);
			Sprite* pAgain = Text::getIntance(150, 490, "Press ESC to Quit", 40);
			ge.add(gOver);
			ge.add(pAgain);
		}
	}

	void GameOverState::updateState() {
		//std::cout << "GameOver" << std::endl;
	}

	void GameOverState::exitState() {
		for (Sprite* s : ge.getSprites()) {
			if(s->getSpriteType() == "text" || s->getSpriteType() == "score"){
				ge.remove(s);
			}
/* 			if (Text* t = dynamic_cast<Text*>(s)) { 
				ge.remove(t);
			} */
		}
	}

	void GameOverState::stateEvents(SDL_Event& event) {
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
			//std::unique_ptr<GameState> is = std::make_unique<IntroState>();
			ge.getQuit() = true;
		}
	}

	void GameOverState::renderState() {
		for (Sprite* s : ge.getSprites()) {
			s->draw();
		}
	}

	GameOverState::~GameOverState() {
		//delete nextState;
	}
}

