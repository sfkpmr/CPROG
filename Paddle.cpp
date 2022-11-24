#include "Paddle.h"
#include "Component.h"
#include "Constants.h"
#include <SDL.h>
#include <SDL_image.h>

namespace cwing {
	Paddle::Paddle(int x, int y, int width, int height): Component(x , y, width, height) {
		
		texture = IMG_LoadTexture(sys.getRen(), (constants::gResPath + "paddle.png").c_str());
	}

	void Paddle::draw() {
		const SDL_Rect& rect = getRect();
		//SDL_RenderCopy(sys.ren, texture, NULL, &getRect());
		SDL_RenderCopy(sys.getRen(), texture, NULL, &rect);
	}

	Paddle::~Paddle() {
		SDL_DestroyTexture(texture);
	}
}