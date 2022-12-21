#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Ball.h"
#include "MovableSprite.h"
#include "Constants.h"
#include "System.h"
#include "Engine.h"
#include "Sprite.h"
#include "Paddle.h"
#include "Powerup.h"
#include <cmath>
#include <iostream>

namespace cwing {
	
	Ball::Ball(int x, int y, int w, int h, int speed) : MovableSprite(x, y, w, h, speed) { //, velocityX(getSpeed()), velocityY(0)
		texture = IMG_LoadTexture(sys.getRen(), (constants::gResPath + "pong_ball.png").c_str());
		velocityX = getSpeed(); // alltid rörs i x
		velocityY = 0; // velocity Y ändras först vid collision
		setSpriteType("ball");
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
			if (s->getSpriteType() == "paddle") { //change to sprite id check s->getSpriteType() == "paddle"
				Paddle* p = dynamic_cast<Paddle*>(s);
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
			if (s->getSpriteType() == "obstacle") { // ändra till getSpriteType? s->getSpriteType() == "obstacle"
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
				Obstacle* o = dynamic_cast<Obstacle*>(s);
				if (SDL_HasIntersection(&getRect(), &(o->getRect()))) {
					//std::cout << getRect().x << "  " << getRect().y << std::endl;
					int temp = getClosestObsticle(o);
					if (temp == 1) { //TOP
						std::cout << "Top" << std::endl;
						//double relativeTop = (o->getRect().x + (o->getRect().w / 2)) - (getRect().x + (getRect().w / 2));
						//double normalizeRYTop = relativeTop / (o->getRect().w / 2);
						//if (relativeTop > 1) {
						//	relativeTop = 1;
						//}
						//if (relativeTop < -1) {
						//	relativeTop = -1;
						//}
						//double angle = relativeTop * (13 * 3.14 / 36);
						//velocityX = -getSpeed() * cos(angle);
						//velocityY = -getSpeed() * -sin(angle);
						velocityY = -velocityY;
						sys.playSfx("p_hit4416.wav");
					} else if (temp == 2) { //BUTTOM
						std::cout << "Bottom" << std::endl;
						//double relativeBottom = (o->getRect().x + (o->getRect().w / 2)) - (getRect().x + (getRect().w / 2));
						//double normalizeRYTop = relativeBottom / (o->getRect().w / 2);
						//if (relativeBottom > 1) {
						//	relativeBottom = 1;
						//}
						//if (relativeBottom < -1) {
						//	relativeBottom = -1;
						//}
						//double angle = relativeBottom * (13 * 3.14 / 36);
						//velocityX = getSpeed() * cos(angle);
						//velocityY = -getSpeed() * -sin(angle);

						velocityY = -velocityY;
						sys.playSfx("p_hit4416.wav");
					} else if (temp == 3) { //LEFT
						std::cout << "Left" << std::endl;
						//double relativeY = (o->getRect().y + (o->getRect().h / 2)) - (getRect().y + (getRect().h / 2)); //var p� paddle tr�ffar bollen
						////d� paddle kan vara olika i h�jd, beh�ver vi normalisera relativeY s� vi f�r nummer mellar -1 och 1, och inte -5 och 5 om paddle �r 10 pixel h�g
						//double normalizeRY = relativeY / (o->getRect().h / 2);
						//if (normalizeRY > 1) {
						//	normalizeRY = 1;
						//}
						//if (normalizeRY < -1) {
						//	normalizeRY = -1;
						//}
						//double angle = normalizeRY * (13 * 3.14 / 36); //(5 * 3.14 / 12) -> max 75 grader. Byta till static const MAXANGLE?
						//velocityX = -getSpeed() * cos(angle);
						//velocityY = getSpeed() * -sin(angle);
						std::cout << "vel left: " << velocityX << " " << -velocityX << std::endl;
						velocityX = -velocityX;
						sys.playSfx("p_hit4416.wav");
					} else if (temp == 4) { //RIGHT
						std::cout << "Right" << std::endl;
						//double relativeY = (o->getRect().y + (o->getRect().h / 2)) - (getRect().y + (getRect().h / 2)); //var p� paddle tr�ffar bollen
						////d� paddle kan vara olika i h�jd, beh�ver vi normalisera relativeY s� vi f�r nummer mellar -1 och 1, och inte -5 och 5 om paddle �r 10 pixel h�g
						//double normalizeRY = relativeY / (o->getRect().h / 2);
						//if (normalizeRY > 1) {
						//	normalizeRY = 1;
						//}
						//if (normalizeRY < -1) {
						//	normalizeRY = -1;
						//}
						//double angle = normalizeRY * (13 * 3.14 / 36); //(5 * 3.14 / 12) -> max 75 grader. Byta till static const MAXANGLE?
						//velocityX = getSpeed() * cos(angle);
						//velocityY = getSpeed() * -sin(angle);
						std::cout << "vel right: " << velocityX << " " << -velocityX << std::endl;
						velocityX = -velocityX;
						sys.playSfx("p_hit4416.wav");
					} 
/* 					else if (temp == 5) {
						velocityX = -velocityX;
						velocityY = -velocityY;
					} */					
				}
			} else if (s->getSpriteType() == "powerup"){ // ändra till getSpriteType? s->getSpriteType() == "powerup"
			    Powerup* p = dynamic_cast<Powerup*>(s);
				if(SDL_HasIntersection(&getRect(), &(p->getRect()))){// && p->getHidden() == false
					setSpeed(1.25);
					//velocityX = getSpeed();
					//velocityY = getSpeed();
					//p->hide();
					ge.remove(p);
				}
			}
		}
	}

