#include "Obstacle.h"
#include "System.h"
#include "Constants.h"
#include <SDL_image.h>

namespace cwing {
	Obstacle::Obstacle(int x, int y, int w, int h): Sprite(x, y, w, h) {
		texture = IMG_LoadTexture(sys.getRen(), (constants::gResPath + "hinder.png").c_str());
	}

	Obstacle* Obstacle::getInstance(int x, int y, int w, int h) {
		return new Obstacle(x, y, w, h);
	}

	SDL_Point* Obstacle::getTopCenter() {
		return new SDL_Point{ getRect().x + (getRect().w / 2), getRect().y };
	}

	SDL_Point* Obstacle::getBottomCenter() {
		return new SDL_Point{ getRect().x + (getRect().w / 2), getRect().h + getRect().y };
	}

	SDL_Point* Obstacle::getLeftCenter() {
		return new SDL_Point{ getRect().x, getRect().y + (getRect().h / 2) };
	}

	SDL_Point* Obstacle::getRightCenter() {
		return new SDL_Point{ getRect().x + getRect().w, getRect().y + (getRect().h / 2) };
	}

	void Obstacle::draw() {
		SDL_RenderCopy(sys.getRen(), texture, NULL, &getRect());
	}

	Obstacle::~Obstacle() {

	}
}