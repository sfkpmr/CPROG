#ifndef BALL_H
#define BALL_H
#include <SDL.h>
#include <SDL_image.h>
#include "MovableSprite.h"



namespace cwing{

class Ball : public MovableSprite
{
private:
	//int x, y, w, h;
	//int direction;
public:
	Ball(int x, int y, int w, int h, int speed);
	void tick();
	
	~Ball();
};

}


#endif

