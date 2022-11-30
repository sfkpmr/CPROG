#ifndef MOVABLESPRITE_H
#define MOVABLESPRITE_H
#include "Sprite.h"

namespace cwing {
	class MovableSprite: public Sprite
	{
	private:
		//int x, y, w, h;
		//std::string direction;
		int speed;
		//int directionX;
		//int directionY;
	protected:
		MovableSprite(int x, int y, int w, int h, int speed);
		SDL_Texture* texture;
	public:
		int getSpeed() const;
		virtual void draw();
		void tick() {}
		//vitual dest?
		virtual ~MovableSprite();
	};
}


#endif
