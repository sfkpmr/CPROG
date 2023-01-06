#include "PlayState.h"
#include "Sprite.h"
#include "Score.h"
#include "Engine.h"
#include "GameOverState.h"
#include <iostream>

namespace cwing {

	PlayState::PlayState(): GameState() {

	}

	std::unique_ptr<GameState> PlayState::getInstance() {
		return std::make_unique<PlayState>();
	}

	void PlayState::enterState() {
		Sprite* score_l = Score::getInstance(390, 15, 40, 2);
		Sprite* score_r = Score::getInstance(485, 15, 40, 1);
		ge.add(score_l);
		ge.add(score_r);
	}

	void PlayState::updateState() {
		for (Sprite* s : ge.getSprites()) {
			s->tick();
		}

		for (Sprite* s : ge.getSprites()) {
			if (s->getSpriteType() == "score") {
				Score* sc = dynamic_cast<Score*>(s);
				if(ge.getMaxScore() == 0) {
					if (sc->getScore() == 5) {
						setNextState(std::move(GameOverState::getInstance()));
					}
				} else {
					if (sc->getScore() == ge.getMaxScore()) {
						setNextState(std::move(GameOverState::getInstance()));
					}
				}
			}
		}
	}

	void PlayState::exitState() {
		for (int i = 0; i < 4; i++) { // fixar paddles går vid game over state, om key blev aldrig släppt
			ge.getKeyStateCheck()[i] = false;
		}
	}

	void PlayState::stateEvents(SDL_Event& event) {
		if (event.type == SDL_KEYDOWN) {
			for (Sprite* s : ge.getSprites()) {
				s->keyDown(event);
			}
		}
		if (event.type == SDL_KEYUP) {
			for (Sprite* s : ge.getSprites()) {
				s->keyUp(event);
			}
		}
	}

	void PlayState::renderState() {
		for (Sprite* s : ge.getSprites()) {
			s->draw();
		}
	}

	PlayState::~PlayState() {
		std::cout << "PlayState dest" << std::endl;
	}
}



