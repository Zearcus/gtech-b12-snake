#ifndef SpriteLoader_HPP
#define SpriteLoader_HPP

#include "MainSDLWindow.hpp"

class SpriteLoader{

    public:
        SpriteLoader();
        ~SpriteLoader();
        static SDL_Texture* LoadSprite(const char* fileName, SDL_Renderer* ren);
};
#endif