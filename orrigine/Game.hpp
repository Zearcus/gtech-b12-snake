
#pragma once
#include "Window.hpp"
#include "snake.hpp"

class Game
{
public:
    Game();
    ~Game();

    void gameLoop();
    void gameInit();
    
    bool running() {return isRunning; };

private:
    int count;
    bool isRunning;
    int dir;
    Window* mainWindow;
    SDL_Renderer* renderer;
    PlayGround *playground;
    Snake* s;
    // Fruit* fruit;


};
