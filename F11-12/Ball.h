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
	//SDL_Texture* texture;
	Ball(int x, int y, int w, int h, int speed);
public:
	static Ball* getInstance(int x, int y, int w, int h, int speed);
	//void draw();
	void tick();
	~Ball();
};

}


#endif

