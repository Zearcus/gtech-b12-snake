
#include "MainSDLWindow.hpp"
#include "fruit.hpp"
#include "SpriteManager.hpp"

using namespace std;

class apple : public Fruits, public MainSDLWindow{
    // effet et sprite de la pomme
    appleSprite = SpriteManager::LoadSprite("", renderer);
};

class leek : public Fruits{
    // effet et sprite du poireau
};

class aubergine : public Fruits{
    // effet et sprite de l'aubergine
};

class cookie : public Fruits{
    // effet et sprite du cookie

};