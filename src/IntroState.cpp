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
		//nextState = PlayState::getInstance();
	}

	std::unique_ptr<GameState> IntroState::getInstance() {
		return std::make_unique<IntroState>();
	}

	void IntroState::enterState() {
		if(sys.getOrientation() == "H"){
			Text* title = Text::getIntance(375, 100, "PONG.", 70);
			Text* serve = Text::getIntance(350, 350, "Press SPACE to serve", 20);
			Text* lp_move = Text::getIntance(100, 400, "Use W and S to move", 20);
			Text* rp_move = Text::getIntance(510, 400, "Use arrow UP and arrow DOWN to move", 20);
			ge.add(title);
			ge.add(serve);
			ge.add(lp_move);
			ge.add(rp_move);
		} else {
			Text* title = Text::getIntance(220, 330, "PONG.", 70);
			Text* serve = Text::getIntance(210, 530, "Press SPACE to serve", 20);
			Text* topp_move = Text::getIntance(210, 110, "Use W and S to move", 20);
			Text* bottomp_move = Text::getIntance(130, 750, "Use arrow UP and arrow DOWN to move", 20);
			ge.add(title);
			ge.add(serve);
			ge.add(topp_move);
			ge.add(bottomp_move);
		}
	}

	void IntroState::updateState() {
		//std::cout << "Intro" << std::endl;
	}

	void IntroState::exitState() {
/* 		for (Sprite* s : ge.getSprites()) {
			if (Text* t = dynamic_cast<Text*>(s)) { 
				ge.remove(s);
			}
		} */
		for (Sprite* s : ge.getSprites()) {
			if (s->getSpriteType() == "score" || s->getSpriteType() == "text") {  //??? score ???
				ge.remove(s);
			}
		}
	}

	void IntroState::stateEvents(SDL_Event& event) {
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE) {
			//std::unique_ptr<GameState> ps = std::make_unique<PlayState>();
			//setNextState(std::move(ps));
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
		//delete nextState;
		//delete getNextState();
	}
}

