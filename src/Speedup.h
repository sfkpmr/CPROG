#ifndef SPEEDUP_H
#define SPEEDUP_H
#include "Sprite.h"

namespace cwing{
    class Speedup : public Sprite
    {
    private:
        SDL_Texture* texture;
        Speedup(int x, int y, int w, int h);
    public:
        static Speedup* getInstance(int x, int y, int w, int h);
        void draw(); 
		void tick();
        void ballCollision();
        ~Speedup();
    };
}
#endif