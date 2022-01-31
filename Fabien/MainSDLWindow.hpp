#ifndef MainSDLWindow_HPP
#define MainSDLWindow_HPP
#include <SDL2/SDL.h>

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
        bool isRunning;
        SDL_Rect srcR, dstR;

        int dir;
        

        const char *lastKeyPressed = "";
        Uint32 frame_time_start = SDL_GetTicks();
        Uint32 frame_ime_interval = SDL_GetTicks() - frame_time_start;
    protected :
        SDL_Renderer *renderer; 
        SDL_Texture *snakeSprite;
};
#endif