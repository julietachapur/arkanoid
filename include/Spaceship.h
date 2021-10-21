#ifndef SPACESHIP_H
#define SPACESHIP_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Object.h"
#include "Meteor.h"
#include "Collisionable.h"

class Spaceship: public Object ,public Collisionable{
    public:
        Spaceship(const sf::Vector2f &pos);
        void update();
        bool isCollision(const Collisionable& _object)const;
        sf::FloatRect getBounds() const;
        void draw(sf::RenderWindow &w) override;
        sf::Sprite &getSprite();

    private:
        sf::Sprite spSpaceship;
        sf::Texture texSpaceship;
};
#endif // SPACESHIP_H
