#include "Sprite.h"

namespace cwing {

	Sprite::Sprite(int x, int y, int w, int h) :rect{x, y, w, h} 
	{
	}
	//vi har en rect, en rect är innesluten i objektet så när objektet försvinner så gör det recten oxå
	//vi har då inget att ta bort, men desktuktorn ska finnas då den är virtuell
	Sprite::~Sprite() {

	}

}