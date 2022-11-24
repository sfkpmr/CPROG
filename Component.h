#ifndef COMPONENT_H
#define COMPONENT_H
#include <SDL.h>

namespace cwing {
	class Component
	{
	public:
		//virtual för att säkerställa att desktrutorer hos subklasser anropas när man tar bort ett objekt 
		virtual ~Component();
		// vi har event hanterare funktioner i Component för att inte behöva kolla för varje komponent om de ska anropa mouseUp t.ex eller inte,
		// dvs om de ska reagera på en event eller inte. Label ska inte reagera på någon event alls t.ex
		//alla ska vara virtual eftersom varje komponent reagerar olika på olika events
		//vi kan inte bara deklarera funktioner då de inte kommer att ha nån generel implementation som sagt, men vi kan inte göra de abstracta då
		//label måste då implementera de oxå, då kan man lämna de som tumma funktioner där varje subklass kan eller inte välja definiera de, de ärver en tum f
		//const SDL_Event& for att ta reda på vilken komponents koordinater hände en event, och då e det eve från Session klassen vi skickar till funktioner
		virtual void mouseDown(const SDL_Event&){}
		virtual void mouseUp(const SDL_Event&){}
		virtual void keyDown(const SDL_Event&){}
		virtual void keyUp(const SDL_Event&){}
		virtual void draw() const = 0; // abstract class, ingen generel implementering, subklasser måste definiera implementationen av draw()
		const SDL_Rect getRect() const { return rect; }; // för att kunna ha åtkomst till rect
	protected:
		//konstruktorn i protected för att vi vill inte att man ska skapa objekt utav komponent klassen, den är bara en basklass till subklasser Button osv..
		//komponenter ska ha sina koordinater och storlek
		Component(int x, int y, int w, int h);
		SDL_Rect rect;
	private:
		//SDL_Rect rect; //för att komponenter ska kunna ha sina koordinater
		//här förbjuder vi kopiering respektive tilldelning
		Component(const Component&) = delete;
		const Component& operator=(const Component&) = delete;
	};
}
#endif