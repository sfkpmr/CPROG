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
	protected:
		SDL_Texture* texture;
	public:
		MovableSprite(int x, int y, int w, int h, int speed);
		int getSpeed() const;
		void draw();
		virtual void tick() = 0;
		~MovableSprite();
	};
}


#endif
