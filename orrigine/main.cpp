#include <iostream>
#include <stdio.h>

#include "Window.hpp"
#include "Game.hpp"
#include "snake.hpp"

using namespace std;



// Snake *snake = new Snake();
// Game *game = nullptr;
// Window *window = nullptr;

// Uint32 frame_time_start, frame_time, frame_delay = 80;

int main(int argc, char *argv[])
{
    Game game;
    
    game.gameInit();
    while(isRunning)
    {
        game.gameLoop();
    }
        
    
    return 0;

}

    // snake = new Snake();
    // game = new Game();
    // window = new Window();

    // window->Init("Snake!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, false);

    // while (window->running())
    // {
    //     frame_time_start = SDL_GetTicks();

    //     window->handleEvents();
    //     window->update();
    //     window->render();

    //     frame_time = SDL_GetTicks() - frame_time_start;
    //     if (frame_time < frame_delay)
    //     {
    //         SDL_Delay((frame_delay - frame_time));
    //     }

    //     // SDL_Delay(10);
    // }
    // window->clean();

    // return 0;
