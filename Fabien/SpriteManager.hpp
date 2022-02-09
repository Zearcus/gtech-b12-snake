#ifndef SpriteManager_HPP
#define SpriteManager_HPP

#include "Window.hpp"

class SpriteManager
{

public:
    SpriteManager();
    ~SpriteManager();
    static SDL_Texture *LoadSprite(const char *fileName, SDL_Renderer *ren);
};
#endif