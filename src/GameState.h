#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <SDL2/SDL.h>
#include <memory>

namespace cwing {
	class GameState
	{
	private:
		//GameState* currentState = NULL;
		std::unique_ptr<GameState> nextState;
	public:
		void setNextState(std::unique_ptr<GameState> state);
		//GameState* getNextState() const;
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
