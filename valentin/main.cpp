#include "MainSDLWindow.hpp"
#include "game.hpp"
#include "snake.hpp"
#include <iostream>
#include <stdio.h>
using namespace std;


// #ifndef GAME_CPP
// #define GAME_CPP

// Snake *snake = nullptr;
Game *game = nullptr;
MainSDLWindow *window = nullptr;
    
int main(int argc, char* argv[])
{
    // snake = new Snake();
    game = new Game();
    window = new MainSDLWindow();

    window->Init("Snake!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, false);

    while (window->running())   
    {

        window->handleEvents();
        window->update();
        window->render();
        

        SDL_Delay(20);

    }
    window->clean();
    

    return 0;
}

// #endif