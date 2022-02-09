#pragma once
#include <SDL2/SDL.h>
#include "snake.hpp"


// #define MOVE_SPEED 4
#define WINDOW_WIDTH  900
#define WINDOW_HEIGHT  900
#define BLOC_SIZE 30
#define NUMBER_BLOCKS_WIDTH 40
#define NUMBER_BLOCKS_HEIGHT 40


class Window {
    public:
        Window();
        ~Window();
        int WindowInit(const char* nameWindow, int posX, int posY, int rendererW, int rendererH);
        //  void DrawRectOnRenderer(SDL_Rect rect, SDL_Renderer * renderer, int r, int g, int b, int a);   

        //  void ShowSpriteOnRenderer(SDL_Texture* sprite, SDL_Renderer * renderer, SDL_Rect position, int angle = 0);

        // SDL_Renderer *GetRenderer(void){};

        // void handleEvents();
        // void update();
        // void render();
        // void clean();
        void ClearRenderer(SDL_Renderer* renderer);
        SDL_Renderer *GetRenderer();


        // bool running() {return isRunning; };
        // return this->renderer;

    protected:
        SDL_Renderer *renderer;   
        SDL_Window *window;


        // SDL_Texture *snakeSprite;
        
        // SDL_Rect box;
        // bool isRunning;
        // int dir;
        
        // Snake* s;

    private:
        int map[NUMBER_BLOCKS_WIDTH][NUMBER_BLOCKS_HEIGHT] = {0};

        Uint32 frame_time_start = SDL_GetTicks();
        Uint32 frame_time_interval = SDL_GetTicks() - frame_time_start;

        
};


class PlayGround {
    public:
        PlayGround(SDL_Renderer*);

    private:
        SDL_Renderer *renderer;
        
};
