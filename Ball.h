#ifndef BALL_H
#define BALL_H
#include <SDL.h>
#include <SDL_image.h>
#include "Component.h"

namespace cwing{

class Ball : public Component
{
private:
	int speed;
	int direction;
	SDL_Texture* texture;
public:
	Ball();
	void draw() const;
	~Ball();
};

}


#endif

