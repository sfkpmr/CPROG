#ifndef ENGINE_H
#define ENGINE_H
#include <vector>
#include "Sprite.h"

//huvudsaklig program
namespace cwing {

	class Engine
	{
	public:
		void add(Sprite* c); // skapa och addera komponenter
		void remove(Sprite* c);
		void run(); // en händelse loop, vänter på nästa händelse och sen går igenom komponenter och anropar deras motsvarande event-handetings metod
		~Engine();
	private:
		std::vector<Sprite*> comps; //innehåller sprites som ska behandlas under iterering
		std::vector<Sprite*> added; //innehåller objekt som adderas under iterering
		std::vector<Sprite*> removed; //innehåller sprites som tas bort under iterering
	};

}
#endif
