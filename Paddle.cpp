#include "Paddle.h"
#include "Sprite.h"
#include "Constants.h"
#include <SDL.h>
#include <SDL_image.h>

namespace cwing {
	Paddle::Paddle(int x, int y, int width, int height): MovableSprite(x , y, width, height) {
		
		texture = IMG_LoadTexture(sys.getRen(), (constants::gResPath + "paddle.png").c_str());
	}

	void Paddle::keyDown(const SDL_Event&) {

	}

	void Paddle::keyUp(const SDL_Event&) {

	}

	Paddle::~Paddle() {
		SDL_DestroyTexture(texture);
	}
}