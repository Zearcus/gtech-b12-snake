#include "fruit.hpp"
#include "MainSDLWindow.hpp"
#include "game.hpp"
#include "SpriteManager.hpp"



void MainSDLWindow::render(){
    SDL_RenderCopy(renderer, appleSprite, NULL, &dstA);
}

int randomFruitSpawn(int min, int max)
{
    return (rand() % (max - min)) + min;
}

int Apple::apple(int min, int max){
//     return (rand()% (max - min)) + min;

//    if(min = 1 && max = 10){
//      return spawn = true;
//    }
//    else
//    {
//      spawn = false;
//    }
    
};
