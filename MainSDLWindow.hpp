#ifndef MainSDLWindow_HPP
#define MainSDLWindow_HPP
#include <SDL2/SDL.h>

#define MOVE_SPEED 2
#define WINDOW_WIDTH 1600
#define WINDOW_HEIGHT 900


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
    private:
        
        SDL_Window *window;
        SDL_Renderer *renderer;   
        bool isRunning;
        SDL_Texture *snakeSprite;
        SDL_Rect srcR, dstR;

        int dir;
        

        const char *lastKeyPressed = "";
        Uint32 frame_time_start = SDL_GetTicks();
        Uint32 frame_ime_interval = SDL_GetTicks() - frame_time_start;

        
};
#endif