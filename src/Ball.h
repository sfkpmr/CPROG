#ifndef BALL_H
#define BALL_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "MovableSprite.h"
#include "Sprite.h"
#include "Paddle.h"
#include <string>

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
	void paddleBounceAngleH(Paddle* p);
	void paddleBounceAngleV(Paddle* p);
	void tickHorizontal();
	void tickVertical();
	void tick();
	void draw();
	double& getVelocityX() { return velocityX; }
	double& getVelocityY() { return velocityY; }
	~Ball();
};
}
#endif

