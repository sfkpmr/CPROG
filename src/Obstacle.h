#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "Sprite.h"

namespace cwing {
	class Obstacle : public Sprite {
	private:
		SDL_Texture* texture;
		Obstacle(int x, int y, int w, int h);
	public:
		static Obstacle* getInstance(int x, int y, int w, int h);
		virtual void draw();
		virtual void tick(){}
		SDL_Point getTopCenter();
		SDL_Point getBottomCenter();
		SDL_Point getLeftCenter();
		SDL_Point getRightCenter();
		~Obstacle();
	};
}
#endif