#ifndef SNAKE_HPP
#define SNAKE_HPP


class Snake
{
public:
    Snake(int longueur);
    ~Snake();

    void addSegment();

private:
    Segment *head;
};
#endif