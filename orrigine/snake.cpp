#include "snake.hpp"
#include "Game.hpp"
#include "SpriteLoader.hpp"
#include <SDL2/SDL_image.h>
#include "Window.hpp"


// SDL_Texture* SpriteLoader::LoadSprite(const char* sprite, SDL_Renderer* ren);
// void Snake::DrawRectOnRenderer(SDL_Rect rect, SDL_Renderer *renderer, int r, int g, int b, int a);

// Snake *s = new Snake();
// Window win = new Window();
Segment::Segment(int xx, int yy, SDL_Renderer *NewRenderer) 
{

    this->x = xx;
    this->y = yy;
    this->next = NULL;

    this->renderer = NewRenderer;

    this->HeadSprite = SpriteLoader::LoadSprite("SpriteSnake/snakeHeadDown.png", renderer);
    this->BodySprite = SpriteLoader::LoadSprite("SpriteSnake/snakeCorpseHorizontal.png", renderer);
    this->L_BodySprite = SpriteLoader::LoadSprite("SpriteSnake/bottomrightCorpse.png", renderer);
    this->TailSprite = SpriteLoader::LoadSprite("SpriteSnake/tailUp.png", renderer);
}

Segment::~Segment()
{
    
    SDL_DestroyTexture(this->HeadSprite);
    SDL_DestroyTexture(this->BodySprite);
    SDL_DestroyTexture(this->L_BodySprite);
    SDL_DestroyTexture(this->TailSprite);
}

void Segment::addSegment(int xx, int yy)
{

    if (next != NULL)
    {
        next->addSegment(xx, yy);
    }
    else
    {
        this->next = new Segment(xx, yy, renderer);
    }
}

void Segment::ApplyAndGoNext(int angle)
{
    if(next != NULL)
    {
        int NextAngle = 90 * ((this->x, this->y) * (this->x - this->next->x) + this->y - this->next->y);

        if(this->x == this->next->x && this->y == this->next->y)
        {
            this -> next-> ApplyAndGoNext(angle);
        }
        else if(NextAngle != angle)
        {
            if((NextAngle + 360) % 360 - angle == 90) 
            {
                angle -= 90;
            }
            ShowSpriteOnRenderer(this->L_BodySprite, this->renderer, {this->x, this->y}, angle);
            this->next-> ApplyAndGoNext(NextAngle);
        }else {
            ShowSpriteOnRenderer(this->BodySprite, this->renderer, {this->x, this->y}, angle);
            this->next-> ApplyAndGoNext(NextAngle);
        }
    }
    else{
        ShowSpriteOnRenderer(this->TailSprite, this->renderer, {this->x, this->y}, angle);
    }
}

void Segment::ApplyHeadSprite(int angle)
{
    ShowSpriteOnRenderer(this->HeadSprite, this->renderer, {this->x, this->y}, angle);
}







// FIXME:       Snake Part
Snake::Snake()
{
    this->head = new Segment(this->x, this->y, this->renderer);
    // this->head->addSegment(this->x, this->y);
}


bool Snake::collisionWithBorder()
{
    if (head->x < 0 || head->x >= WINDOW_WIDTH || head->y < 0 || head->y >= WINDOW_HEIGHT)
    {
        return true;
    }
    return false;
}

bool Snake::collisionWithHimself()
{
    if(head->next == NULL) return false;
    Segment *seg = head->next;
    while (seg != NULL)
    {
        if (head->x == seg->x && head->y == seg->y)
        {
            return true;
        }
        seg = seg->next;
    }
    return false;
}




void Snake::ShowSnake() {
    this-> head -> next-> ApplyAndGoNext( 90 * ((this->head->x - this->head->next->x - 1) * (this->head->x - this->head->next->x ) + this->head->y - this->head->next->y));
    this-> head -> ApplyHeadSprite(90 * ( (dirX - 1) * dirX + dirY));
}



void Snake::MoveUp()
{head->y -= BLOC_SIZE;}

void Snake::MoveDown()
{head->y += BLOC_SIZE;}

void Snake::MoveRight()
{head->x += BLOC_SIZE;}

void Snake::MoveLeft()
{head->x -= BLOC_SIZE;}

void Snake::changeDirection(int dir) {
    dirX = (1 - dir % 2) * (1 - dir);
    dirY = -(dir % 2 ) * (dir - 2);
}

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

    // Segment *previousLast = this->head;
    // // Find the previous last segment
    // while (previousLast->next != this->tail)
    // {
    //     previousLast = previousLast->next;
    // }
}


SDL_Texture* SpriteLoader::LoadSprite(const char* sprite, SDL_Renderer* ren)
{
    SDL_Surface* tempSurface = IMG_Load(sprite);
    SDL_Texture* sprt = SDL_CreateTextureFromSurface(ren, tempSurface);
    SDL_FreeSurface(tempSurface);
    

    return sprt; 
}

 void Snake::DrawRectOnRenderer(SDL_Rect rect, SDL_Renderer *renderer, int r, int g, int b, int a)
{
    
    rect.h = BLOC_SIZE;
    rect.w = BLOC_SIZE;
    

    rect.x = rect.x * BLOC_SIZE;
    rect.y = rect.y * BLOC_SIZE;
    SDL_RenderDrawRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, r, g, b, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &rect);
        

        
    
}

 void Snake::ShowSpriteOnRenderer(SDL_Texture* sprite, SDL_Renderer * renderer, SDL_Rect position, int angle)
{
    position.h = BLOC_SIZE;
    position.y = BLOC_SIZE;

    position.x = position.x * BLOC_SIZE;
    position.y = position.y * BLOC_SIZE;
    SDL_RenderCopyEx(renderer, sprite, NULL, &position, angle, NULL, SDL_FLIP_NONE);
        
       
}
// Définir tête serpent.
// Lui assigner le sprite
// Créer addSegment(donner un sprite aux segments) - les faire suivre la tête
// Condition if (nextSeg) == NULL) |segment a un pointeur sur nextSeg| ALORS
// if fruit a été mangé -> addSegment