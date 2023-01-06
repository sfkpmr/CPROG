#include <SDL2/SDL.h>
#include <string>
#include "Engine.h"
#include "System.h"
#include "Sprite.h"
#include "Ball.h"
#include "Paddle.h"
#include "Text.h"
#include "Score.h"
#include "Speedup.h"
#include "Sizedown.h"
#include <iostream>

using namespace cwing;

int main(int argc, char** argv) {
	//normal game sprites 
	ge.setMaxScore(7); //sets the desired max score (5 per default)
	Sprite* ball = Ball::getInstance(437, 275, 25, 25, 13);
	Sprite* paddle_l = Paddle::getInstance(10, 250, 20, 100, 12, 2);
	Sprite* paddle_r = Paddle::getInstance(870, 250, 20, 100, 12, 1);
	ge.add(ball);
	ge.add(paddle_l);
	ge.add(paddle_r);
	//normal game sprites end

	//extra game sprites
	Sprite* powerUp1 = Speedup::getInstance(300,300,30,30);
	Sprite* powerUp2 = Speedup::getInstance(600,150,30,30);
	Sprite* sizedown1 = Sizedown::getInstance(300, 400, 30, 30);
	Sprite* sizedown2 = Sizedown::getInstance(100, 300, 30, 30);
	ge.add(powerUp1);
	ge.add(powerUp2);
	ge.add(sizedown1);
	ge.add(sizedown2);
	//extra game sprites end
	//run, main engine loop
	ge.run();

	return 0;
}