#ifndef INTROSTATE_H
#define INTROSTATE_H
#include "GameState.h"
#include <SDL2/SDL.h>


namespace cwing {
	class IntroState: public GameState
	{
	private:
		IntroState();
	public:
		static IntroState* getInstance();
		void enterState();
		void updateState();
		void exitState();
		void stateEvents(SDL_Event& event);
		void renderState();
	};
}
#endif
