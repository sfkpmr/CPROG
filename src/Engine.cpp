#include "Engine.h"
#include "System.h"
#include "IntroState.h"
#include <SDL2/SDL.h>

namespace cwing {
#define FPS 60 //antal frames per sekund. FPS för att kunna styra hastigheten av spelet, samt att hastigheten blir samma på olika datorer

	void Engine::add(Sprite* s) {
		added.push_back(s);  //vi adderar sprites först till en temporär vector först, för att slippa addera komponenter under loopens gång
	}

	void Engine::remove(Sprite* s) {
		removed.push_back(s); //adderar sprites till en temporär vector först, för att slippa ta bort komponenter under loopens gång
	}

	void Engine::run() {
		currentState = std::move(std::make_unique<IntroState>());
		currentState->enterState();

		quit = false; 
		Uint32 tInterval = 1000 / FPS; //hur många milisekunder programmet ska dröja mellan ticks
		while (!quit) {
			Uint32 nextTick = SDL_GetTicks() + tInterval; //nextTick räknar ur när nästa tick ska vara. SDL_GetTicks() returnerar antal milisekunder sen initieringen utav SDL
			SDL_Event eve;
			while (SDL_PollEvent(&eve) != 0) { 
				if (eve.type == SDL_QUIT) {
					quit = true;
				}
				currentState->stateEvents(eve);
			} 
		
			if (quit == true) {
				for (Sprite* s : sprites) {
					delete s;
				}
				break;
			}
			currentState->updateState();
			  
			currentState->changeState();

			for (Sprite* s : added) {
				sprites.push_back(s); //vi överför alla komponenter från added till comps när vi inte längre itererar över den
			}
			added.clear(); //rensar vektorn
			
			for (Sprite* s : removed) {
				for (std::vector<Sprite*>::iterator i = sprites.begin(); i != sprites.end();) {
					if (*i == s) { // vi kollar om pekaren c finns i removed vektorn och tar bort den
						delete *i;
						i = sprites.erase(i); //i= för att erase() returnerar iterator på det första elementet som är kvar i vektorn, efter i
					} else {
						i++; //i++ är i else då vi vill inte öka iteratorn om ett element tas bort
					}
				}
			}
			removed.clear();

			SDL_RenderClear(sys.getRen());
			sys.drawSysBG(); //ritar bakgrund
			currentState->renderState();
			//sen ska man skriva ut, presentera från renderaren till skärmen efter ritningen
			SDL_RenderPresent(sys.getRen());

			int delay = nextTick - SDL_GetTicks();
			if (delay > 0) { // delay är 0 eller negativ om det inte finns nåt kvar 
				SDL_Delay(delay);
			} 
			
		}//out while
	}

	const std::vector<Sprite*> Engine::getSprites() const {
		return sprites;
	}

	bool* Engine::getKeyStateCheck() {
		return keyStateCheck;
	}

	bool* Engine::getScoreCollision() {
		return scoreCollision;
	}

	bool& Engine::getQuit() {
		return quit;
	}

	void Engine::setMaxScore(int max){
		maxScore = max;
	}

	const int Engine::getMaxScore() const {
		return maxScore;
	}

	void Engine::setCurrentState(std::unique_ptr<GameState> state) {
		currentState = std::move(state);
	}

	GameState* Engine::getCurrentState() const {
		return currentState.get();
	}

	Engine ge;
}