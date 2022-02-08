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

Uint32 frame_time_start, frame_time, frame_delay = 80;

int main(int argc, char* argv[])
{
    // snake = new Snake();
    game = new Game();
    window = new MainSDLWindow();

    window->Init("Snake!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, false);

    while (window->running())   
    {
        frame_time_start = SDL_GetTicks();

        window->handleEvents();
        window->update();
        window->render();
        

        frame_time = SDL_GetTicks() - frame_time_start;
        if(frame_time < frame_delay)
        {
            SDL_Delay((frame_delay - frame_time));
            
        }

        // SDL_Delay(10);


    }
    window->clean();
    

    return 0;
}

// #endif