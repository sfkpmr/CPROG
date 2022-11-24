#ifndef SESSION_H
#define SESSION_H
#include <vector>
#include "Component.h"

//huvudsaklig program
namespace cwing {

	class Session
	{
	public:
		void add(Component* c); // skapa och addera komponenter
		void run(); // en h�ndelse loop, v�nter p� n�sta h�ndelse och sen g�r igenom komponenter och anropar deras motsvarande event-handetings metod
		~Session();
	private:
		std::vector<Component*> comps; //inneh�ller komponenter
	};

}
#endif
