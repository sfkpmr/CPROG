#include <SDL.h>
#include <SDL_image.h>
#include "Ball.h"
#include "MovableSprite.h"
#include "Constants.h"
#include "System.h"
#include "Engine.h"
#include "Sprite.h"
#include "Paddle.h"
#include <cmath>
#include <iostream>

namespace cwing {
	
	Ball::Ball(int x, int y, int w, int h, int speed) : MovableSprite(x, y, w, h, speed) { 
		texture = IMG_LoadTexture(sys.getRen(), (constants::gResPath + "pong_ball.png").c_str());
		velocityX = getSpeed(); // alltid r�rs i x
		velocityY = 0; // velocity Y �ndras f�rst vid collision
		
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

	void Ball::paddleCollision() {  // FIXA BOLLEN TR�FFAR 2 G�NGER
		//std::cout << "paddleC " << ge.getSprites().size() << std::endl;
		for (Sprite* s : ge.getSprites()) {
			//std::cout << "PD LOOP"<< std::endl;
			if (Paddle* p = dynamic_cast<Paddle*>(s)) {
				if (p->getPlayerID() == 1) {
					if (SDL_HasIntersection(&getRect(), &(p->getRect()))) {
						double relativeY = (p->getRect().y + (p->getRect().h / 2)) - (getRect().y + (getRect().h / 2)); //var p� paddle tr�ffar bollen
						//d� paddle kan vara olika i h�jd, beh�ver vi normalisera relativeY s� vi f�r nummer mellar -1 och 1, och inte -5 och 5 om paddle �r 10 pixel h�g
						double normalizeRY = relativeY / (p->getRect().h / 2);
						if (normalizeRY > 1) {
							normalizeRY = 1;
						} 
						if (normalizeRY < -1) {
							normalizeRY = -1;
						} 
						double angle = normalizeRY * (13 * 3.14 / 36); //(5 * 3.14 / 12) -> max 75 grader. Byta till static const MAXANGLE?
						velocityX = -getSpeed() * cos(angle);
						velocityY = getSpeed() * -sin(angle);
						sys.playSfx("p_hit4416.wav");
					}
				} else if (p->getPlayerID() == 2) {
					if (SDL_HasIntersection(&getRect(), &(p->getRect()))) {
						double relativeY = (p->getRect().y + (p->getRect().h / 2)) - (getRect().y + (getRect().h / 2)); //var p� paddle tr�ffar bollen
						//d� paddle kan vara olika i h�jd, beh�ver vi normalisera relativeY s� vi f�r nummer mellar -1 och 1, och inte -5 och 5 om paddle �r 10 pixel h�g
						double normalizeRY = relativeY / (p->getRect().h / 2);
						if (normalizeRY > 1) {
							normalizeRY = 1;
						}
						if (normalizeRY < -1) {
							normalizeRY = -1;
						}
						double angle = normalizeRY * (13 * 3.14 / 36); //(5 * 3.14 / 12) -> max 75 grader. Byta till static const MAXANGLE?
						velocityX = getSpeed() * cos(angle);
						velocityY = getSpeed() * -sin(angle);
						sys.playSfx("p_hit4416.wav");
					}
				}
			}
		}	
	}

	void Ball::obstacleCollision() {
		for (Sprite* s : ge.getSprites()) {
			if (Obstacle* o = dynamic_cast<Obstacle*>(s)) {
				//if (SDL_HasIntersection(&getRect() , &(o->getRect()))) {
				//	std::cout << getRect().x << "  " << getRect().y << std::endl;
				//	getClosestObsticle(o);
				//	double relativeY = (o->getRect().y + (o->getRect().h / 2)) - (getRect().y + (getRect().h / 2)); //var p� paddle tr�ffar bollen
				//	//d� paddle kan vara olika i h�jd, beh�ver vi normalisera relativeY s� vi f�r nummer mellar -1 och 1, och inte -5 och 5 om paddle �r 10 pixel h�g
				//	double normalizeRY = relativeY / (o->getRect().h / 2);
				//	if (normalizeRY > 1) {
				//		normalizeRY = 1;
				//	}
				//	if (normalizeRY < -1) {
				//		normalizeRY = -1;
				//	}
				//	double angle = normalizeRY * (13 * 3.14 / 36); //(5 * 3.14 / 12) -> max 75 grader. Byta till static const MAXANGLE?
				//	velocityX = -getSpeed() * cos(angle);
				//	velocityY = getSpeed() * -sin(angle);
				//	sys.playSfx("p_hit4416.wav");
				if (SDL_HasIntersection(&getRect(), &(o->getRect()))) {
					std::cout << getRect().x << "  " << getRect().y << std::endl;
					int temp = getClosestObsticle(o);
					if (temp == 1) {
						double relativeTop = (o->getRect().x + (o->getRect().w / 2)) - (getRect().x + (getRect().w / 2));
						double normalizeRYTop = relativeTop / (o->getRect().w / 2);
						if (relativeTop > 1) {
							relativeTop = 1;
						}
						if (relativeTop < -1) {
							relativeTop = -1;
						}
						double angle = relativeTop * (13 * 3.14 / 36);
						velocityX = getSpeed() * cos(angle);
						velocityY = getSpeed() * -sin(angle);
						sys.playSfx("p_hit4416.wav");
					} else if (temp == 2) {
						double relativeButtom = (o->getRect().x + (o->getRect().w / 2)) - (getRect().x + (getRect().w / 2));
						double normalizeRYTop = relativeButtom / (o->getRect().w / 2);
						if (relativeButtom > 1) {
							relativeButtom = 1;
						}
						if (relativeButtom < -1) {
							relativeButtom = -1;
						}
						double angle = relativeButtom * (13 * 3.14 / 36);
						velocityX = getSpeed() * cos(angle);
						velocityY = getSpeed() * -sin(angle);
						sys.playSfx("p_hit4416.wav");
					} else if (temp == 3) {
						double relativeY = (o->getRect().y + (o->getRect().h / 2)) - (getRect().y + (getRect().h / 2)); //var p� paddle tr�ffar bollen
						//d� paddle kan vara olika i h�jd, beh�ver vi normalisera relativeY s� vi f�r nummer mellar -1 och 1, och inte -5 och 5 om paddle �r 10 pixel h�g
						double normalizeRY = relativeY / (o->getRect().h / 2);
						if (normalizeRY > 1) {
							normalizeRY = 1;
						}
						if (normalizeRY < -1) {
							normalizeRY = -1;
						}
						double angle = normalizeRY * (13 * 3.14 / 36); //(5 * 3.14 / 12) -> max 75 grader. Byta till static const MAXANGLE?
						velocityX = -getSpeed() * cos(angle);
						velocityY = getSpeed() * -sin(angle);
						sys.playSfx("p_hit4416.wav");
					} else if (temp == 4) {
						double relativeY = (o->getRect().y + (o->getRect().h / 2)) - (getRect().y + (getRect().h / 2)); //var p� paddle tr�ffar bollen
						//d� paddle kan vara olika i h�jd, beh�ver vi normalisera relativeY s� vi f�r nummer mellar -1 och 1, och inte -5 och 5 om paddle �r 10 pixel h�g
						double normalizeRY = relativeY / (o->getRect().h / 2);
						if (normalizeRY > 1) {
							normalizeRY = 1;
						}
						if (normalizeRY < -1) {
							normalizeRY = -1;
						}
						double angle = normalizeRY * (13 * 3.14 / 36); //(5 * 3.14 / 12) -> max 75 grader. Byta till static const MAXANGLE?
						velocityX = getSpeed() * cos(angle);
						velocityY = getSpeed() * -sin(angle);
						sys.playSfx("p_hit4416.wav");
					}
				}
			} 
		}
	}

	SDL_Point* Ball::getCenter() {
		return new SDL_Point{ getRect().x + (getRect().w / 2), getRect().y + (getRect().h / 2) };
	}

	int Ball::getClosestObsticle(Obstacle* obs) {
		SDL_Point* temp = getCenter();
		SDL_Point* top = obs->getTopCenter();
		SDL_Point* bottom = obs->getBottomCenter();
		SDL_Point* left = obs->getLeftCenter();
		SDL_Point* right = obs->getRightCenter();
		std::cout << top->x << "-" << top->y << "-" << bottom->x << "-" <<bottom->y << "-" <<left->x << "-" <<left->y << "-" <<right->x << "-" <<right->y << std::endl;
		double topDistance = sqrt(pow(temp->x - temp->y, 2) + pow(top->x - top->y, 2));
		double bottomDistance = sqrt(pow(temp->x - temp->y, 2) + pow(bottom->x - bottom->y, 2));
		double leftDistance = sqrt(pow(temp->x - temp->y, 2) + pow(left->x - left->y, 2));
		double rightDistance = sqrt(pow(temp->x - temp->y, 2) + pow(right->x - right->y, 2));
		std::cout << topDistance << "  " << bottomDistance << "  " << leftDistance << "  " << rightDistance << std::endl;
		//tiebreaker?
		if (topDistance > bottomDistance && topDistance > leftDistance && topDistance > rightDistance) {
			return 1;
		}
		else if (bottomDistance > topDistance && bottomDistance > leftDistance && bottomDistance > rightDistance) {
			return 2;
		}
		else if (leftDistance > topDistance && leftDistance > bottomDistance && leftDistance > rightDistance) {
			return 3;
		}
		else {
			return 4;
		}
	}
	
	void Ball::tick() {
		// e i konstruktor nu
		//velocityX = getSpeed(); // alltid r�rs i x
		//velocityY = 0; // velocity Y �ndras f�rst vid collision
		paddleCollision();
		obstacleCollision();
		//std::cout << "getSprites " << ge.getSprites().size() << std::endl;
		if (getRect().x + getRect().w >= sys.getWidth()) {
			ge.getScoreCollision()[1] = true;
			sys.playSfx("score4416.wav");
			ge.remove(this); // kolla om det fungerar
			ge.add(Ball::getInstance(475, 275, 25, 25, getSpeed()));
		} else if (getRect().x <= 0) {
			ge.getScoreCollision()[0] = true;
			sys.playSfx("score4416.wav");
			ge.remove(this);
			ge.add(Ball::getInstance(475, 275, 25, 25, getSpeed()));
		} 
		
		if (getRect().y <= 0) {
			velocityY = -velocityY;
			sys.playSfx("w_hit4416.wav");
		} else if ((getRect().y + getRect().h) >= sys.getHeight()) {
			velocityY = -velocityY;
			sys.playSfx("w_hit4416.wav");
		}

		getRect().x += velocityX;
		getRect().y += velocityY;
	}

	Ball::~Ball() {
		std::cout << "Ball dest anropas" << std::endl;
		SDL_DestroyTexture(texture);
	}

}
