#ifndef TEXT_H
#define TEXT_H
#include "Sprite.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

namespace cwing{
	class Text : public Sprite
	{
	private:
		TTF_Font* font;
		SDL_Surface* surf;
		SDL_Texture* texture;
		std::string text;
		int fontSize;
	protected:
		Text(int x, int y, std::string text, int fontSize);
	public:
		static Text* getIntance(int x, int y, std::string text, int fontSize);
		void draw();
		void setText(std::string nText);
		virtual void tick(){}
		virtual ~Text();
	};
}
#endif 

