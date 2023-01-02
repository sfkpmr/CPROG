#include "System.h"
#include "Constants.h"
#include <iostream>

namespace cwing {

	System::System() {
		SDL_Init(SDL_INIT_EVERYTHING);
		width = 900;
		height = 600;
		orientation = "H";
		background = "hor_pong_court.png";
		win = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
		ren = SDL_CreateRenderer(win, -1, 0);
		tex = IMG_LoadTexture(ren, (constants::gResPath + background).c_str()); 
		TTF_Init();
		Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4096);
	}

	System::~System() {
		std::cout << "Sys dest" << std::endl;
		TTF_Quit();
		Mix_FreeChunk(audio); //ska finnas i Audio klassens destruktor?
		Mix_CloseAudio();
		SDL_DestroyWindow(win);
		SDL_DestroyRenderer(ren);
		SDL_DestroyTexture(tex);
		SDL_Quit();
	}

	SDL_Renderer* System::getRen() const {
		return ren;
	}

	const int System::getWidth() const {
		return width;
	}

	const int System::getHeight() const {
		return height;
	}

	void System::playSfx(std::string sfx) {
		audio = Mix_LoadWAV((constants::gResPath + sfx).c_str());
		Mix_PlayChannel(-1, audio, 0); // 0 - spela en g�ng, 1 - en g�ng och en g�ng till
	}

	void System::drawSysBG() {
		SDL_RenderCopy(ren, tex, NULL, NULL);
	}

	void System::setVertical(){
		TTF_Quit();
		Mix_FreeChunk(audio); //ska finnas i Audio klassens destruktor
		Mix_CloseAudio();
		SDL_DestroyWindow(win);
		SDL_DestroyRenderer(ren);
		SDL_DestroyTexture(tex);
		SDL_Quit();
		SDL_Init(SDL_INIT_EVERYTHING);
		orientation = "V";
		width = 600;
		height = 900;
		background = "ver_pong_court.png";
		win = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
		ren = SDL_CreateRenderer(win, -1, 0);
		tex = IMG_LoadTexture(ren, (constants::gResPath + background).c_str()); //kan skapas vid varje state
		TTF_Init();
		Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4096);
	}

	const std::string System::getOrientation() const {
		return orientation;
	}
	//audio = Mix_LoadWAV((constants::gResPath + sfx).c_str());
	//Mix_PlayChannel(-1, audio, -1); // 0 - spela en g�ng, 1 - en g�ng och en g�ng till

	//eftersom objektet ligger utanf�r funktioner blir det ett statisk objekt och dess konstruktor kommer att k�ras innan programmet startar, och des n�r klar
	//global data, extern System sys;
	System sys;
}
