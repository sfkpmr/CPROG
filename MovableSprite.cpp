#include "MovableSprite.h"
#include "Sprite.h"
#include "System.h"

namespace cwing {

	MovableSprite::MovableSprite(int x, int y, int w, int h): Sprite(x, y, w, h) {

	}

	void MovableSprite::draw() {
		const SDL_Rect& rect = getRect();
		//SDL_RenderCopy(sys.getRen(), texture, NULL, &getRect());
		SDL_RenderCopy(sys.getRen(), texture, NULL, &rect);
	}
	
	//const SDL_Texture& MovableSprite::getTexture() {
	//	return *texture;
	//}

	MovableSprite::~MovableSprite() {

	}
}

