#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <SDL2/SDL.h>

namespace cwing {
	class GameState
	{
	private:
		//GameState* currentState = NULL;
		GameState* nextState = NULL;
	public:
		void setNextState(GameState* state);
		//GameState* getCurrentState();
		//void setCurrentState(GameState* state);
		void changeState();
		virtual void enterState() {}
		virtual void updateState() {}
		virtual void exitState() {}
		virtual void stateEvents(SDL_Event& event) {}
		virtual void renderState() {}
		virtual ~GameState();
	};
}
#endif
