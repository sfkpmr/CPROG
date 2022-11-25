#include <SDL.h>
#include <string>
#include "Engine.h"
#include "Sprite.h"
#include "Ball.h"
#include "Paddle.h"

using namespace std;
using namespace cwing;


int main(int argc, char** argv) {
	Engine ge;

	Sprite* ball = new Ball(500 - 25, 300 - 25, 50, 50, 2);
	Sprite* paddle_l = new Paddle(30, 250, 20, 100, 1);
	Sprite* paddle_r = new Paddle(970, 250, 20, 100, 1);
	ge.add(paddle_l);
	ge.add(paddle_r);
	ge.add(ball);
	ge.run();

	return 0;
}