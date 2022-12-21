#ifndef BALL_H
#define BALL_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "MovableSprite.h"
#include "Sprite.h"
#include "Obstacle.h"
#include <string>


namespace cwing{

class Ball : public MovableSprite
{
private:
	//int x, y, w, h;
	//SDL_Texture* texture;
	Ball(int x, int y, int w, int h, int speed);
	double velocityX, velocityY;
	//std::string direction = "UP";
	//int ticksSinceLH;
public:
	static Ball* getInstance(int x, int y, int w, int h, int speed);
	//void draw();
	//bool checkBounds();
	void paddleCollision();
	void obstacleCollision();
	SDL_Point getCenter();
	int getClosestObsticle(Obstacle* o); //change name?
	void tick();
	double& getVelocityX() { return velocityX; }
	//void setVelocityX(double v) { velocityX = v; }
	~Ball();
};

}
#endif

