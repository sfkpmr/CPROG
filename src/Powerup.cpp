#include "Powerup.h"
#include "Constants.h"
#include "System.h"
#include <SDL2/SDL_image.h>

namespace cwing{
    Powerup::Powerup(int x, int y, int w, int h): Sprite(x, y, w, h){
        texture = IMG_LoadTexture(sys.getRen(), (constants::gResPath + "star.png").c_str());
        setSpriteType("powerup");
    }

    Powerup* Powerup::getInstance(int x, int y, int w, int h){ //tillåter inte värdesemantik. Konstruktor private.
        return new Powerup(x,y,w,h);
    }

    void Powerup::draw(){
        SDL_RenderCopy(sys.getRen(), texture, NULL, &getRect());
    }

    void Powerup::tick(){

    }

    Powerup::~Powerup(){
        SDL_DestroyTexture(texture);
    }

}