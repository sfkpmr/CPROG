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


	bool Ball::checkBounds() {
		if (getRect().y <= 0) {
			//getRect().y += getSpeed();
			return false;
		}
		if ((getRect().y + getRect().h) >= sys.getHeight()) {
			return false;
		}


		return true;
	}
	
	void Ball::tick() {
//		if (getRect().x + getRect().w >= sys.getWidth()) {
//			//std::cout << "Borde ta bort" << std::endl;
//			ge.remove(this); // kolla om det fungerar
//		} else if (getRect().x <= 0) {
//			//std::cout << "Temp" << std::endl;
////			getRect().y -= getSpeed();
//			ge.remove(this);
//		} 
		
		//if (checkBounds()) {
		//	getRect().y -= getSpeed();
		//	std::cout << 1 << std::endl;

			if (getRect().y <= 0 && direction == "UP") {
				getRect().y += getSpeed();
				direction = "DOWN";
				std::cout << 2 << std::endl;
			}
			else if ((getRect().y + getRect().h) >= sys.getHeight() && direction == "DOWN") {
				getRect().y -= getSpeed();
				direction = "UP";
				std::cout << 3 << std::endl;
			}
			else {
				if (direction == "UP") {
					getRect().y -= getSpeed();
				}
				else if (direction == "DOWN") {
					getRect().y += getSpeed();
				}
			}
	
		
	}

	Ball::~Ball() {
		SDL_DestroyTexture(texture);
	}

}
