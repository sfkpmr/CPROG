#include "Powerup.h"
#include "Constants.h"
#include "System.h"
#include <iostream>
#include <SDL_image.h>

namespace cwing{
    Powerup::Powerup(int x, int y, int w, int h): Sprite(x, y, w, h){
        texture = IMG_LoadTexture(sys.getRen(), (constants::gResPath + "star.png").c_str());
        //hidden = false;
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

/*     bool Powerup::getHidden(){
        return hidden;
    }

    void Powerup::hide(){
        hidden = !hidden;
        std::cout << hidden << std::endl;
    } */

    Powerup::~Powerup(){
        SDL_DestroyTexture(texture);
    }

}