#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED
#include <SFML/Graphics.hpp>

class Object{

 public:
        virtual void update()=0;
        virtual void draw(sf::RenderWindow &w)=0;

};


#endif // OBJECT_H_INCLUDED
