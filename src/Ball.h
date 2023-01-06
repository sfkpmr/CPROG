#ifndef BALL_H
#define BALL_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "MovableSprite.h"
#include "Paddle.h"

namespace cwing{
class Ball : public MovableSprite
{
private:
	Ball(int x, int y, int w, int h, int speed);
	double velocityX, velocityY;
	SDL_Texture* texture; 
public:
	static Ball* getInstance(int x, int y, int w, int h, int speed);
	void paddleCollision();
	void paddleBounceAngle(Paddle* p);
	void tick();
	void draw();
	double& getVelocityX();
	~Ball();
};
}
#endif

