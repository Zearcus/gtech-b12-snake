#include "fruit.hpp"
#include "Window.hpp"
#include "game.hpp"
#include "SpriteManager.hpp"

// Game.cpp
//     appleSprite = SpriteManager::LoadSprite("SpriteSnake/apple.png", renderer);

// void Window::render(){
//     SDL_RenderCopy(renderer, appleSprite, NULL, &dstA);
// }

// void Window::update(){
//     dstA.h = 48;
//     dstA.w = 48;
// }

// Window.hpp
// SDL_Texture *appleSprite; // à enlever si prob

// int randomFruitSpawn(int min, int max)
// {
//     return (rand() % (max - min)) + min;
// }

void Fruits::update()
{
    srand((unsigned)time(0));
    for (int index = 0; index < 1; index++)
    {
        fruitNumber = (rand() % 100) + 1;
        // cout << fruitNumber << endl;
    }
};

int Apple::apple(int min, int max)
{

    if (fruitNumber < 50 && fruitNumber > 0) // ou != de 0/50
    {
        spawn = true;
        // segment = new segment();
        // eat();
    }
};
