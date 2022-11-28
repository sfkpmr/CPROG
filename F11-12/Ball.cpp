#include <SDL.h>
#include <SDL_image.h>
#include "Ball.h"
#include "MovableSprite.h"
#include "Constants.h"
#include "System.h"
#include "Engine.h"
#include "Sprite.h"
#include <iostream>

namespace cwing {
	
	
	Ball::Ball(int x, int y, int w, int h, int speed) : MovableSprite(x, y, w, h, speed) { 
		texture = IMG_LoadTexture(sys.getRen(), (constants::gResPath + "wdot.png").c_str());
	}

	Ball* Ball::getInstance(int x, int y, int w, int h, int speed) {
		return new Ball(x, y, w, h, speed);
	}

	//void Ball::draw() {
	//	//const SDL_Rect& rect = getRect();
	//	//SDL_RenderCopy(sys.getRen(), texture, NULL, &getRect());
	//	SDL_RenderCopy(sys.getRen(), texture, NULL, &getRect());
	//}

	
	void Ball::tick() {
		if (getRect().x + getRect().w >= sys.getWidth()) {
			//std::cout << "Borde ta bort" << std::endl;
			ge.remove(this); // kolla om det fungerar
		} else {
			//std::cout << "Temp" << std::endl;
			getRect().x += getSpeed();
		}
		
	}

	Ball::~Ball() {
		SDL_DestroyTexture(texture);
	}

}
