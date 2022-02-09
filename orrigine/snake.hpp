#pragma once

#include "SpriteLoader.hpp"
#include "SDL2/SDL.h"


class Segment
{
    public :
        int x, y;
        Segment* next;

        Segment(int xx, int yy, SDL_Renderer* NewRenderer);
        ~Segment();

        void addSegment(int xx, int yy);
        void ApplyHeadSprite(int angle);
        void ApplyAndGoNext(int angle);
        


        void SetPosition();
        SDL_Rect srcS, dstS;




    private :
        SDL_Texture* HeadSprite;
        SDL_Texture* BodySprite;
        SDL_Texture* L_BodySprite;
        SDL_Texture* TailSprite;

        SDL_Renderer* renderer;
};   




class Snake
{
public:
    Segment* head;
    int x, y;

    Snake();
    ~Snake();
    
    void Eat();
    void ShowSnake();

    int length();

void DrawRectOnRenderer(SDL_Rect rect, SDL_Renderer * renderer, int r, int g, int b, int a);   
void ShowSpriteOnRenderer(SDL_Texture* sprite, SDL_Renderer * renderer, SDL_Rect position, int angle = 0);
    void MoveUp();
    void MoveDown();
    void MoveRight();
    void MoveLeft();
    void changeDirection(int dir);

    bool collisionWithBorder();
    bool collisionWithHimself();
    SDL_Renderer *renderer;
    int dir;
    int dirX;
    int dirY;
    // Snake* GetHead();

private:
    Segment* tail;  
    // coordinates previvous_tail_coords ;
    
};

class SpriteLoader
{

public:
    SpriteLoader();
    ~SpriteLoader();
    static SDL_Texture *LoadSprite(const char *fileName, SDL_Renderer *ren);
};
