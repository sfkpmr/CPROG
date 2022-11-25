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
		void run(); // en h�ndelse loop, v�nter p� n�sta h�ndelse och sen g�r igenom komponenter och anropar deras motsvarande event-handetings metod
		~Engine();
	private:
		std::vector<Sprite*> comps; //inneh�ller sprites som ska behandlas under iterering
		std::vector<Sprite*> added; //inneh�ller objekt som adderas under iterering
		std::vector<Sprite*> removed; //inneh�ller sprites som tas bort under iterering
	};

}
#endif
