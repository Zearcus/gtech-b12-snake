#pragma once

#include "SpriteLoader.hpp"
#include "SDL2/SDL.h"

class Segment
{
    public :
        int x, y;
        Segment* next;

        Segment(int xx, int yy);
        ~Segment();

        void addSegment(int xx, int yy);
        // int HasNext();
        // Segment* GetNext();
        // coordinates GetCoords();

        void SetPosition();
        SDL_Rect srcS, dstS;




    private :
};   




class Snake
{
public:
    Segment* head;
    int x, y;

    Snake();
    ~Snake();
    
    void Eat();
    void Draw(SDL_Renderer * renderer, int r, int g, int b, int a);   
    int length();
    void MoveUp();
    void MoveDown();
    void MoveRight();
    void MoveLeft();
    bool collisionWithBorder();
    bool collisionWithHimself();
    int dir;
    // Snake* GetHead();

private:
    Segment* tail;  
    // coordinates previvous_tail_coords ;
    
};
