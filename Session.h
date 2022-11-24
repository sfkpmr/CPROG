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
		void run(); // en händelse loop, vänter på nästa händelse och sen går igenom komponenter och anropar deras motsvarande event-handetings metod
		~Session();
	private:
		std::vector<Component*> comps; //innehåller komponenter
	};

}
#endif
