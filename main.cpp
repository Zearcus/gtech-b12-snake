#include "MainSDLWindow.hpp"
#include "game.hpp"

// #ifndef GAME_CPP
// #define GAME_CPP

Game *game = nullptr;
MainSDLWindow *window = nullptr;
    
int main(int argc, char* argv[])
{
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