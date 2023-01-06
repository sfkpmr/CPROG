#include "Sprite.h"
#include <iostream>

namespace cwing {

	Sprite::Sprite(int x, int y, int w, int h) :rect{x, y, w, h} 
	{
		
	}

	Sprite::~Sprite() {
		std::cout << "Sprite dest anropas" << std::endl;
	}

}