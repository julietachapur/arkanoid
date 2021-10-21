#ifndef COLLISIONABLE_H
#define COLLISIONABLE_H
#include <SFML/Graphics.hpp>

class Collisionable
{
    public:
        virtual bool isCollision(const Collisionable& _object) const = 0;
        virtual sf::FloatRect getBounds() const = 0;
};

#endif // COLLISIONABLE_H
