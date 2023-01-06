#include "Sizedown.h"
#include "Constants.h"
#include "System.h"
#include "Engine.h"
#include <iostream>
#include <SDL2/SDL_image.h>

namespace cwing{
    Sizedown::Sizedown(int x, int y, int w, int h): Sprite(x, y, w, h){
        texture = IMG_LoadTexture(sys.getRen(), (constants::gResPath + "sizedown.png").c_str());
        setSpriteType("sizedown");
    }

    Sizedown* Sizedown::getInstance(int x, int y, int w, int h){ 
        return new Sizedown(x,y,w,h);
    }

    void Sizedown::draw(){
        SDL_RenderCopy(sys.getRen(), texture, NULL, &getRect());
    }

    void Sizedown::tick(){
        ballCollision();
    }

    void Sizedown::ballCollision(){
        for(Sprite* s : ge.getSprites()){
			if (s->getSpriteType() == "ball"){ 
				if(SDL_HasIntersection(&getRect(), &(s->getRect()))){
					ge.remove(this);
                    s->getRect().h = s->getRect().h / 1.5;
                    s->getRect().w = s->getRect().w / 1.5;
				}
			}
		}
    }

    Sizedown::~Sizedown(){
        std::cout << "Sizedown dest" << std::endl;
        SDL_DestroyTexture(texture);
    }
}