	SDL_Point Ball::getCenter() {
		return SDL_Point{ getRect().x + (getRect().w / 2), getRect().y + (getRect().h / 2) }; //heap allokerat måste tas bort?
	}

	int Ball::getClosestObsticle(Obstacle* obs) {
		SDL_Point temp = getCenter();
		SDL_Point left = obs->getTopCenter();
		SDL_Point right = obs->getBottomCenter(); // was bottom, vi vet det fucked
		SDL_Point top = obs->getLeftCenter();
		SDL_Point bottom = obs->getRightCenter(); // was right, vi vet det fucked
		std::cout << top.x << "-" << top.y << "-" << bottom.x << "-" <<bottom.y << "-" <<left.x << "-" <<left.y << "-" <<right.x << "-" <<right.y << std::endl;
		/*double topDistance = sqrt(pow(temp->x - temp->y, 2) + pow(top->x - top->y, 2));
		double bottomDistance = sqrt(pow(temp->x - temp->y, 2) + pow(bottom->x - bottom->y, 2));
		double leftDistance = sqrt(pow(temp->x - temp->y, 2) + pow(left->x - left->y, 2));
		double rightDistance = sqrt(pow(temp->x - temp->y, 2) + pow(right->x - right->y, 2));*/
		double topDistance = sqrt(pow(temp.x - top.y, 2) + pow(top.x - temp.y, 2));
		double bottomDistance = sqrt(pow(temp.x - bottom.y, 2) + pow(bottom.x - temp.y, 2));
		double leftDistance = sqrt(pow(temp.x - left.y, 2) + pow(left.x - temp.y, 2));
		double rightDistance = sqrt(pow(temp.x - right.y, 2) + pow(right.x - temp.y, 2));
		std::cout << topDistance << "  " << bottomDistance << "  " << leftDistance << "  " << rightDistance << std::endl;
		int test = 0;
		//tiebreaker?
		if (topDistance < bottomDistance && topDistance < leftDistance && topDistance < rightDistance) {
			test = 1;
		}
		else if (bottomDistance < topDistance && bottomDistance < leftDistance && bottomDistance < rightDistance) {
			test = 2;
		}
		else if (leftDistance < topDistance && leftDistance < bottomDistance && leftDistance < rightDistance) {
			test = 3;
		}
		else if (rightDistance < topDistance && rightDistance < bottomDistance && rightDistance < leftDistance){
			test = 4;
		}
		else {
			//throw std::invalid_argument("Fucked");
			for(int i = 0; i < 10; i++){
				std::cout << "Fucked" << std::endl;
			}
			test = 5;
		}
		std::cout << temp.x << " " << temp.y << " " << topDistance << " " << bottomDistance << " " << leftDistance << " " << rightDistance << " " << test << std::endl;
		//delete temp;
		//delete left;
		//delete right;
		//delete top;
		//delete bottom;
		return test;
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
			resetSpeed();
			//velocityX = -velocityX;
			Ball* b = Ball::getInstance(485, 275, 25, 25, getSpeed());
			b->getVelocityX() = -getSpeed();
			ge.add(b);	
/* 			ge.add(getInstance(485, 275, 25, 25, getSpeed()));
			velocityX = -getSpeed(); */
					
		} else if (getRect().x <= 0) {
			ge.getScoreCollision()[0] = true;
			sys.playSfx("score4416.wav");
			ge.remove(this);
			//Ball* ball = Ball::getInstance(475, 275, 25, 25, 12);
			resetSpeed();		
			ge.add(getInstance(485, 275, 25, 25, getSpeed()));		
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
