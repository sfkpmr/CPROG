#include "IntroState.h"
#include "System.h"
#include "Sprite.h"
#include "Engine.h"
#include "Ball.h"
#include "Text.h"
#include "Score.h"
#include "PlayState.h"
#include <iostream>

namespace cwing {

	IntroState::IntroState(): GameState() {
		
	}

	std::unique_ptr<GameState> IntroState::getInstance() {
		return std::make_unique<IntroState>();
	}

	void IntroState::enterState() {
		Text* title = Text::getIntance(375, 100, "PONG.", 70);
		Text* serve = Text::getIntance(350, 350, "Press SPACE to serve", 20);
		Text* lp_move = Text::getIntance(100, 400, "Use W and S to move", 20);
		Text* rp_move = Text::getIntance(510, 400, "Use arrow UP and arrow DOWN to move", 20);
		ge.add(title);
		ge.add(serve);
		ge.add(lp_move);
		ge.add(rp_move);
	}

	void IntroState::updateState() {
		//std::cout << "Intro" << std::endl;
	}

	void IntroState::exitState() {
		for (Sprite* s : ge.getSprites()) {
			if (s->getSpriteType() == "score" || s->getSpriteType() == "text") {  
				ge.remove(s);
			}
		}
	}

	void IntroState::stateEvents(SDL_Event& event) {
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE) {
			setNextState(std::move(PlayState::getInstance()));
		}
	}

	void IntroState::renderState() {
		//sys.drawSysBG(); //ritar bakgrund, �ndra??

		for (Sprite* s : ge.getSprites()) { 
			if(s->getSpriteType() != "score"){ // och s->getSpriteType() != "ball" ??
				s->draw();
			}
		}
	}

	IntroState::~IntroState() {
		std::cout << "Intro-state dest" << std::endl;
	}
}

