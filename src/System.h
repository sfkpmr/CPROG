#ifndef SYSTEM_H
#define SYSTEM_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>
#include <string>

namespace cwing {

	class System
	{
	public:
		System();
		~System();
		SDL_Renderer* getRen() const;
		const int getWidth() const;
		const int getHeight() const;
		void drawSysBG();
		void playSfx(std::string sfx);
		void setVertical();
		const std::string getOrientation() const;
	private:
		SDL_Window* win;
		SDL_Renderer* ren;
		SDL_Texture* tex;
		Mix_Chunk* audio;
		std::string orientation;
		std::string background;
		int width;
		int height;
	};
	//extern betyder att alla som inkluderar filen f�r deklaration om att det finns n�nstans ett objekt sys av typen System
	extern System sys;
}
#endif
