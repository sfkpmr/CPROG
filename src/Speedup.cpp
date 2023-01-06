#include "Speedup.h"
#include "Constants.h"
#include "System.h"
#include "Engine.h"
#include "Ball.h"
#include <iostream>
#include <SDL2/SDL_image.h>

namespace cwing{
    Speedup::Speedup(int x, int y, int w, int h): Sprite(x, y, w, h){
        texture = IMG_LoadTexture(sys.getRen(), (constants::gResPath + "speedup.png").c_str());
        setSpriteType("speedup");
    }

    Speedup* Speedup::getInstance(int x, int y, int w, int h){ //tillåter inte värdesemantik. Konstruktor private.
        return new Speedup(x,y,w,h);
    }

    void Speedup::draw(){
        SDL_RenderCopy(sys.getRen(), texture, NULL, &getRect());
    }

    void Speedup::tick(){
        ballCollision();
    }

    void Speedup::ballCollision(){
		for(Sprite* s : ge.getSprites()){
			if (s->getSpriteType() == "ball"){ 
                Ball* b = dynamic_cast<Ball*>(s);
				if(SDL_HasIntersection(&getRect(), &(b->getRect()))){
                    ge.remove(this);
                    b->setSpeed(1.3);
				}
			}
		}
	}

    Speedup::~Speedup(){
        std::cout << "Speedup dest" << std::endl;
        SDL_DestroyTexture(texture);
    }
}