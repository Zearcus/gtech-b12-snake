#ifndef Fruits_HPP
#define Fruits_HPP

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;
class Fruits
{
public:
    void update();

protected:
    int fruitNumber;
    int apple = 1, poireau = 2, aubergine = 3, cookie = 4;
    bool spawn;
    //  SDL_Texture *appleSprite;
    //  SDL_Rect srcA, dstA;
    // int quantityMaxfruits;
    // int rarity;
};

class Apple : public Fruits, public Window
{
    // effet et sprite de la pomme
public:
    int apple(int min, int max);
    ~Apple();
    // int position;
};

// class Leek : public Fruits{
//     // effet et sprite du poireau
// };

// class Aubergine : public Fruits{
//     // effet et sprite de l'aubergine
// };

// class Cookie : public Fruits{
//     // effet et sprite du cookie

// };
#endif

// Pomme :  rareté : commun / donne un segment supplémentaire au snake
// Poireau :  rareté : peu commun / diminue la vitesse du snake de 1 ou de 2
// Aubergine :  rareté : peu commun / VIAGRA POWER donne plusieurs segment au snake
// Cookie :  rareté : très rare / augmente la quantité de fruits sur la map