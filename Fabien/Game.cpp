#include <iostream>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Window.hpp"
#include "game.hpp"
#include "SpriteManager.hpp"
#include "fruit.hpp"

// #include "MoveSprite.hpp"

using namespace std;

// // SNAKE = tête + corps1 + corps2 + corps3 + fin (variables héritant de la tête globale. dernière partie bouge sur partie suivante etc, tête elle avance d'une unité)

// class Snake
// {
//     public:
//         Snake()
//       {
//           this -> x = 0;
//           this -> y = 0;
//           this -> head = 0;

//       }
//       ~Snake()
//       { // Destruct
//           if (nextSnake != NULL)
//           {
//               delete nextSnake;
//           }
//       }
//       int move(int newx, int newy)
//       {
//           if (nextSnake != NULL)
//           {
//               nextSnake.move(x, y);
//           }
//           this -> x = newx;
//           this -> y = newy;
//           return 0;
//       }

//       int turn(int degree)
//       {
//           this -> head = degree;
//           return 0;
//       }

//       int createSnake()
//         { // Crée le next serpent
//             if (nextSnake != NULL)
//             {
//                 nextSnake.createSnake();
//             }
//             else
//             {
//                 Snake temporarySnake;
//                 this -> nextSnake = temporarySnake;
//             }

//         }

//     private:
//         int x;
//         int y;
//         int head;
//         Snake* nextSnake;

// };

Window::Window()
{
    this->window = NULL;
    this->renderer = NULL;
}

Game::Game() {}

Window::~Window()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int Window::Init(const char *nameWindow, int posX, int posY, int rendererW, int rendererH, bool fullscreen)
{
    window = SDL_CreateWindow(nameWindow, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, rendererW, rendererH, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        cout << "Error: SDL_CreateWindow() failed" << endl;
        isRunning = false;
        return EXIT_FAILURE; // Quit program
    }
    else
    {
        isRunning = true;
    }

    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "Error: Init() function failed" << endl;
        isRunning = false;
        return EXIT_FAILURE; // Quit program
    }
    else
    {
        isRunning = true;
    }

    // SDL_Surface* tempSurface = IMG_Load("SpriteSnake/apple.png");
    // snakeSprite = SDL_CreateTextureFromSurface(renderer, tempSurface);
    // SDL_FreeSurface(tempSurface);

    snakeSprite = SpriteManager::LoadSprite("SpriteSnake/snakeHeadDown.png", renderer);
    appleSprite = SpriteManager::LoadSprite("SpriteSnake/apple.png", renderer);
    // à enlever si prob
    return EXIT_SUCCESS;

    // SDL_RenderClear(renderer);
}

void Window::handleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0)
    {

        switch (event.type)
        {
        case SDL_QUIT:
            isRunning = false; // Quit
            break;

        case SDL_KEYDOWN:
            std::cout << "Entered" << std::endl;
            switch (event.key.keysym.sym)
            {

            case SDLK_z:
                cout << "Up" << endl;
                if (dir != 2)
                {
                    dir = 1;
                }
                // snakeSprite = SpriteManager::LoadSprite("SpriteSnake/snakeHeadUp.png", renderer);
                break;

            case SDLK_s:
                cout << "Down" << endl;
                if (dir != 1)
                {
                    dir = 2;
                }
                // snakeSprite = SpriteManager::LoadSprite("SpriteSnake/snakeHeadDown.png", renderer);

                break;

            case SDLK_d:
                cout << "Right" << endl;
                if (dir != 4)
                {
                    dir = 3;
                }

                // snakeSprite = SpriteManager::LoadSprite("SpriteSnake/snakeHeadRight.png", renderer);
                break;
            case SDLK_q:
                cout << "Left" << endl;
                if (dir != 3)
                {
                    dir = 4;
                }
                // snakeSprite = SpriteManager::LoadSprite("SpriteSnake/snakeHeadLeft.png", renderer);
            }

        default:
            break;
        }

        // default:
        //     break;
    }
    if (dir == 1)
    {
        dstR.y = dstR.y - 2;
    }
    if (dir == 2)
    {
        dstR.y = dstR.y + 2;
    }
    if (dir == 3)
    {
        dstR.x = dstR.x + 2;
    }
    if (dir == 4)
    {
        dstR.x = dstR.x - 2;
    }
}

void Window::update()
{

    // counter++;
    dstR.h = 48;
    dstR.w = 48;

    dstA.h = 48;
    dstA.w = 48;

    // cout << counter << endl;
}

void Window::render()
{
    SDL_RenderClear(renderer);
    // Where we add stuff to render
    SDL_RenderCopy(renderer, snakeSprite, NULL, &dstR);
    // SDL_RenderDrawRect(renderer, &rect);
    SDL_RenderCopy(renderer, appleSprite, NULL, &dstA);

    SDL_RenderPresent(renderer);
}

void Window::clean()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    // SDL_Quit();
    std::cout << "Game cleaned!" << std::endl;
    exit(0);
}

// g++ main.cpp -lSDL2 -o main && ./main