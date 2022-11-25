#ifndef BALL_H
#define BALL_H
#include <SDL.h>
#include <SDL_image.h>
#include "MovableSprite.h"
#include "Sprite.h"

namespace cwing{

class Ball : public MovableSprite
{
private:
	int x, y, w, h;
	int speed;
	int direction;
public:
	Ball(int x, int y, int w, int h);
	void tick(){}
	
	~Ball();
};

}


#endif

