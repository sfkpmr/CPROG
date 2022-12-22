#ifndef PLAYSTATE_H
#define PLAYSTATE_H
#include "GameState.h"
#include <SDL.h>

namespace cwing {
	class PlayState: public GameState
	{
	private:
		PlayState();
	public:
		static PlayState* getInstance();
		void enterState();
		void updateState();
		void exitState();
		void stateEvents(SDL_Event& event);
		void renderState();
	};
}
#endif

