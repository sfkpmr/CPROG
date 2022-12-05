#include "Engine.h"
#include "Sprite.h"
#include <SDL.h>
#include "System.h"
#include "PlayState.h"
#include <iostream>
namespace cwing {

#define FPS 60 //antal frames per sekund. FPS för att kunna styra hastigheten av spelet, samt att hastigheten blir samma på olika datorer

	void Engine::add(Sprite* c) {
		added.push_back(c);  //vi adderar sprites först till en temporär vector, för att slippa addera komponenter under loopens gång
	}

	void Engine::remove(Sprite* c) {
		removed.push_back(c); //adderar sprites till en temporär vector först när de tas bort
		//std::cout << removed.size() << std::endl;
	}

	void Engine::run() {
		//GameState* currentState = IntroState::getInstance();
		//GameState* gState = new GameState();
		//GameState* currentState = gState->getCurrentState();
		//currentState = IntroState::getInstance();
		currentState = IntroState::getInstance();
		currentState->enterState();
		//currentState->setCurrentState(currentState);
		//currentState->getCurrentState()->enterState();
		bool quit = false; 
		Uint32 tInterval = 1000 / FPS; //hur många milisekunder programmet ska dröja mellan ticks
		while (!quit) {
			Uint32 nextTick = SDL_GetTicks() + tInterval; //nextTick räknar ur när nästa tick ska vara. SDL_GetTicks() returnerar antal milisekunder sen initieringen utav SDL
			SDL_Event eve;
			while (SDL_PollEvent(&eve) != 0) {
				if (eve.type == SDL_QUIT) {
					quit = true;
				}
				currentState->stateEvents(eve);
			} //in while
			//std::cout << removed.size() << std::endl;
			currentState->updateState();
			  
			currentState->changeState();
			//std::cout << " Out tick: " << SDL_GetTicks() << " " << sprites.size() << std::endl;
			for (Sprite* s : added) {
				//std::cout << "tick: " << SDL_GetTicks() << " " << added.size() << std::endl;
				sprites.push_back(s); //vi överför alla komponenter från added till comps när vi inte längre itererar över den
				//std::cout << sprites.size() << std::endl;
			}
			added.clear(); //rensar vektorn
			//std::cout << "After added loop " << sprites.size() << std::endl;
			//std::cout << removed.size() << std::endl;
			 //bara en check
			for (Sprite* s : removed) { 
				//std::cout << "Should delete" << std::endl;
				for (std::vector<Sprite*>::iterator i = sprites.begin(); i != sprites.end();) {
					if (*i == s) { // vi kollar om pekaren c finns i removed vektorn och tar bort den
						i = sprites.erase(i); //i= för att erase() returnerar iterator på det första elementet som är kvar i vektorn, efter i
					} else {
						i++; //i++ är i else då vi vill inte öka iteratorn om ett element tas bort
					}
				}
			}
			removed.clear();
			//Färg till renderaren
			//SDL_SetRenderDrawColor(sys.getRen(), 0, 0, 0, 0);
			//går igenom alla komponenter efter eventet och ritar de i det nya tillståndet. För att rita up llla händelse måste man sudda skärmen först RClear
			SDL_RenderClear(sys.getRen());
			sys.drawSysBG(); //ritar bakgrund
			currentState->renderState();
			//sen ska man skriva ut, presentera från renderaren till skärmen efter ritningen
			SDL_RenderPresent(sys.getRen());
			//i slutet av loopen, efter allt ritas ut, räknar vi tid kvar till nästa tick
			int delay = nextTick - SDL_GetTicks();
			if (delay > 0) { // delay är 0 eller negativ om det inte finns någ kvar 
				SDL_Delay(delay);
			} 
			//std::cout << "getSprites " << sprites.size() << std::endl;
		}//out while
	}

	std::vector<Sprite*> Engine::getSprites() const {
		//std::cout << "getSprites " << sprites.size() << std::endl;
		return sprites;
	}

	bool* Engine::getKeyStateCheck() {
		return keyStateCheck;
	}

	bool* Engine::getScoreCollision() {
		return scoreCollision;
	}

	void Engine::setCurrentState(GameState* state) {
		currentState = state;
	}

	GameState* Engine::getCurrentState() {
		return currentState;
	}

	Engine::~Engine() {

	}

	Engine ge;
}