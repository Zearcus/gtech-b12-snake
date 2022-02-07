#ifndef game_HPP
#define game_HPP

#include "MainSDLWindow.hpp"
#include "snake.hpp"

class Game : public MainSDLWindow
{ 
    public:
        Game();
        ~Game();

        void handleEvents();
        void update();
        void render();
        // void clean();

        // bool running() {return isRunning; };
        int dir;

    private:

        const Uint8 *keystates = SDL_GetKeyboardState(NULL);
};
#endif