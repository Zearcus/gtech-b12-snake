#ifndef Fruits_HPP
#define Fruits_HPP

#include <iostream>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;
class Fruits
{
     public :
        Fruits();
        void effectFruit();

     protected :
        int apple = 1, poireau = 2, aubergine = 3, cookie = 4; 
         //  SDL_Texture *appleSprite;
         //  SDL_Rect srcA, dstA;
          // int quantityMaxfruits;
          // int rarity;

};
#endif

//Pomme :  rareté : commun / donne un segment supplémentaire au snake
//Poireau :  rareté : peu commun / diminue la vitesse du snake de 1 ou de 2
//Aubergine :  rareté : peu commun / VIAGRA POWER donne plusieurs segment au snake
//Cookie :  rareté : très rare / augmente la quantité de fruits sur la map