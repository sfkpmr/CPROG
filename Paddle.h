#ifndef PADDLE_H
#define PADDLE_H
#include <SDL.h>
#include <SDL_image.h>
#include "Component.h"
#include "System.h"

namespace cwing {
	class Paddle : public Component
	{
	private:
		int x;
		int y;
		int width;
		int height;
		SDL_Texture* texture;
	public:
		Paddle(int x, int y, int width, int height);
		void draw();
		void keyDown(const SDL_Event&);
		void keyUp(const SDL_Event&);
		~Paddle();
	};
}

#endif
