#ifndef BASESCENE_H
#define BASESCENE_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Object.h"
#include <vector>

using namespace std;

class BaseScene
{
    public:
        BaseScene();
        virtual void update();
        virtual void draw(sf::RenderWindow &w);
        void add(Object *o);
        void remove(Object *o);

    private:
        vector<Object *> objects;
};

#endif // BASESCENE_H
