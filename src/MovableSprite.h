#ifndef MOVABLESPRITE_H
#define MOVABLESPRITE_H
#include "Sprite.h"

namespace cwing {
	class MovableSprite : public Sprite	{
	private:
		int speed, oldSpeed;
	protected:
		MovableSprite(int x, int y, int w, int h, int speed); 
	public:
		const int getSpeed() const;
		void setSpeed(double newSpeed);
		void resetSpeed();
		void draw() {}
		void tick() {}
		virtual ~MovableSprite();
	};
}
#endif
