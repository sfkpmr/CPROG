#ifndef BALL_H
#define BALL_H
#include <SDL.h>
#include <SDL_image.h>
#include "MovableSprite.h"
#include "Paddle.h"
#include "Sprite.h"
#include <string>


namespace cwing{

class Ball : public MovableSprite
{
private:
	//int x, y, w, h;
	//SDL_Texture* texture;
	Ball(int x, int y, int w, int h, int speed);
	double velocityX, velocityY;
	std::string direction = "UP";
public:
	static Ball* getInstance(int x, int y, int w, int h, int speed);
	//void draw();
	//bool checkBounds();
	void paddleCollision();
	void tick();
	~Ball();
};

}


#endif

