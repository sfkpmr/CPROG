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
		MovableSprite(int x, int y, int w, int h, int speed); //https://stackoverflow.com/a/16814901 
		SDL_Texture* texture; //not protected 
	public:
		int getSpeed() const;
		void setSpeed();
		void draw(); //virtual eller ej???
		void tick() {}
		//vitual dest?
		virtual ~MovableSprite();
	};
}


#endif
