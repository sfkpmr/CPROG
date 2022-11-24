#include "System.h"
#include <SDL.h>

namespace cwing {

#define HEIGHT 600
#define WIDTH 1000

	System::System() {
		SDL_Init(SDL_INIT_EVERYTHING);
		win = SDL_CreateWindow("CWING", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
		ren = SDL_CreateRenderer(win, -1, 0);
		TTF_Init();
		font = TTF_OpenFont("c:/Windows/Fonts/arial.ttf", 34);
	}

	System::~System() {
		TTF_CloseFont(font);
		TTF_Quit();
		SDL_DestroyWindow(win);
		SDL_DestroyRenderer(ren);
		SDL_Quit();
	}

	SDL_Renderer* System::getRen() const {
		return ren;
	}

	TTF_Font* System::getFont() const {
		return font;
	}

	//eftersom objektet ligger utanför funktioner blir det ett statisk objekt och dess konstruktor kommer att köras innan programmet startar, och des när klar
	//global data, extern System sys;
	System sys;

}
