#include "Session.h"
#include <SDL.h>
#include "System.h"
namespace cwing {

	void Session::add(Component* c) {
		comps.push_back(c);
	}

	void Session::run() {
		bool quit = false;
		while (!quit) {
			SDL_Event eve;
			while (SDL_PollEvent(&eve)) {
				switch (eve.type) {
				case SDL_QUIT:
					quit = true;
					break;
				case SDL_MOUSEBUTTONDOWN:
					//efter att ha tagit emot h�ndelse i loopen g�r vi igenom alla komponent och anropar deras funktioner f�r 
					//att hantera den typen av h�ndelsen och de updaterar sig
					for (Component* c : comps) {
						c->mouseDown(eve);
					}
					break;
				case SDL_MOUSEBUTTONUP:
					for (Component* c : comps) {
						c->mouseUp(eve);
					}
					break;
				case SDL_KEYDOWN:
					for (Component* c : comps) {
						c->keyDown(eve);
					}
					break;
				case SDL_KEYUP:
					for (Component* c : comps) {
						c->keyUp(eve);
					}
					break;
				} //switch
			} //in while
			//F�rg till renderaren
			SDL_SetRenderDrawColor(sys.getRen(), 0, 0, 0, 0);
			//g�r igenom alla komponenter efter eventet och ritar de i det nya tillst�ndet. F�r att rita up llla h�ndelse m�ste man sudda sk�rmen f�rst RClear
			SDL_RenderClear(sys.getRen());
			for (Component* c : comps) {
				c->draw(); 
			}
			//sen ska man skriva ut, presentera fr�n renderaren till sk�rmen efter ritningen
			SDL_RenderPresent(sys.getRen());

		}//out while
	}

	Session::~Session() {

	}
}