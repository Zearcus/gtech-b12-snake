#ifndef Fruits_HPP
#define Fruits_HPP

class Fruits
{
   public :
        fruits();
        void effectFruit();

   private :
        int apple = 1, poireau = 2, aubergine = 3, cookie = 4;  
        // int quantityMaxfruits;
        // int rarity;

};
#endif

//Pomme :  rareté : commun / donne un segment supplémentaire au snake
//Poireau :  rareté : peu commun / diminue la vitesse du snake de 1 ou de 2
//Aubergine :  rareté : peu commun / VIAGRA POWER donne plusieurs segment au snake
//Cookie :  rareté : très rare / augmente la quantité de fruits sur la map