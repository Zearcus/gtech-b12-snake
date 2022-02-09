#pragma once

#include "Window.hpp"

class SpriteLoader
{

public:
    SpriteLoader();
    ~SpriteLoader();
    static SDL_Texture *LoadSprite(const char *fileName, SDL_Renderer *ren);
};
