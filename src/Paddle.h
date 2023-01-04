#ifndef PADDLE_H
#define PADDLE_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "MovableSprite.h"


namespace cwing {
	class Paddle : public MovableSprite
	{
	private:
		int playerId;
		double velocity;
		SDL_Texture* texture; 
		Paddle(int x, int y, int width, int height, int speed, int player);
	public:
		static Paddle* getInstance(int x, int y, int width, int height, int speed, int player);
		const int getPlayerID() const;
		void keyDown(const SDL_Event& eve);
		void keyUp(const SDL_Event& eve);
		void draw();
		void tick();
		~Paddle();
	};
}
#endif
