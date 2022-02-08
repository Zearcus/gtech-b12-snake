#ifndef MainSDLWindow_HPP
#define MainSDLWindow_HPP
#include <SDL2/SDL.h>

// #define MOVE_SPEED 4
#define WINDOW_WIDTH  1000
#define WINDOW_HEIGHT  1000
#define BLOC_SIZE 30
#define NUMBER_BLOCKS_WIDTH 40
#define NUMBER_BLOCKS_HEIGHT 40


class MainSDLWindow {
    public:
        MainSDLWindow();
        ~MainSDLWindow();
        int Init(const char* nameWindow, int posX, int posY, int rendererW, int rendererH, bool fullscreen);
        // SDL_Renderer *GetRenderer(void){};

        void handleEvents();
        void update();
        void render();
        void clean();

        bool running() {return isRunning; };
        // return this->renderer;

    protected:
        SDL_Texture *snakeSprite;
        SDL_Rect srcS, dstS;
        SDL_Rect box;
        SDL_Renderer *renderer;   
        SDL_Window *window;
        bool isRunning;
        int dir;
        

    private:
        int map[NUMBER_BLOCKS_WIDTH][NUMBER_BLOCKS_HEIGHT] = {0};


        Uint32 frame_time_start = SDL_GetTicks();
        Uint32 frame_time_interval = SDL_GetTicks() - frame_time_start;

        
};
#endif