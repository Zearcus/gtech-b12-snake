#include <iostream>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Window.hpp"
#include "snake.hpp"
#include "Game.hpp"
#include "SpriteLoader.hpp"

// #include "MoveSprite.hpp"

using namespace std;

// Snake *snake = nullptr;
// snake = new Snake();

// Window::Window()
// {
//     this->window = NULL;
//     this->renderer = NULL;
// }

Game::Game() 
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0) { // SDL init error ?
        printf("Error initialization SDL : %s\n",SDL_GetError()); // Print error
        exit(1); // Quit to avoid more problems
  }
}

Game::~Game()
{
    delete this -> s;
    SDL_DestroyRenderer(renderer);
    delete this -> mainWindow;
    SDL_Quit();
}


void Game::gameLoop()
{
    Uint32 time = SDL_GetTicks();
    Uint32 frame_time_start, frame_time, frame_delay = 80;
    SDL_Event event;
    bool isRunning = true;

    while(isRunning)
    {
        // cout << "Game loop" << endl;
        // cout << "I'm count : " << count++  << endl;
        
        while (SDL_PollEvent(&this->event))
        {

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
                        {dir = 1;}
                        // UP
                        break;

                    case SDLK_s:
                        if (dir != 1)
                        {dir = 2;}
                        // DOWN
                        break;

                    case SDLK_d:
                        if (dir != 4)
                        {dir = 3;}
                        // RIGHT
                        break;
                    case SDLK_q:
                        if (dir != 3)
                        {dir = 4;}
                        // LEFT
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
            this->s->MoveUp();
        }
        if (dir == 2)
        {
            this->s->MoveDown();
        }
        if (dir == 3)
        {
            this->s->MoveRight();
        }
        if (dir == 4)
        {
            this->s->MoveLeft();
        }
        if (s->collisionWithBorder())
        {
            isRunning = false;
            cout << "Collide border" << endl;
        }
        if (s->collisionWithHimself())
        {
            isRunning = false;
            cout << "Collide himself" << endl;
        }




        // Drawing part
        this -> s -> ShowSnake();
        SDL_RenderPresent(renderer);

        // Frame Ratexxdsx
        frame_time = SDL_GetTicks() - frame_time_start;
        if (frame_time < frame_delay)
        {
            SDL_Delay((frame_delay - frame_time));
        }

    // if (this->fruit->x == this->s->head->x && this->fruit->y == this->s->head->y)
    // {
    //     this->s->Eat(this->fruit);
    //     cout << "\nEaten" << endl;
    // }
    // cout << "Coord pomme : " << box.y << "      " << box.x << endl;

    // cout << "Coord snake : " << this->s->x << "      " << this->s->y << "\n" << endl;
    }

}

void Game::gameInit()
{
    this -> mainWindow = new Window();
    this -> mainWindow -> WindowInit("Snake!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT);

    this -> renderer = mainWindow->GetRenderer();
    this -> playground = new PlayGround(renderer);

    this -> s = new Snake();
    // this -> fruit = new Fruit();
}

