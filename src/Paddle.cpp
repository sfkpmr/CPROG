#include "Paddle.h"
#include "Constants.h"
#include "System.h"
#include "Engine.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

namespace cwing {
	//const Uint8* keyStates = SDL_GetKeyboardState(NULL); //fel plats?

	Paddle::Paddle(int x, int y, int width, int height, int speed, int pId): MovableSprite(x , y, width, height, speed), playerId(pId){
		texture = IMG_LoadTexture(sys.getRen(), (constants::gResPath + "paddle.png").c_str());
		velocityY = getSpeed();
		setSpriteType("paddle");
	}

	Paddle* Paddle::getInstance(int x, int y, int width, int height, int speed, int player){
		return new Paddle(x, y, width, height, speed, player);
	}

	// 4 players?
	void Paddle::keyDown(const SDL_Event& eve) {
		if (playerId == 1) {
			if (eve.key.keysym.sym == SDLK_UP) {
				ge.getKeyStateCheck()[0] = true;
			}
			else if (eve.key.keysym.sym == SDLK_DOWN) {
				ge.getKeyStateCheck()[1] = true;
			}
			//velocityY = getSpeed();
			//if ((keyStates[SDL_SCANCODE_UP])) {
			//	if (getRect().y >= 0) {
			//		getRect().y -= velocityY;
			//	}
			//}
			//
			//if (keyStates[SDL_SCANCODE_DOWN]) {
			//	if (getRect().y <= (sys.getHeight() - getRect().h)) {
			//		getRect().y += velocityY;
			//	}
			//}
		}

		if (playerId == 2) {
			if (eve.key.keysym.sym == SDLK_w) {
				ge.getKeyStateCheck()[2] = true;
			}
			else if (eve.key.keysym.sym == SDLK_s) {
				ge.getKeyStateCheck()[3] = true;
			}
			//velocityY = getSpeed();
			//if (keyStates[SDL_SCANCODE_W]) {
			//	if (getRect().y >= 0) {
			//		getRect().y -= velocityY;
			//	}


			//}
			//if (keyStates[SDL_SCANCODE_S]) {
			//	if (getRect().y <= (sys.getHeight() - getRect().h)) {
			//		getRect().y += velocityY;
			//	}
			//}
		}

	}

	void Paddle::keyUp(const SDL_Event& eve) {
		if (playerId == 1) {
			if (eve.key.keysym.sym == SDLK_UP) {
				ge.getKeyStateCheck()[0] = false;
			}
			else if (eve.key.keysym.sym == SDLK_DOWN) {
				ge.getKeyStateCheck()[1] = false;
			}
			//if ((keyStates[SDL_SCANCODE_UP])) {
			//	if (getRect().y >= 0) {
			//		//getRect().y;
			//		velocityY = 0;
			//	}
			//}

			//if (keyStates[SDL_SCANCODE_DOWN]) {
			//	if (getRect().y <= (sys.getHeight() - getRect().h)) {
			//		//getRect().y;
			//		velocityY = 0;
			//	}
			//}
		}

		if (playerId == 2) {
			if (eve.key.keysym.sym == SDLK_w) {
				ge.getKeyStateCheck()[2] = false;
			}
			else if (eve.key.keysym.sym == SDLK_s) {
				ge.getKeyStateCheck()[3] = false;
			}
			//if (keyStates[SDL_SCANCODE_W]) {
			//	if (getRect().y >= 0) {
			//		//getRect().y;
			//		velocityY = 0;
			//	}


			//}
			//if (keyStates[SDL_SCANCODE_S]) {
			//	if (getRect().y <= (sys.getHeight() - getRect().h)) {
			//		//getRect().y;
			//		velocityY = 0;
			//	}
			//}
		}

	}

	void Paddle::tick() {

		if (ge.getKeyStateCheck()[0] && playerId == 1) {
			if (getRect().y >= 0) {
				getRect().y -= velocityY;
			}
		} else if (ge.getKeyStateCheck()[1] && playerId == 1) {
			if (getRect().y <= (sys.getHeight() - getRect().h)) {
				getRect().y += velocityY;
			}
		} else {
			;
		}
		if (ge.getKeyStateCheck()[2] && playerId == 2) {
			if (getRect().y >= 0) {
				getRect().y -= velocityY;
			}
		}
		else if (ge.getKeyStateCheck()[3] && playerId == 2) {
			if (getRect().y <= (sys.getHeight() - getRect().h)) {
				getRect().y += velocityY;
			}
		} else {
			;
		}

	}

	int Paddle::getPlayerID() const {
		return playerId;
	}

	Paddle::~Paddle() {
		SDL_DestroyTexture(texture);
	}
}