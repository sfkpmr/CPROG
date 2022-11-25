#include "Paddle.h"
#include "Constants.h"
#include "System.h"
#include <SDL.h>
#include <SDL_image.h>

namespace cwing {
	Paddle::Paddle(int x, int y, int width, int height, int speed): MovableSprite(x , y, width, height, speed) {
		
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