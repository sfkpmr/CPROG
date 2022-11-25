#include "Engine.h"
#include "Sprite.h"
#include <SDL.h>
#include "System.h"
namespace cwing {

	void Engine::add(Sprite* c) {
		added.push_back(c);  //vi adderar sprites f�rst till en tempor�r vector, f�r att slippa addera komponenter under loopens g�ng
	}

	void Engine::remove(Sprite* c) {
		removed.push_back(c); //adderar sprites till en tempor�r vector f�rst n�r de tas bort
	}

	void Engine::run() {
		bool quit = false;
		while (!quit) {
			SDL_Event eve;
			while (SDL_PollEvent(&eve)) {
				switch (eve.type) {
				case SDL_QUIT:
					quit = true;
					break;
				case SDL_MOUSEBUTTONDOWN: // kommer inte beh�vas??
					//efter att ha tagit emot h�ndelse i loopen g�r vi igenom alla komponent och anropar deras funktioner f�r 
					//att hantera den typen av h�ndelsen och de updaterar sig
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
				comps.push_back(c); //vi �verf�r alla komponenter fr�n added till comps n�r vi inte l�ngre itererar �ver den
			}
			added.clear(); //rensar vektorn

			for (Sprite* c : removed) {
				for (std::vector<Sprite*>::iterator i = comps.begin(); i != comps.end();) {
					if (*i == c) {
						i = comps.erase(i); 
					}
					else {
						i++;
					}
				}
			}
			removed.clear();
			
			//F�rg till renderaren
			SDL_SetRenderDrawColor(sys.getRen(), 0, 0, 0, 0);
			//g�r igenom alla komponenter efter eventet och ritar de i det nya tillst�ndet. F�r att rita up llla h�ndelse m�ste man sudda sk�rmen f�rst RClear
			SDL_RenderClear(sys.getRen());
			for (Sprite* c : comps) {
				c->draw(); 
			}
			//sen ska man skriva ut, presentera fr�n renderaren till sk�rmen efter ritningen
			SDL_RenderPresent(sys.getRen());

		}//out while
	}

	Engine::~Engine() {

	}
}