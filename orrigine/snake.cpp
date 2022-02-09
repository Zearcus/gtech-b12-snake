#include "snake.hpp"
#include "Game.hpp"
#include "Window.hpp"
#include "Window.hpp"
#include "Game.hpp"

// Snake *s = new Snake();

bool Snake::collisionWithBorder()
{
    if (head->x < 0 || head->x >= WINDOW_WIDTH || head->y < 0 || head->y >= WINDOW_HEIGHT)
    {
        return true;
    }
    return false;
}
Segment::Segment(int xx, int yy) 
{

    this->x = xx;
    this->y = yy;

    this->next = NULL;
}

Segment::~Segment()
{
    
}

bool Snake::collisionWithHimself()
{
    while (head->next != NULL)
    {
        if (head->x == head->next->x && head->y == head->next->y)
        {
            return true;
        }
    }
    return false;
}

void Segment::addSegment(int xx, int yy)
{

    if (next != NULL)
    {
        next->addSegment(xx, yy);
    }
    else
    {
        this->next = new Segment(xx, yy);
    }
}

void Snake::Draw(SDL_Renderer *renderer, int r, int g, int b, int a)
{
    SDL_Rect rect;
    rect.h = BLOC_SIZE;
    rect.w = BLOC_SIZE;
    Segment *currentSeg = head;

    while (currentSeg != NULL)
    {
        rect.x = currentSeg->x * BLOC_SIZE;
        rect.y = currentSeg->y * BLOC_SIZE;
        SDL_RenderDrawRect(renderer, &rect);
        SDL_SetRenderDrawColor(renderer, r, g, b, a);
        SDL_RenderFillRect(renderer, &rect);
        currentSeg = currentSeg->next;
    }
}

Snake::Snake()
{
    this->head = new Segment(this->x, this->y);
    this->head->addSegment(this->x, this->y);
}

void Snake::MoveUp()
{head->y -= BLOC_SIZE;}

void Snake::MoveDown()
{head->y += BLOC_SIZE;}

void Snake::MoveRight()
{head->x += BLOC_SIZE;}

void Snake::MoveLeft()
{head->x -= BLOC_SIZE;}

Snake::~Snake()
{
    if (this->head)
    {
        delete this->head;
    }
}
void Snake::Eat()
{

    this->tail->next->addSegment(this->x, this->y);
    this->tail = this->tail->next;

    Segment *previousLast = this->head;
    // Find the previous last segment
    while (previousLast->next != this->tail)
    {
        previousLast = previousLast->next;
    }
}

// Définir tête serpent.
// Lui assigner le sprite
// Créer addSegment(donner un sprite aux segments) - les faire suivre la tête
// Condition if (nextSeg) == NULL) |segment a un pointeur sur nextSeg| ALORS
// if fruit a été mangé -> addSegment