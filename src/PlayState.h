#ifndef PLAYSTATE_H
#define PLAYSTATE_H
#include "GameState.h"
#include <SDL2/SDL.h>
#include <memory>

namespace cwing {
	class PlayState: public GameState
	{
	public:
		PlayState();
		static std::unique_ptr<GameState> getInstance();
		void enterState();
		void updateState();
		void exitState();
		void stateEvents(SDL_Event& event);
		void renderState();
		~PlayState(); 
	};
}
#endif

