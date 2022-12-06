#include "Text.h"
#include "Constants.h"
#include "System.h"

namespace cwing {
	Text::Text(int x, int y, std::string text, int fontSize): Sprite(x, y, 0, 0), text(text), fontSize(fontSize) {
		font = TTF_OpenFont((constants::gResPath + "321Impact.ttf").c_str(), fontSize);
		surf = TTF_RenderText_Solid(font, text.c_str(), {255,255,255,200});
		texture = SDL_CreateTextureFromSurface(sys.getRen(), surf);
		//FreeSurface här?? 
	}

	Text* Text::getIntance(int x, int y, std::string text, int fontSize) {
		return new Text(x, y, text, fontSize);
	}

	void Text::draw() {
		getRect().h = surf->h; 
		getRect().w = surf->w; 
		SDL_RenderCopy(sys.getRen(), texture, NULL, &getRect());
	}

	//ändrar text, renderar om texturen
	void Text::setText(std::string nText) {
		SDL_FreeSurface(surf);
		SDL_DestroyTexture(texture);
		text = nText;
		surf = TTF_RenderText_Solid(font, text.c_str(), {255,255,255,200});
		texture = SDL_CreateTextureFromSurface(sys.getRen(), surf);
	}

	Text::~Text() {
		TTF_CloseFont(font);
		SDL_FreeSurface(surf);
		SDL_DestroyTexture(texture);
	}
}