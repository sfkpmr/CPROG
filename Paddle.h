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
	public:
		Paddle(int x, int y, int width, int height, int speed);
		void keyDown(const SDL_Event&);
		void keyUp(const SDL_Event&);
		
		
		void tick(){}
		~Paddle();
	};
}

#endif
