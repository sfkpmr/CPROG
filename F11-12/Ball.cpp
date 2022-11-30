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
		velocityX = getSpeed(); // alltid rörs i x
		velocityY = 0; // velocity Y ändras först vid collision
		
	}

	Ball* Ball::getInstance(int x, int y, int w, int h, int speed) {
		return new Ball(x, y, w, h, speed);
	}

	//bool Ball::checkBounds() {
	//	if (getRect().y <= 0) {
	//		//getRect().y += getSpeed();
	//		return false;
	//	}
	//	if ((getRect().y + getRect().h) >= sys.getHeight()) {
	//		return false;
	//	}


	//	return true;
	//}

	void Ball::paddleCollision() {
		std::cout << "paddleC " << ge.getSprites().size() << std::endl;
		for (Sprite* s : ge.getSprites()) {
			if (Paddle* p = dynamic_cast<Paddle*>(s)) {
				if (p->getPlayerID() == 1) {
					if (SDL_HasIntersection(&getRect(), &(p->getRect()))) {
						double relativeY = (p->getRect().y + (p->getRect().h / 2)) - (getRect().y + (getRect().h / 2)); //var på paddle träffar bollen
						//då paddle kan vara olika i höjd, behöver vi normalisera relativeY så vi får nummer mellar -1 och 1, och inte -5 och 5 om paddle är 10 pixel hög
						double normalizeRY = relativeY / (p->getRect().h / 2);
						double angle = normalizeRY * (5 * 3.14 / 12); //(5 * 3.14 / 12) -> max 75 grader. Byta till static const MAXANGLE?
						velocityX = -getSpeed() * cos(angle);
						velocityY = getSpeed() * -sin(angle);
					}
				} else if (p->getPlayerID() == 2) {
					if (SDL_HasIntersection(&getRect(), &(p->getRect()))) {
						double relativeY = (p->getRect().y + (p->getRect().h / 2)) - (getRect().y + (getRect().h / 2)); //var på paddle träffar bollen
						//då paddle kan vara olika i höjd, behöver vi normalisera relativeY så vi får nummer mellar -1 och 1, och inte -5 och 5 om paddle är 10 pixel hög
						double normalizeRY = relativeY / (p->getRect().h / 2);
						double angle = normalizeRY * (5 * 3.14 / 12); //(5 * 3.14 / 12) -> max 75 grader. Byta till static const MAXANGLE?
						velocityX = getSpeed() * cos(angle);
						velocityY = getSpeed() * -sin(angle);
					}
				}
			}
		}	
	}
	
	void Ball::tick() {
		// e i konstruktor nu
		//velocityX = getSpeed(); // alltid rörs i x
		//velocityY = 0; // velocity Y ändras först vid collision
		paddleCollision();

		if (getRect().x + getRect().w >= sys.getWidth() - 100) {
			//std::cout << "Borde ta bort" << std::endl;
			ge.remove(this); // kolla om det fungerar
		} else if (getRect().x <= 0) {
			//std::cout << "Temp" << std::endl;
			ge.remove(this);
		} 
		
		if (getRect().y <= 0) {
			velocityY = -velocityY;
		} else if ((getRect().y + getRect().h) >= sys.getHeight()) {
			velocityY = -velocityY;
		}

		getRect().x += velocityX;
		getRect().y += velocityY;


		//if (checkBounds()) {
		//	getRect().y -= getSpeed();
		//	std::cout << 1 << std::endl;

			//if (getRect().y <= 0 && direction == "UP") {
			//	getRect().y += getSpeed();
			//	getRect().x += getSpeed();
			//	direction = "DOWN";
			//	std::cout << 2 << std::endl;
			//}
			//
			//else if ((getRect().y + getRect().h) >= sys.getHeight() && direction == "DOWN") {
			//	getRect().y -= getSpeed();
			//	direction = "UP";
			//	std::cout << 3 << std::endl;
			//}
			//else {
			//	if (direction == "UP") {
			//		getRect().y -= getSpeed();
			//	}
			//	else if (direction == "DOWN") {
			//		getRect().y += getSpeed();
			//	}
			//}
	}

	Ball::~Ball() {
		std::cout << "Ball dest anropas" << std::endl;
		SDL_DestroyTexture(texture);
	}

}
