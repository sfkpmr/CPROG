#ifndef COMPONENT_H
#define COMPONENT_H
#include <SDL.h>

namespace cwing {
	class Component
	{
	public:
		//virtual f�r att s�kerst�lla att desktrutorer hos subklasser anropas n�r man tar bort ett objekt 
		virtual ~Component();
		// vi har event hanterare funktioner i Component f�r att inte beh�va kolla f�r varje komponent om de ska anropa mouseUp t.ex eller inte,
		// dvs om de ska reagera p� en event eller inte. Label ska inte reagera p� n�gon event alls t.ex
		//alla ska vara virtual eftersom varje komponent reagerar olika p� olika events
		//vi kan inte bara deklarera funktioner d� de inte kommer att ha n�n generel implementation som sagt, men vi kan inte g�ra de abstracta d�
		//label m�ste d� implementera de ox�, d� kan man l�mna de som tumma funktioner d�r varje subklass kan eller inte v�lja definiera de, de �rver en tum f
		//const SDL_Event& for att ta reda p� vilken komponents koordinater h�nde en event, och d� e det eve fr�n Session klassen vi skickar till funktioner
		virtual void mouseDown(const SDL_Event&){}
		virtual void mouseUp(const SDL_Event&){}
		virtual void keyDown(const SDL_Event&){}
		virtual void keyUp(const SDL_Event&){}
		virtual void draw() const = 0; // abstract class, ingen generel implementering, subklasser m�ste definiera implementationen av draw()
		const SDL_Rect getRect() const { return rect; }; // f�r att kunna ha �tkomst till rect
	protected:
		//konstruktorn i protected f�r att vi vill inte att man ska skapa objekt utav komponent klassen, den �r bara en basklass till subklasser Button osv..
		//komponenter ska ha sina koordinater och storlek
		Component(int x, int y, int w, int h);
		SDL_Rect rect;
	private:
		//SDL_Rect rect; //f�r att komponenter ska kunna ha sina koordinater
		//h�r f�rbjuder vi kopiering respektive tilldelning
		Component(const Component&) = delete;
		const Component& operator=(const Component&) = delete;
	};
}
#endif