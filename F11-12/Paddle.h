#ifndef PADDLE_H
#define PADDLE_H
#include <SDL.h>
#include <SDL_image.h>
#include "MovableSprite.h"


namespace cwing {
	class Paddle : public MovableSprite
	{
	private:
		//std::string direction;
		//char moveOne, moveTwo;
		int playerId;
	public:
		Paddle(int x, int y, int width, int height, int speed, int player);
		void keyDown(const SDL_Event& eve);
		void keyUp(const SDL_Event& eve);
		
		void tick(){}
		~Paddle();
	};
}

#endif
