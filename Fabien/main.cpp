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

    game.gameLoop();
    SDL_Delay(20);
    
        
    
    return 0;

}
