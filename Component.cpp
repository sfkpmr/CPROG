#include "Component.h"

namespace cwing {

	Component::Component(int x, int y, int w, int h) :rect{x, y, w, h} 
	{
	}
	//vi har en rect, en rect är innesluten i objektet så när objektet försvinner så gör det recten oxå
	//vi har då inget att ta bort, men desktuktorn ska finnas då den är virtuell
	Component::~Component() {

	}

}