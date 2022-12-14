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

	IntroState* IntroState::getInstance() {
		return new IntroState();
	}

	void IntroState::enterState() {
		Text* title = Text::getIntance(420, 100, "PONG.", 70);
		Text* serve = Text::getIntance(410, 350, "Press SPACE to serve", 20);
		Text* lp_move = Text::getIntance(100, 400, "Use W and S to move", 20);
		Text* rp_move = Text::getIntance(600, 400, "Use arrow UP and arrow DOWN to move", 20);
		ge.add(title);
		ge.add(serve);
		ge.add(lp_move);
		ge.add(rp_move);
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
			if (s->getSpriteType() == "score" || s->getSpriteType() == "text") { 
				ge.remove(s);
			}
		}
	}

	void IntroState::stateEvents(SDL_Event& event) {
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE) {
			setNextState(PlayState::getInstance());
		}
	}

	void IntroState::renderState() {
		//sys.drawSysBG(); //ritar bakgrund, �ndra??

		for (Sprite* s : ge.getSprites()) { 
			if(s->getSpriteType() != "score"){ // och ball?
				s->draw();
			}
/* 			if (Ball* b = dynamic_cast<Ball*>(s)) { // hitta s�tt att kolla om det �r false och inte s� h�r
				;  
			} else if (Score* sc = dynamic_cast<Score*>(s)) {
				;
			} else {
				s->draw();
			} */
		}
	}

}