#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H
#include "GameState.h"
#include <SDL.h>
#include <SDL_image.h>

namespace cwing {
	class GameOverState: public GameState
	{
	private:
		GameOverState();
	public:
		static GameOverState* getInstance();
		void enterState();
		void updateState();
		void exitState();
		void stateEvents(SDL_Event& event);
		void renderState();
	};
}
#endif

