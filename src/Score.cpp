#include "Score.h"
#include "Engine.h"
#include <string>
#include <iostream>

namespace cwing {
	Score::Score(int x, int y, int fontSize, int pID): Text(x, y, "0", fontSize), playerID(pID) {
		setSpriteType("score");
	}

	Score* Score::getInstance(int x, int y, int fontSize, int playerID) {
		return new Score(x, y, fontSize, playerID);
	}

	void Score::tick() {
		if (ge.getScoreCollision()[0] && playerID == 1) {
			score++;
			setText(std::to_string(score));
			ge.getScoreCollision()[0] = false;
		} else if (ge.getScoreCollision()[1] && playerID == 2) {
			score++;
			setText(std::to_string(score));
			ge.getScoreCollision()[1] = false;
		}
	}

	const int Score::getScore() const {
		return score;
	}

	Score::~Score(){
		std::cout << "Score dest" << std::endl;
	}
}