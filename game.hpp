#ifndef game_HPP
#define game_HPP

class Game {
    public:
        Game();
        ~Game();

        void handleEvents();
        void update();
        void render();
        // void clean();

        bool running() {return isRunning; };

    private:
        bool isRunning;
        SDL_Renderer *renderer; 
        SDL_Texture *appleSprite;
        SDL_Rect srcR, dstR;
        const char *lastKeyPressed = "";
        const Uint8 *keystates = SDL_GetKeyboardState(NULL);
};
#endif