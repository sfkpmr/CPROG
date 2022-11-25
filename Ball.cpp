#include <SDL.h>
#include <SDL_image.h>
#include "Ball.h"
#include "MovableSprite.h"
#include "Constants.h"
#include "System.h"
#include "Engine.h"

namespace cwing {
	
	
	Ball::Ball(int x, int y, int w, int h, int speed) : MovableSprite(x, y, w, h, speed) { 
		texture = IMG_LoadTexture(sys.getRen(), (constants::gResPath + "wdot.png").c_str());
	}
	
	void Ball::tick() {
		if (getRect().x + getRect().w >= sys.getWidth()) {
			ge.remove(this); // kolla om det fungerar
		} else {
			getRect().x += getSpeed();
		}
		
	}

	Ball::~Ball() {
		SDL_DestroyTexture(texture);
	}

}
