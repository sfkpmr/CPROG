#include "Ball.h"
#include "MovableSprite.h"
#include "Constants.h"
#include "System.h"
#include "Engine.h"
#include <cmath>
#include <iostream>

namespace cwing {
	
	Ball::Ball(int x, int y, int w, int h, int speed) : MovableSprite(x, y, w, h, speed) { //, velocityX(getSpeed()), velocityY(0)
		texture = IMG_LoadTexture(sys.getRen(), (constants::gResPath + "pong_ball.png").c_str());
		if(sys.getOrientation() == "H"){
			velocityX = getSpeed(); // alltid rörs i x
			velocityY = 0; // velocity Y ändras först vid collision
		} else {
			velocityX = 0; // alltid rörs i x
		    velocityY = getSpeed(); // velocity Y ändras först vid collision
		}
		setSpriteType("ball");
	}

	Ball* Ball::getInstance(int x, int y, int w, int h, int speed) {
		return new Ball(x, y, w, h, speed);
	}

	void Ball::draw() {
		//const SDL_Rect& rect = getRect();
		//SDL_RenderCopy(sys.getRen(), texture, NULL, &getRect());
		SDL_RenderCopy(sys.getRen(), texture, NULL, &getRect());
	}

	void Ball::paddleCollision() {  
		for (Sprite* s : ge.getSprites()) {
			if (s->getSpriteType() == "paddle") { 
				Paddle* p = dynamic_cast<Paddle*>(s);
				if(sys.getOrientation() == "H"){
					paddleBounceAngleH(p);
				} else {
					paddleBounceAngleV(p);
				}
			}
		}	
	}

	void Ball::paddleBounceAngleH(Paddle* p){
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

	void Ball::paddleBounceAngleV(Paddle* p){
		if (p->getPlayerID() == 1) {
			if (SDL_HasIntersection(&getRect(), &(p->getRect()))) {
				double relativeX = (p->getRect().x + (p->getRect().w / 2)) - (getRect().x + (getRect().w / 2)); //var p� paddle tr�ffar bollen
				//d� paddle kan vara olika i h�jd, beh�ver vi normalisera relativeY s� vi f�r nummer mellar -1 och 1, och inte -5 och 5 om paddle �r 10 pixel h�g
				double normalizeRX = relativeX / (p->getRect().w / 2);
				if (normalizeRX > 1) {
					normalizeRX = 1;
				} 
				if (normalizeRX < -1) {
					normalizeRX = -1;
				} 
				double angle = normalizeRX * (13 * 3.14 / 36); //(5 * 3.14 / 12) -> max 75 grader. Byta till static const MAXANGLE?
				velocityY = -getSpeed() * cos(angle); //y ändrat uppe
				velocityX = getSpeed() * -sin(angle); //x ändrat uppe
				sys.playSfx("p_hit4416.wav");
			}
		} else if (p->getPlayerID() == 2) {
			if (SDL_HasIntersection(&getRect(), &(p->getRect()))) {
				double relativeX = (p->getRect().x + (p->getRect().w / 2)) - (getRect().x + (getRect().w / 2)); //var p� paddle tr�ffar bollen
				//d� paddle kan vara olika i h�jd, beh�ver vi normalisera relativeY s� vi f�r nummer mellar -1 och 1, och inte -5 och 5 om paddle �r 10 pixel h�g
				double normalizeRX = relativeX / (p->getRect().w / 2);
				if (normalizeRX > 1) {
					normalizeRX = 1;
				}
				if (normalizeRX < -1) {
					normalizeRX = -1;
				}
				double angle = normalizeRX * (13 * 3.14 / 36); //(5 * 3.14 / 12) -> max 75 grader. Byta till static const MAXANGLE?
				velocityY = getSpeed() * cos(angle);
				velocityX = getSpeed() * -sin(angle);
				sys.playSfx("p_hit4416.wav");
			}
		}
	}
	
	void Ball::tick() {
		// e i konstruktor nu
		//velocityX = getSpeed(); // alltid r�rs i x
		//velocityY = 0; // velocity Y �ndras f�rst vid collision
		paddleCollision();
		if(sys.getOrientation() == "H"){
			tickHorizontal();
		} else {
			tickVertical();
		}

		getRect().x += velocityX;
		getRect().y += velocityY;
	}

	void Ball::tickHorizontal(){
		if (getRect().x + getRect().w >= sys.getWidth()) {
			ge.getScoreCollision()[1] = true;
			sys.playSfx("score4416.wav");
			ge.remove(this); // kolla om det fungerar
			resetSpeed();
			//velocityX = -velocityX;
			Ball* b = Ball::getInstance(437, 275, 25, 25, getSpeed());
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
			ge.add(getInstance(437, 275, 25, 25, getSpeed()));		
		} 	
		if (getRect().y <= 0) {
			velocityY = -velocityY;
			sys.playSfx("w_hit4416.wav");
		} else if ((getRect().y + getRect().h) >= sys.getHeight()) {
			velocityY = -velocityY;
			sys.playSfx("w_hit4416.wav");
		}
	}

	void Ball::tickVertical(){
		if (getRect().y + getRect().h >= sys.getHeight()) {
			ge.getScoreCollision()[1] = true;
			sys.playSfx("score4416.wav");
			ge.remove(this); // kolla om det fungerar
			resetSpeed();
			//velocityX = -velocityX;
			Ball* b = Ball::getInstance(290, 435, 25, 25, getSpeed());
			b->getVelocityY() = -getSpeed();
			ge.add(b);	
/* 			ge.add(getInstance(485, 275, 25, 25, getSpeed()));
			velocityX = -getSpeed(); */					
		} else if (getRect().y <= 0) {
			ge.getScoreCollision()[0] = true;
			sys.playSfx("score4416.wav");
			ge.remove(this);
			resetSpeed();		
			ge.add(getInstance(290, 435, 25, 25, getSpeed()));		
		} 	
		if (getRect().x <= 0) {
			velocityX = -velocityX;
			sys.playSfx("w_hit4416.wav");
		} else if ((getRect().x + getRect().w) >= sys.getWidth()) {
			velocityX = -velocityX;
			sys.playSfx("w_hit4416.wav");
		}
	}

	Ball::~Ball() {
		std::cout << "Ball dest anropas" << std::endl;
		SDL_DestroyTexture(texture);
	}

}
