#include <iostream>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "MainSDLWindow.hpp"
#include "snake.hpp"
#include "game.hpp"
#include "SpriteLoader.hpp"

// #include "MoveSprite.hpp"

using namespace std;


// Snake *snake = nullptr;
// snake = new Snake();

MainSDLWindow::MainSDLWindow()
{
    this->window = NULL;
    this->renderer = NULL;
}

Game::Game() {}

MainSDLWindow::~MainSDLWindow()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int MainSDLWindow::Init(const char *nameWindow, int posX, int posY, int rendererW, int rendererH, bool fullscreen)
{
    window = SDL_CreateWindow(nameWindow, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, rendererW, rendererH, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        cout << "Error: SDL_CreateWindow() failed : "<< SDL_GetError() << endl;
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
    SDL_SetRenderDrawColor(renderer, 66, 245, 87, SDL_ALPHA_OPAQUE);

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "Error: Init() function failed : "<< SDL_GetError() << endl;
        isRunning = false;
        return EXIT_FAILURE; // Quit program
    }
    else
    {
        isRunning = true;
    }


    snakeSprite = SpriteLoader::LoadSprite("SpriteSnake/snakeHeadDown.png", renderer);
    
    return EXIT_SUCCESS;

    
}

void MainSDLWindow::handleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0)
    {

        // if(collisionWithBorder == true)
        // {
        //     isRunning = false;
        // }
            


        switch (event.type)
        {
        case SDL_QUIT:
            isRunning = false; // Quit
            break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {

            case SDLK_z:
                if (dir != 2)
                {
                    dir = 1;
                }
                break;

            case SDLK_s:
                if (dir != 1)
                {
                    dir = 2;
                }

                break;

            case SDLK_d:
                if (dir != 4)
                {
                    dir = 3;
                }
                break;
            case SDLK_q:
                if (dir != 3)
                {
                    dir = 4;
                }
            // case SDLK_x:

                
            }
            
        default:
            break;
        }

        // if(this->Apple->x == this->snake->x && this->Apple->y == this->snake->y)
        // {
        //     Snake::Eat();
        // }
    }


    

    if (dir == 1)
    {
        dstS.y -=  BLOC_SIZE;
        // dstS.y = dstS.y - MOVE_SPEED;
    }
    if (dir == 2)
    {
        dstS.y +=  BLOC_SIZE;
        // dstS.y = dstS.y + MOVE_SPEED;
    }
    if (dir == 3)
    {
        dstS.x +=  BLOC_SIZE;
        // dstS.x = dstS.x + MOVE_SPEED;
    }
    if (dir == 4)
    {
        dstS.x -=  BLOC_SIZE;
        // dstS.x = dstS.x - MOVE_SPEED;

    }
        if(dstS.y == box.y && dstS.x == box.x)
        {
            Snake s;
            cout << "Eaten" << endl;
            s.Eat();
        }
        cout << "\nCoord pomme : " << box.y << "      " << box.x << endl;

        cout << "Coord snake : " << dstS.x << "      " << dstS.y << endl;
}



void MainSDLWindow::update()
{
    dstS.h = BLOC_SIZE;
    dstS.w = BLOC_SIZE; 

    box.w = BLOC_SIZE; 
    box.h = BLOC_SIZE; 
    box.x = WINDOW_WIDTH/2;
    box.y = WINDOW_HEIGHT/2; 
    





}

void MainSDLWindow::render()
{
    // Color of background
    SDL_SetRenderDrawColor(renderer, 0 , 0 , 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    // Where we add stuff to render
    // SDL_RenderCopy(renderer, snakeSprite, NULL, &dstS);
    SDL_RenderDrawRect(renderer, &dstS);
    SDL_SetRenderDrawColor(renderer, 255 , 255 , 255, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &dstS);

    SDL_RenderDrawRect(renderer, &box);
    SDL_SetRenderDrawColor(renderer, 255 , 160 , 0, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &box);

    SDL_RenderPresent(renderer);
}

void MainSDLWindow::clean()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    // SDL_Quit();
    std::cout << "Game cleaned!" << std::endl;
    exit(0);
}

