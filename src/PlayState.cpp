#include "PlayState.h"
#include "Sprite.h"
#include "Ball.h"
#include "Score.h"
#include "Engine.h"
#include "GameOverState.h"
#include <iostream>

namespace cwing {

	PlayState::PlayState(): GameState() {

	}

	PlayState* PlayState::getInstance() {
		return new PlayState();
	}

	void PlayState::enterState() {
		Sprite* score_l = Score::getInstance(280, 30, 40, 2);
		Sprite* score_r = Score::getInstance(700, 30, 40, 1);
		ge.add(score_l);
		ge.add(score_r);
	}

	void PlayState::updateState() {
		//std::cout << "Play" << std::endl;
		for (Sprite* s : ge.getSprites()) {
			s->tick();
		}

		for (Sprite* s : ge.getSprites()) {
			if (Score* sc = dynamic_cast<Score*>(s)) {
				if (sc->getScore() == 5) {
					setNextState(GameOverState::getInstance());
				}
			}
		}
	}

	void PlayState::exitState() {
		for (int i = 0; i < 4; i++) { // fixar paddle g�r efter game over state, om key gick blev aldrig upp
			ge.getKeyStateCheck()[i] = false;
		}
/* 		for(Sprite* s : ge.getSprites()){
			if(s->getSpriteType() == "ball"){
				ge.remove(s);
			}
		} */
		//for (Sprite* s : ge.getSprites()) {
		//	if (Ball* b = dynamic_cast<Ball*>(s)) {
		//		ge.remove(s);
		//	}
		//}
	}

	void PlayState::stateEvents(SDL_Event& event) {
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			for (Sprite* s : ge.getSprites()) {
				s->mouseDown(event);
			}
		}
		if (event.type == SDL_MOUSEBUTTONUP) {
			for (Sprite* s : ge.getSprites()) {
				s->mouseUp(event);
			}
		}
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
		//switch (event.type) {
		//case SDL_MOUSEBUTTONDOWN: // kommer inte beh�vas??
		//	//efter att ha tagit emot h�ndelse i loopen g�r vi igenom alla komponent och anropar deras funktioner f�r 
		//	//att hantera den typen av h�ndelsen och de updaterar sig
		//	for (Sprite* s : ge.getSprites()) {
		//		s->mouseDown(event);
		//	}
		//	break;
		//case SDL_MOUSEBUTTONUP: // samma?
		//	for (Sprite* s : ge.getSprites()) {
		//		s->mouseUp(event);
		//	}
		//	break;
		//case SDL_KEYDOWN:
		//	for (Sprite* s : ge.getSprites()) {
		//		s->keyDown(event);
		//	}
		//	break;
		//case SDL_KEYUP:
		//	for (Sprite* s : ge.getSprites()) {
		//		s->keyUp(event);
		//	}
		//	break;
		//} //switch
	}

	void PlayState::renderState() {
		for (Sprite* s : ge.getSprites()) {
			s->draw();
		}
	}
}
