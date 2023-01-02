#include "PlayState.h"
#include "Sprite.h"
#include "Ball.h"
#include "Score.h"
#include "Engine.h"
#include "System.h"
#include "GameOverState.h"
#include <iostream>

namespace cwing {

	PlayState::PlayState(): GameState() {
		//nextState = GameOverState::getInstance();
	}

	std::unique_ptr<GameState> PlayState::getInstance() {
		return std::make_unique<PlayState>();
	}

	void PlayState::enterState() {
		if(sys.getOrientation() == "H"){
			Sprite* score_l = Score::getInstance(390, 15, 40, 2);
			Sprite* score_r = Score::getInstance(485, 15, 40, 1);
			ge.add(score_l);
			ge.add(score_r);
		} else {
			Sprite* score_top = Score::getInstance(20, 400, 40, 2);
		    Sprite* score_bottom = Score::getInstance(560, 460, 40, 1);
		    ge.add(score_top);
		    ge.add(score_bottom);
		}
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
						//std::unique_ptr<GameState> gos = std::make_unique<GameOverState>();
						setNextState(std::move(GameOverState::getInstance()));
					}
				} else {
					if (sc->getScore() == ge.getMaxScore()) {
						//std::unique_ptr<GameState> gos = std::make_unique<GameOverState>();
						setNextState(std::move(GameOverState::getInstance()));
					}
				}
			}
		}
	}

	void PlayState::exitState() {
		for (int i = 0; i < 4; i++) { // fixar paddles går vid game over state, om key blev aldrig upp
			ge.getKeyStateCheck()[i] = false;
		}
		//for (Sprite* s : ge.getSprites()) {
		//	if (Score* sc = dynamic_cast<Score*>(s)) {
		//		ge.remove(s);
		//	}
		//}
		//for (Sprite* s : ge.getSprites()) {
		//	if (Ball* b = dynamic_cast<Ball*>(s)) {
		//		ge.remove(s);
		//	}
		//}
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
		std::cout << "Play dest" << std::endl;
	}
}



