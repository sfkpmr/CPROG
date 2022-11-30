#include "Paddle.h"
#include "Constants.h"
#include "System.h"
#include "Engine.h"
#include <SDL.h>
#include <SDL_image.h>

namespace cwing {
	const Uint8* keyStates = SDL_GetKeyboardState(NULL); //fel plats?

	Paddle::Paddle(int x, int y, int width, int height, int speed, int pId): MovableSprite(x , y, width, height, speed), playerId(pId){
		
		texture = IMG_LoadTexture(sys.getRen(), (constants::gResPath + "paddle.png").c_str());
	}

	// 4 players?
	void Paddle::keyDown(const SDL_Event& eve) {

		if (playerId == 1) {
			if ((keyStates[SDL_SCANCODE_UP])) {
				if (getRect().y >= 0) {
					getRect().y -= getSpeed();
				}
			}
			
			if (keyStates[SDL_SCANCODE_DOWN]) {
				if (getRect().y <= (sys.getHeight() - getRect().h)) {
					getRect().y += getSpeed();
				}
			}
		}

		if (playerId == 2) {
			if (keyStates[SDL_SCANCODE_W]) {
				if (getRect().y >= 0) {
					getRect().y -= getSpeed();
				}


			}
			if (keyStates[SDL_SCANCODE_S]) {
				if (getRect().y <= (sys.getHeight() - getRect().h)) {
					getRect().y += getSpeed();
				}
			}
		}

	}

	void Paddle::keyUp(const SDL_Event& eve) {
		if (playerId == 1) {
			if ((keyStates[SDL_SCANCODE_UP])) {
				if (getRect().y >= 0) {
					//getRect().y;
				}
			}

			if (keyStates[SDL_SCANCODE_DOWN]) {
				if (getRect().y <= (sys.getHeight() - getRect().h)) {
					//getRect().y;
				}
			}
		}

		if (playerId == 2) {
			if (keyStates[SDL_SCANCODE_W]) {
				if (getRect().y >= 0) {
					//getRect().y;
				}


			}
			if (keyStates[SDL_SCANCODE_S]) {
				if (getRect().y <= (sys.getHeight() - getRect().h)) {
					//getRect().y;
				}
			}
		}

	}

	int Paddle::getPlayerID() const {
		return playerId;
	}

	Paddle::~Paddle() {
		SDL_DestroyTexture(texture);
	}
}