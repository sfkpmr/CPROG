#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H
#include "GameState.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <memory>

namespace cwing {
	class GameOverState: public GameState
	{
	public:
		static std::unique_ptr<GameState> getInstance();
		GameOverState();
		void enterState();
		void updateState();
		void exitState();
		void stateEvents(SDL_Event& event);
		void renderState();
		~GameOverState(); 
	};
}
#endif

