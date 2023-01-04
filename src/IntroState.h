#ifndef INTROSTATE_H
#define INTROSTATE_H
#include "GameState.h"
#include <SDL2/SDL.h>
#include <memory>

namespace cwing {
	class IntroState: public GameState
	{
	public:
		IntroState();
		static std::unique_ptr<GameState> getInstance();
		void enterState();
		void updateState();
		void exitState();
		void stateEvents(SDL_Event& event);
		void renderState();
		~IntroState(); 
	};
}
#endif
