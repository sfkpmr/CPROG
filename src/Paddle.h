#ifndef PADDLE_H
#define PADDLE_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "MovableSprite.h"


namespace cwing {
	class Paddle : public MovableSprite
	{
	private:
		//std::string direction;
		//char moveOne, moveTwo;
		int playerId;
		double velocityY;
	public:
		Paddle(int x, int y, int width, int height, int speed, int player);
		int getPlayerID() const;
		void keyDown(const SDL_Event& eve);
		void keyUp(const SDL_Event& eve);
		
		void tick();
		~Paddle();
	};
}

#endif
