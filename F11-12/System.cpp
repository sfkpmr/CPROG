#include "System.h"
#include "Constants.h"
#include <SDL.h>
#include <SDL_image.h>

namespace cwing {

//#define HEIGHT 600
//#define WIDTH 1000

	System::System() {
		SDL_Init(SDL_INIT_EVERYTHING);
		win = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
		ren = SDL_CreateRenderer(win, -1, 0);
		tex = IMG_LoadTexture(ren, (constants::gResPath + "pong_court.png").c_str()); //kan skapas vid varje state
		TTF_Init();
		//font = TTF_OpenFont((constants::gResPath + "RetroGaming.ttf").c_str(), 34); //FLYTTA S�KV�GEN TILL CONSTANTS
	}

	System::~System() {
		//TTF_CloseFont(font);
		TTF_Quit();
		SDL_DestroyWindow(win);
		SDL_DestroyRenderer(ren);
		SDL_DestroyTexture(tex);
		SDL_Quit();
	}

	SDL_Renderer* System::getRen() const {
		return ren;
	}

	//TTF_Font* System::getFont() const {
	//	return font;
	//}

	int System::getWidth() const {
		return width;
	}

	int System::getHeight() const {
		return height;
	}

	void System::drawSysBG() {
		SDL_RenderCopy(ren, tex, NULL, NULL);
	}

	//eftersom objektet ligger utanf�r funktioner blir det ett statisk objekt och dess konstruktor kommer att k�ras innan programmet startar, och des n�r klar
	//global data, extern System sys;
	System sys;

}
