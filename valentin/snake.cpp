#include "snake.hpp"


Snake::Snake()
{
    this->head = new Segment();
}

Snake *snake = nullptr;
snake = new Snake();

Snake::~Snake()
{
    if (this->head)
    {
        delete this->head;
    }
    
}
void Snake::Eat()
{


    this->tail->next = new Segment(x, y);
    this->tail = this->tail->next;

    Segment* previousLast = this->head;
    // Find the previous last segment
    while(previousLast->next != this->tail)
    {
        previousLast = previousLast->next;
    }
}

bool collision()
{

}

Segment::Segment(int xx, int yy)
{

    this->next = NULL;
    this->x = xx;
    this->y = yy;

}

    // Définir tête serpent.
    // Lui assigner le sprite
    // Créer addSegment(donner un sprite aux segments) - les faire suivre la tête
    // Condition if (nextSeg) == NULL) |segment a un pointeur sur nextSeg| ALORS
    // if fruit a été mangé -> addSegment