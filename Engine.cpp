#include "Engine.h"
#include "Sprite.h"
#include <SDL.h>
#include "System.h"
namespace cwing {

#define FPS 60 //antal frames per sekund. FPS för att kunna styra hastigheten av spelet, samt att hastigheten blir samma på olika datorer

	void Engine::add(Sprite* c) {
		added.push_back(c);  //vi adderar sprites först till en temporär vector, för att slippa addera komponenter under loopens gång
	}

	void Engine::remove(Sprite* c) {
		removed.push_back(c); //adderar sprites till en temporär vector först när de tas bort
	}

	void Engine::run() {
		bool quit = false; 
		Uint32 tInterval = 1000 / FPS; //hur många milisekunder programmet ska dröja mellan ticks
		while (!quit) {
			Uint32 nextTick = SDL_GetTicks() + tInterval; //nextTick räknar ur när nästa tick ska vara. SDL_GetTicks() returnerar antal milisekunder sen initieringen utav SDL
			SDL_Event eve;
			while (SDL_PollEvent(&eve)) {
				switch (eve.type) {
				case SDL_QUIT:
					quit = true;
					break;
				case SDL_MOUSEBUTTONDOWN: // kommer inte behövas??
					//efter att ha tagit emot händelse i loopen går vi igenom alla komponent och anropar deras funktioner för 
					//att hantera den typen av händelsen och de updaterar sig
					for (Sprite* c : comps) {
						c->mouseDown(eve);
					}
					break;
				case SDL_MOUSEBUTTONUP: // samma?
					for (Sprite* c : comps) {
						c->mouseUp(eve);
					}
					break;
				case SDL_KEYDOWN: 
					for (Sprite* c : comps) {
						c->keyDown(eve);
					}
					break;
				case SDL_KEYUP:
					for (Sprite* c : comps) {
						c->keyUp(eve);
					}
					break;
				} //switch
			} //in while

			for (Sprite* c : comps) {
				c->tick();
			}
			
			for (Sprite* c : added) {
				comps.push_back(c); //vi överför alla komponenter från added till comps när vi inte längre itererar över den
			}
			added.clear(); //rensar vektorn

			for (Sprite* c : removed) {
				for (std::vector<Sprite*>::iterator i = comps.begin(); i != comps.end();) {
					if (*i == c) { // vi kollar om pekaren c finns i removed vektorn och tar bort den
						i = comps.erase(i); //i= för att erase() returnerar iterator på det första elementet som är kvar i vektorn, efter i
					}
					else {
						i++; //i++ är i else då vi vill inte öka iteratorn om ett element tas bort
					}
				}
			}
			removed.clear();
			
			//Färg till renderaren
			SDL_SetRenderDrawColor(sys.getRen(), 0, 0, 0, 0);
			//går igenom alla komponenter efter eventet och ritar de i det nya tillståndet. För att rita up llla händelse måste man sudda skärmen först RClear
			SDL_RenderClear(sys.getRen());
			for (Sprite* c : comps) {
				c->draw(); 
			}
			//sen ska man skriva ut, presentera från renderaren till skärmen efter ritningen
			SDL_RenderPresent(sys.getRen());
			//i slutet av loopen, efter allt ritas ut, räknar vi tid kvar till nästa tick
			int delay = nextTick - SDL_GetTicks();
			if (delay > 0) { // delay är 0 eller negativ om det inte finns någ kvar 
				SDL_Delay(delay);
			} 
		}//out while
	}

	Engine::~Engine() {

	}

	Engine ge;
}