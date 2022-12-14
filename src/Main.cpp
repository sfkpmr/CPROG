#include <SDL2/SDL.h>
#include <string>
#include "Engine.h"
#include "Sprite.h"
#include "Ball.h"
#include "Paddle.h"
#include "Text.h"
#include "Score.h"
#include "Obstacle.h"
#include <iostream>

using namespace std;
using namespace cwing;

int main(int argc, char** argv) {
	//Engine ge;

	//Sprite* ball = Ball::getInstance(500 - 25, 300 - 25, 50, 50, 10);
	Sprite* ball = Ball::getInstance(475, 275, 25, 25, 8);
	Sprite* paddle_l = new Paddle(10, 250, 20, 100, 8, 2);
	Sprite* paddle_r = new Paddle(970, 250, 20, 100, 8, 1);
	Sprite* hinder = Obstacle::getInstance(100,100,100,100);
/* 	Sprite* hinder1 = Obstacle::getInstance(200,200,50,50);
	Sprite* hinder2 = Obstacle::getInstance(400,400,50,50);
	Sprite* hinder3 = Obstacle::getInstance(500,300,50,50); */
	//Sprite* score_l = Score::getInstance(280, 30, 40, 2);
	//Sprite* score_r = Score::getInstance(700, 30, 40, 1);
	//ge.add(text);
	//ge.add(score_l);
	//ge.add(score_r);
	ge.add(paddle_l);
	ge.add(paddle_r);
	ge.add(ball);
	ge.add(hinder);
/* 	ge.add(hinder1);
	ge.add(hinder2);
	ge.add(hinder3); */
	ge.run();

	return 0;
}