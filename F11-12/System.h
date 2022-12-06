#ifndef SYSTEM_H
#define SYSTEM_H
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <string>

namespace cwing {

	class System
	{
	public:
		System();
		~System();

		SDL_Renderer* getRen() const;
		//TTF_Font* getFont() const;
		int getWidth() const;
		int getHeight() const;
		void drawSysBG();
		void playSfx(std::string sfx);

	private:
		SDL_Window* win;
		SDL_Renderer* ren;
		//TTF_Font* font;
		SDL_Texture* tex;
		Mix_Chunk* audio;
		int width = 1000;
		int height = 600;
	};
	//extern betyder att alla som inkluderar filen får deklaration om att det finns nånstans ett objekt sys av typen System
	extern System sys;
}
#endif
