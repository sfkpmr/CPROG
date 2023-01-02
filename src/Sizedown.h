#ifndef SIZEDOWN_H
#define SIZEDOWN_H
#include "Sprite.h"

namespace cwing{
    class Sizedown : public Sprite
    {
    private:
        SDL_Texture* texture;
        Sizedown(int x, int y, int w, int h);
    public:
        static Sizedown* getInstance(int x, int y, int w, int h);
        void draw(); 
		void tick();
        void ballCollision();
        ~Sizedown();
    };
}
#endif