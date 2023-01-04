#include "Ball.h"
#include "MovableSprite.h"
#include "Constants.h"
#include "System.h"
#include "Engine.h"
#include <cmath>
#include <iostream>

namespace cwing {
	
	Ball::Ball(int x, int y, int w, int h, int speed) : MovableSprite(x, y, w, h, speed) { 
		texture = IMG_LoadTexture(sys.getRen(), (constants::gResPath + "pong_ball.png").c_str());
		velocityX = getSpeed(); 
		velocityY = 0;
		setSpriteType("ball");
	}

	Ball* Ball::getInstance(int x, int y, int w, int h, int speed) {
		return new Ball(x, y, w, h, speed);
	}

	void Ball::draw() {
		SDL_RenderCopy(sys.getRen(), texture, NULL, &getRect());
	}

	void Ball::paddleCollision() {  
		for (Sprite* s : ge.getSprites()) {
			if (s->getSpriteType() == "paddle") { 
				Paddle* p = dynamic_cast<Paddle*>(s);
				paddleBounceAngleH(p);
			}
		}	
	}

	void Ball::paddleBounceAngleH(Paddle* p){
		if (p->getPlayerID() == 1) {
			if (SDL_HasIntersection(&getRect(), &(p->getRect()))) {
				double relativeY = (p->getRect().y + (p->getRect().h / 2)) - (getRect().y + (getRect().h / 2)); 
				double normalizeRY = relativeY / (p->getRect().h / 2);
				if (normalizeRY > 1) {
					normalizeRY = 1;
				} 
				if (normalizeRY < -1) {
					normalizeRY = -1;
				} 
				double angle = normalizeRY * (13 * 3.14 / 36); 
				velocityX = -getSpeed() * cos(angle);
				velocityY = getSpeed() * -sin(angle);
				sys.playSfx("p_hit4416.wav");
			}
		} else if (p->getPlayerID() == 2) {
			if (SDL_HasIntersection(&getRect(), &(p->getRect()))) {
				double relativeY = (p->getRect().y + (p->getRect().h / 2)) - (getRect().y + (getRect().h / 2)); 
				double normalizeRY = relativeY / (p->getRect().h / 2);
				if (normalizeRY > 1) {
					normalizeRY = 1;
				}
				if (normalizeRY < -1) {
					normalizeRY = -1;
				}
				double angle = normalizeRY * (13 * 3.14 / 36); 
				velocityX = getSpeed() * cos(angle);
				velocityY = getSpeed() * -sin(angle);
				sys.playSfx("p_hit4416.wav");
			}
		}
	}
	
	void Ball::tick() {
		paddleCollision();

		if (getRect().x + getRect().w >= sys.getWidth()) {
			ge.getScoreCollision()[1] = true;
			sys.playSfx("score4416.wav");
			ge.remove(this); 
			resetSpeed();
			Ball* b = Ball::getInstance(437, 275, 25, 25, getSpeed());
			b->getVelocityX() = -getSpeed();
			ge.add(b);				
		} else if (getRect().x <= 0) {
			ge.getScoreCollision()[0] = true;
			sys.playSfx("score4416.wav");
			ge.remove(this);
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

		getRect().x += velocityX;
		getRect().y += velocityY;
	}

	Ball::~Ball() {
		std::cout << "Ball dest anropas" << std::endl;
		SDL_DestroyTexture(texture);
	}

}
