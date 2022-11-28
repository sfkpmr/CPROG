#include "Paddle.h"
#include "Constants.h"
#include "System.h"
#include <SDL.h>
#include <SDL_image.h>

namespace cwing {
	Paddle::Paddle(int x, int y, int width, int height, int speed, int pId): MovableSprite(x , y, width, height, speed), playerId(pId){
		
		texture = IMG_LoadTexture(sys.getRen(), (constants::gResPath + "paddle.png").c_str());
	}
	// 4 players?
	void Paddle::keyDown(const SDL_Event& eve) {
		if (playerId == 1) {
			if ((eve.key.keysym.sym == SDLK_UP)) {
				if (getRect().y >= 0) {
					getRect().y -= getSpeed();
				}

				
			}
			if ((eve.key.keysym.sym == SDLK_DOWN)) {
				if (getRect().y <= (sys.getHeight() - getRect().h)) {
					getRect().y += getSpeed();
				}
			}
		}

		if (playerId == 2) {
			if ((eve.key.keysym.sym == SDLK_w)) {
				if (getRect().y >= 0) {
					getRect().y -= getSpeed();
				}


			}
			if ((eve.key.keysym.sym == SDLK_s)) {
				if (getRect().y <= (sys.getHeight() - getRect().h)) {
					getRect().y += getSpeed();
				}
			}
		}

	}

	void Paddle::keyUp(const SDL_Event& eve) {

	}

	Paddle::~Paddle() {
		SDL_DestroyTexture(texture);
	}
}