#include <SDL.h>
#include <string>
#include "Session.h"
#include "Component.h"
#include "Ball.h"

using namespace std;
using namespace cwing;


int main(int argc, char** argv) {
	Session ses;

	Component* ball = new Ball();
	ses.add(ball);
	ses.run();

	return 0;
}