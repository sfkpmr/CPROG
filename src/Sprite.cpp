#include "Sprite.h"
#include <iostream>

namespace cwing {

	Sprite::Sprite(int x, int y, int w, int h) :rect{x, y, w, h} 
	{
		
	}
	//vi har en rect, en rect �r innesluten i objektet s� n�r objektet f�rsvinner s� g�r det recten ox�
	//vi har d� inget att ta bort, men desktuktorn ska finnas d� den �r virtuell
	Sprite::~Sprite() {
		std::cout << "Sprite dest anropas" << std::endl;
	}

}