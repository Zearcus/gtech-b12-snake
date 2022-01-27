#include "SpriteManager.hpp"
#include <SDL2/SDL_image.h>

SDL_Texture* SpriteManager::LoadSprite(const char* sprite, SDL_Renderer* ren)
{
    SDL_Surface* tempSurface = IMG_Load(sprite);
    SDL_Texture* sprt = SDL_CreateTextureFromSurface(ren, tempSurface);
    SDL_FreeSurface(tempSurface);

    return sprt; 
}