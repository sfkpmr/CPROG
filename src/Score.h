#ifndef SCORE_H
#define SCORE_H
#include "Text.h"

namespace cwing {
	class Score: public Text
	{
	private:
		int score {0};
		int playerID {0};
		Score(int x, int y, int fontSize, int playerID);
	public:
		static Score* getInstance(int x, int y, int fontSize, int playerID);
		void tick();
		const int getScore() const;
		~Score();
	};
}
#endif

