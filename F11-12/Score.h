#ifndef SCORE_H
#define SCORE_H
#include "Text.h"

namespace cwing {
	class Score: public Text
	{
	private:
		int score = 0;
		int playerID;
		bool scored;
		Score(int x, int y, int fontSize, int playerID);
	public:
		static Score* getInstance(int x, int y, int fontSize, int playerID);
		void tick();
		bool checkIfScored();
	};
}
#endif

