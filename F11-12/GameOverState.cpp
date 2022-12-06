#include "GameOverState.h"
#include "Text.h"
#include "Engine.h"
#include "Sprite.h"
#include "IntroState.h"
#include <iostream>

namespace cwing {

	GameOverState::GameOverState(): GameState() {

	}

	GameOverState* GameOverState::getInstance() {
		return new GameOverState();
	}

	void GameOverState::enterState() {
		Text* gover = Text::getIntance(350, 100, "GAME OVER!", 60);
		Text* again = Text::getIntance(300, 450, "Press ENTER to play again", 40);
		ge.add(gover);
		ge.add(again);
	}

	void GameOverState::updateState() {
		//std::cout << "GameOver" << std::endl;
	}

	void GameOverState::exitState() {
		for (Sprite* s : ge.getSprites()) {
			if (Text* t = dynamic_cast<Text*>(s)) { 
				ge.remove(s);
			}
		}
	}

	void GameOverState::stateEvents(SDL_Event& event) {
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN) {
			setNextState(IntroState::getInstance());
		}
	}

	void GameOverState::renderState() {
		for (Sprite* s : ge.getSprites()) {
			s->draw();
		}
	}

}