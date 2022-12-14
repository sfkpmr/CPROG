#ifndef POWERUP_H
#define POWEUP_H
#include "Sprite.h"

namespace cwing{
    class Powerup : public Sprite
    {
    private:
        SDL_Texture* texture;
        Powerup(int x, int y, int w, int h);
    public:
        //void enablePowerup(int newSpeed);
        static Powerup* getInstance(int x, int y, int w, int h);
        void draw(); 
		void tick();
        ~Powerup();
    };
}

#endif