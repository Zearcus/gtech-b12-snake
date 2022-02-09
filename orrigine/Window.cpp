
#include <SDL2/SDL.h>
#include "snake.hpp"
#include "Window.hpp"
#include <iostream>

using namespace std;

// #define MOVE_SPEED 4
#define WINDOW_WIDTH  900
#define WINDOW_HEIGHT  900
#define BLOC_SIZE 30
#define NUMBER_BLOCKS_WIDTH 40
#define NUMBER_BLOCKS_HEIGHT 40


Window::Window()
{
    this->renderer = NULL;
    this->window = NULL;
}

Window::~Window()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    // SDL_Quit();
    cout << "Game cleaned!" << endl;
}

int Window::WindowInit(const char* nameWindow, int posX, int posY, int rendererW, int rendererH, bool fullscreen)
{
    window = SDL_CreateWindow(nameWindow, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, rendererW, rendererH, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        cout << "Error: SDL_CreateWindow() failed : " << SDL_GetError() << endl;
        // isRunning = false;
        return EXIT_FAILURE; // Quit program
    }
    // else
    // {
    //     isRunning = true;
    // }

    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, 66, 245, 87, SDL_ALPHA_OPAQUE);

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "Error: Init() function failed : " << SDL_GetError() << endl;
        // isRunning = false;
        return EXIT_FAILURE; // Quit program
    }
    // else
    // {
    //     isRunning = true;
    // }
    return 0;
}

void Window::ClearRenderer(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
}

SDL_Renderer *Window::GetRenderer(void)
{
    return this -> renderer;
}

PlayGround::PlayGround(SDL_Renderer* r)
{
    renderer = r;
}