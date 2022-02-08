#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "SpriteLoader.hpp"



class Snake
{
public:
    Snake *head;
    Snake *tail;

    Snake();
    ~Snake();
    
    void Eat();
    Snake* GetHead();
    int collisionWithBorder();
    int length();

private:
    // coordinates previvous_tail_coords ;
    
};


class Segment
{
    public :
        Segment *next;

        Segment(int xx, int yy);
        ~Segment();

        int addSegment(int xx, int yy);
        // int addSegment(int xx, int yy);
        // int HasNext();
        // Segment* GetNext();
        // coordinates GetCoords();

        void SetPosition();
    private :
        int x, y;
        // coordinates coords;
};   
#endif