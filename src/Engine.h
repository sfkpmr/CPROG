#ifndef ENGINE_H
#define ENGINE_H
#include <vector>
#include <memory>
#include "Sprite.h"
#include "GameState.h"

//huvudsaklig program
namespace cwing {

	class Engine
	{
	public:
		void add(Sprite* s); // skapa och addera komponenter
		void remove(Sprite* s);
		const std::vector<Sprite*> getSprites() const;
		bool* getKeyStateCheck(); //inte pekare?
		bool* getScoreCollision();
		bool& getQuit();
		void setMaxScore(int max);
		const int getMaxScore() const;
		void setCurrentState(std::unique_ptr<GameState> state);
		GameState* getCurrentState() const;
		//GameState* getNextState();
		void run(); // en händelse loop, vänter på nästa händelse och sen går igenom komponenter och anropar deras motsvarande event-handetings metod
	private:
		std::vector<Sprite*> sprites; //innehåller sprites som ska behandlas under iterering
		std::vector<Sprite*> added; //innehåller objekt som adderas före iterering
		std::vector<Sprite*> removed; //innehåller sprites som tas bort under iterering
		std::unique_ptr<GameState> currentState;
		//GameState* nextState;
		bool keyStateCheck[4] = {}; //FRÅGA OM RÄTT
		bool scoreCollision[2] = {};
		int maxScore;
		bool quit;
	};
	extern Engine ge;
}
#endif
