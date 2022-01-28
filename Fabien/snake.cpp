class Snake
{
    public:
        Snake(int longueur);
        ~Snake();

        void addSegment();


    private:
        Segment* head;

};


void Snake::addSegment()
{

}

int main()
{
    Snake snake(5);

}