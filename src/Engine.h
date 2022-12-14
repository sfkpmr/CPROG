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
		void run(); // en händelse loop, vänter på nästa händelse och sen går igenom komponenter och anropar deras motsvarande event-handetings metod
		~Engine();
	private:
		std::vector<Sprite*> sprites; //innehåller sprites som ska behandlas under iterering
		std::vector<Sprite*> added; //innehåller objekt som adderas före iterering
		std::vector<Sprite*> removed; //innehåller sprites som tas bort under iterering
		GameState* currentState = NULL;
		bool keyStateCheck[4] = {}; //FRÅGA OM RÄTT
		bool scoreCollision[2] = {};
	};
	extern Engine ge;
}
#endif
