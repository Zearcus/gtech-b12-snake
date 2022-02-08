#include "snake.hpp"
#include "MainSDLWindow.hpp"


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


    this->tail->next = new Segment(xx, yy);
    this->tail = this->tail->next;

    Segment* previousLast = this->head;
    // Find the previous last segment
    while(previousLast->next != this->tail)
    {
        previousLast = previousLast->next;
    }
}

bool collisionWithBorder()
{
    if(this->x < 0 || this->x > WINDOW_WIDTH || this->y < 0 || this->y > WINDOW_HEIGHT)
    {
        return true;
    }
}

Segment::Segment(int xx, int yy)
{

    this->x = xx;
    this->y = yy;
    this->next = NULL;

}

int Segment::addSegment(int xx, int yy)
{
    if (next != NULL)
    {
        next->addSegment(xx, yy);
    }else {
        this->next = new Segment(xx, yy);
    }
}



    // Définir tête serpent.
    // Lui assigner le sprite
    // Créer addSegment(donner un sprite aux segments) - les faire suivre la tête
    // Condition if (nextSeg) == NULL) |segment a un pointeur sur nextSeg| ALORS
    // if fruit a été mangé -> addSegment