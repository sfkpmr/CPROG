#include "Paddle.h"
#include "Constants.h"
#include "System.h"
#include "Engine.h"

namespace cwing {

	Paddle::Paddle(int x, int y, int width, int height, int speed, int pId): MovableSprite(x , y, width, height, speed), playerId(pId){
		texture = IMG_LoadTexture(sys.getRen(), (constants::gResPath + "paddle_v.png").c_str());
		velocity = getSpeed();
		setSpriteType("paddle");
	}

	Paddle* Paddle::getInstance(int x, int y, int width, int height, int speed, int player){
		return new Paddle(x, y, width, height, speed, player);
	}

	void Paddle::draw() {
		SDL_RenderCopy(sys.getRen(), texture, NULL, &getRect());
	}

	void Paddle::keyDown(const SDL_Event& eve) {
		if (playerId == 1) {
			if (eve.key.keysym.sym == SDLK_UP) {
				ge.getKeyStateCheck()[0] = true;
			} else if (eve.key.keysym.sym == SDLK_DOWN) {
				ge.getKeyStateCheck()[1] = true;
			}
		}
		if (playerId == 2) {
			if (eve.key.keysym.sym == SDLK_w) {
				ge.getKeyStateCheck()[2] = true;
			}
			else if (eve.key.keysym.sym == SDLK_s) {
				ge.getKeyStateCheck()[3] = true;
			}
		}
	}

	void Paddle::keyUp(const SDL_Event& eve) {
		if (playerId == 1) {
			if (eve.key.keysym.sym == SDLK_UP) {
				ge.getKeyStateCheck()[0] = false;
			} else if (eve.key.keysym.sym == SDLK_DOWN) {
				ge.getKeyStateCheck()[1] = false;
			}
		}
		if (playerId == 2) {
			if (eve.key.keysym.sym == SDLK_w) {
				ge.getKeyStateCheck()[2] = false;
			}
			else if (eve.key.keysym.sym == SDLK_s) {
				ge.getKeyStateCheck()[3] = false;
			}
		}
	}

	void Paddle::tick() {
		if (ge.getKeyStateCheck()[0] && playerId == 1) {
			if (getRect().y >= 0) {
				getRect().y -= velocity;
			}
		} else if (ge.getKeyStateCheck()[1] && playerId == 1) {
			if (getRect().y <= (sys.getHeight() - getRect().h)) {
				getRect().y += velocity;
			}
		} 
		if (ge.getKeyStateCheck()[2] && playerId == 2) {
			if (getRect().y >= 0) {
				getRect().y -= velocity;
			}
		}
		else if (ge.getKeyStateCheck()[3] && playerId == 2) {
			if (getRect().y <= (sys.getHeight() - getRect().h)) {
				getRect().y += velocity;
			}
		} 
	}

	const int Paddle::getPlayerID() const {
		return playerId;
	}

	Paddle::~Paddle() {
		SDL_DestroyTexture(texture);
	}
}