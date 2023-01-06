#ifndef SPRITE_H
#define SPRITE_H
#include <SDL2/SDL.h>
#include <string>

namespace cwing {
	class Sprite
	{
	private:
		SDL_Rect rect;
		std::string spriteType;
		Sprite(const Sprite&) = delete;
		const Sprite& operator=(const Sprite&) = delete;
	protected:
		Sprite(int x, int y, int w, int h);
	public:
		//virtual för att säkerställa att desktrutorer hos subklasser anropas när man tar bort ett objekt 
		virtual ~Sprite();

		virtual void keyDown(const SDL_Event&){}
		virtual void keyUp(const SDL_Event&){}
		virtual void draw() = 0; // abstract class, ingen generel implementering, subklasser m�ste definiera implementationen av draw()
		virtual void tick() = 0; //f�r att kontrollera objekt n�r inget h�nder, updatera de. Ball ska ha den, d� den r�rs utan input, Paddle ska inte ha.
		void setSpriteType(std::string type) {spriteType = type;}
		const std::string getSpriteType() const {return spriteType;} // check const
		SDL_Rect& getRect() { return rect; }; // f�r att kunna ha �tkomst till rect
	};
}
#endif