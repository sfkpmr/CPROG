#include <SDL.h>
#include <SDL_image.h>
#include "Ball.h"
#include "Component.h"
#include "Constants.h"
#include "System.h"

namespace cwing {
	Ball::Ball() : Component(500 - 25, 300 - 25, 50, 50) { // - (getRect().y/2) mitten?
		texture = IMG_LoadTexture(sys.getRen(), (constants::gResPath + "wdot.png").c_str());
	}

	void Ball::draw() {
		const SDL_Rect& rect = getRect();
		//SDL_RenderCopy(sys.ren, texture, NULL, &getRect());
		SDL_RenderCopy(sys.getRen(), texture, NULL, &rect);
		getRect().x += 1;
	}

	Ball::~Ball() {
		SDL_DestroyTexture(texture);
	}
}
