#include "Engine.h"
#include "Sprite.h"
#include <SDL.h>
#include "System.h"
#include <iostream>
namespace cwing {

#define FPS 60 //antal frames per sekund. FPS f�r att kunna styra hastigheten av spelet, samt att hastigheten blir samma p� olika datorer

	void Engine::add(Sprite* c) {
		added.push_back(c);  //vi adderar sprites f�rst till en tempor�r vector, f�r att slippa addera komponenter under loopens g�ng
	}

	void Engine::remove(Sprite* c) {
		removed.push_back(c); //adderar sprites till en tempor�r vector f�rst n�r de tas bort
		//std::cout << removed.size() << std::endl;
	}

	void Engine::run() {
		bool quit = false; 
		Uint32 tInterval = 1000 / FPS; //hur m�nga milisekunder programmet ska dr�ja mellan ticks
		while (!quit) {
			Uint32 nextTick = SDL_GetTicks() + tInterval; //nextTick r�knar ur n�r n�sta tick ska vara. SDL_GetTicks() returnerar antal milisekunder sen initieringen utav SDL
			SDL_Event eve;
			while (SDL_PollEvent(&eve)) {
				switch (eve.type) {
				case SDL_QUIT:
					quit = true;
					break;
				case SDL_MOUSEBUTTONDOWN: // kommer inte beh�vas??
					//efter att ha tagit emot h�ndelse i loopen g�r vi igenom alla komponent och anropar deras funktioner f�r 
					//att hantera den typen av h�ndelsen och de updaterar sig
					for (Sprite* s : sprites) {
						s->mouseDown(eve);
					}
					break;
				case SDL_MOUSEBUTTONUP: // samma?
					for (Sprite* s : sprites) {
						s->mouseUp(eve);
					}
					break;
				case SDL_KEYDOWN: 
					for (Sprite* s : sprites) {
						s->keyDown(eve);
					}
					break;
				case SDL_KEYUP:
					for (Sprite* s : sprites) {
						s->keyUp(eve);
					}
					break;
				} //switch
			} //in while
			//std::cout << removed.size() << std::endl;
			
			for (Sprite* s : sprites) {
				//std::cout << "In tick: " << SDL_GetTicks() << " " << sprites.size() << std::endl;
				s->tick();
			}
			//std::cout << " Out tick: " << SDL_GetTicks() << " " << sprites.size() << std::endl;
			for (Sprite* s : added) {
				//std::cout << "tick: " << SDL_GetTicks() << " " << added.size() << std::endl;
				sprites.push_back(s); //vi �verf�r alla komponenter fr�n added till comps n�r vi inte l�ngre itererar �ver den
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
						i = sprites.erase(i); //i= f�r att erase() returnerar iterator p� det f�rsta elementet som �r kvar i vektorn, efter i
					} else {
						i++; //i++ �r i else d� vi vill inte �ka iteratorn om ett element tas bort
					}
				}
			}
			removed.clear();
			//F�rg till renderaren
			//SDL_SetRenderDrawColor(sys.getRen(), 0, 0, 0, 0);
			//g�r igenom alla komponenter efter eventet och ritar de i det nya tillst�ndet. F�r att rita up llla h�ndelse m�ste man sudda sk�rmen f�rst RClear
			SDL_RenderClear(sys.getRen());
			sys.drawSysBG(); //ritar bakgrund
			for (Sprite* s : sprites) {
				s->draw(); 
			}
			//sen ska man skriva ut, presentera fr�n renderaren till sk�rmen efter ritningen
			SDL_RenderPresent(sys.getRen());
			//i slutet av loopen, efter allt ritas ut, r�knar vi tid kvar till n�sta tick
			int delay = nextTick - SDL_GetTicks();
			if (delay > 0) { // delay �r 0 eller negativ om det inte finns n�g kvar 
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

	Engine::~Engine() {

	}

	Engine ge;
}