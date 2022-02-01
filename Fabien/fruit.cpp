#include "fruit.hpp"
#include "MainSDLWindow.hpp"
#include "game.hpp"
#include "SpriteManager.hpp"



void MainSDLWindow::render(){
    SDL_RenderCopy(renderer, appleSprite, NULL, &dstA);
}

class apple : public Fruits, public MainSDLWindow{
    // effet et sprite de la pomme
    // int random(int min, int max){

    // }
};

class leek : public Fruits{
    // effet et sprite du poireau
};

class aubergine : public Fruits{
    // effet et sprite de l'aubergine
};

class cookie : public Fruits{
    // effet et sprite du cookie

};