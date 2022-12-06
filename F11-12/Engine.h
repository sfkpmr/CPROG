#ifndef ENGINE_H
#define ENGINE_H
#include <vector>
#include "Sprite.h"
#include "GameState.h"
#include "IntroState.h"

//huvudsaklig program
namespace cwing {

	class Engine
	{
	public:
		void add(Sprite* c); // skapa och addera komponenter
		void remove(Sprite* c);
		std::vector<Sprite*> getSprites() const;
		bool* getKeyStateCheck();
		bool* getScoreCollision();
		void setCurrentState(GameState* state);
		GameState* getCurrentState();
		void run(); // en h�ndelse loop, v�nter p� n�sta h�ndelse och sen g�r igenom komponenter och anropar deras motsvarande event-handetings metod
		~Engine();
	private:
		std::vector<Sprite*> sprites; //inneh�ller sprites som ska behandlas under iterering
		std::vector<Sprite*> added; //inneh�ller objekt som adderas f�re iterering
		std::vector<Sprite*> removed; //inneh�ller sprites som tas bort under iterering
		GameState* currentState = NULL;
		bool keyStateCheck[4] = {}; //FR�GA OM R�TT
		bool scoreCollision[2] = {};
	};
	extern Engine ge;
}
#endif
