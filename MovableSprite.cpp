#include "MovableSprite.h"
#include "Sprite.h"
#include "System.h"

namespace cwing {

	MovableSprite::MovableSprite(int x, int y, int w, int h, int speed): Sprite(x, y, w, h), speed(speed) {
		
	}

	int MovableSprite::getSpeed() const {
		return speed;
	}

	void MovableSprite::draw() {
		const SDL_Rect& rect = getRect();
		//SDL_RenderCopy(sys.getRen(), texture, NULL, &getRect());
		SDL_RenderCopy(sys.getRen(), texture, NULL, &rect);
	}
	
	
	MovableSprite::~MovableSprite() {
		
	}
}

