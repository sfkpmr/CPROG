#ifndef ENGINE_H
#define ENGINE_H
#include <vector>
#include <memory>
#include "Sprite.h"
#include "GameState.h"

namespace cwing {

	class Engine
	{
	public:
		void add(Sprite* s); // skapa och addera komponenter
		void remove(Sprite* s);
		const std::vector<Sprite*> getSprites() const;
		bool* getKeyStateCheck(); 
		bool* getScoreCollision();
		bool& getQuit();
		void setMaxScore(int max);
		const int getMaxScore() const;
		void setCurrentState(std::unique_ptr<GameState> state);
		GameState* getCurrentState() const;
		void run(); // en händelse loop, väntar på nästa händelse och sen går igenom komponenter och anropar deras motsvarande event-handerings metod
	private:
		std::vector<Sprite*> sprites; //innehåller sprites som ska behandlas under iterering
		std::vector<Sprite*> added; //innehåller objekt som adderas före iterering
		std::vector<Sprite*> removed; //innehåller sprites som tas bort efter händelseloop
		std::unique_ptr<GameState> currentState;
		bool keyStateCheck[4] = {}; 
		bool scoreCollision[2] = {};
		int maxScore;
		bool quit;
	};
	extern Engine ge;
}
#endif
