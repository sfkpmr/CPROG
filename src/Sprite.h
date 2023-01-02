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
		// vi har event hanterare funktioner i Component f�r att inte beh�va kolla f�r varje komponent om de ska anropa mouseUp t.ex eller inte,
		// dvs om de ska reagera p� en event eller inte. Label ska inte reagera p� n�gon event alls t.ex
		//alla ska vara virtual eftersom varje komponent reagerar olika p� olika events
		//vi kan inte bara deklarera funktioner d� de inte kommer att ha n�n generel implementation som sagt, men vi kan inte g�ra de abstracta d�
		//label m�ste d� implementera de ox�, d� kan man l�mna de som tumma funktioner d�r varje subklass kan eller inte v�lja definiera de, de �rver en tum f
		//const SDL_Event& for att ta reda p� vilken komponents koordinater h�nde en event, och d� e det eve fr�n Session klassen vi skickar till funktioner
		//virtual void mouseDown(const SDL_Event&){}
		//virtual void mouseUp(const SDL_Event&){}
		virtual void keyDown(const SDL_Event&){}
		virtual void keyUp(const SDL_Event&){}
		virtual void draw() = 0; // abstract class, ingen generel implementering, subklasser m�ste definiera implementationen av draw()
		virtual void tick() = 0; //f�r att kontrollera objekt n�r inget h�nder, updatera de. Ball ska ha den, d� den r�rs utan input, Paddle ska inte ha.
		void setSpriteType(std::string type) {spriteType = type;}
		const std::string getSpriteType() const {return spriteType;} // check const
		SDL_Rect& getRect() { return rect; }; // f�r att kunna ha �tkomst till rect
		//SDL_Texture* getTexture() { return texture; };
	};
}
#endif