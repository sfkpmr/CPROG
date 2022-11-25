#include <SDL.h>
#include <SDL_image.h>
#include "Ball.h"
#include "MovableSprite.h"
#include "Constants.h"
#include "System.h"
#include "Sprite.h"

namespace cwing {
	Ball::Ball(int x, int y, int w, int h) : MovableSprite(x, y, w, h) { // - (getRect().y/2) mitten?
		texture = IMG_LoadTexture(sys.getRen(), (constants::gResPath + "wdot.png").c_str());
	}
	
	//void tick() {
	//	
	//}

	Ball::~Ball() {
		SDL_DestroyTexture(texture);
	}
}
