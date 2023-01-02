#include "MovableSprite.h"
#include "Sprite.h"
#include "System.h"
#include <iostream>

namespace cwing {

	MovableSprite::MovableSprite(int x, int y, int w, int h, int speed): Sprite(x, y, w, h), speed(speed), oldSpeed(speed) {
		
	}

	const int MovableSprite::getSpeed() const {
		return speed;
	}

	void MovableSprite::setSpeed(double newSpeed){
		speed *= newSpeed;
	}

	void MovableSprite::resetSpeed(){
		speed = oldSpeed;
	}
		
	MovableSprite::~MovableSprite() {
		std::cout << "MS dest anropas" << std::endl;
	}
}

