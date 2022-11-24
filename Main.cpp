#include <SDL.h>
#include <string>
#include "Session.h"
#include "Component.h"
#include "Ball.h"
#include "Paddle.h"

using namespace std;
using namespace cwing;


int main(int argc, char** argv) {
	Session ses;

	Component* ball = new Ball();
	Component* paddle_l = new Paddle(30, 250, 20, 100);
	Component* paddle_r = new Paddle(970, 250, 20, 100);
	ses.add(paddle_l);
	ses.add(paddle_r);
	ses.add(ball);
	ses.run();

	return 0;
}