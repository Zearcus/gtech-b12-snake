#ifndef SpriteManager_HPP
#define SpriteManager_HPP

#include "MainSDLWindow.hpp"

class SpriteManager{

    public:
        SpriteManager();
        ~SpriteManager();
        static SDL_Texture* LoadSprite(const char* fileName, SDL_Renderer* ren);
};
#endif