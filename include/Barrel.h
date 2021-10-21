#ifndef BARREL_H
#define BARREL_H
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "../include/Object.h"
#include "../include/Meteor.h"
#include "Collisionable.h"

class Barrel: public Object ,public Collisionable{
    public:
        Barrel(const sf::Vector2f &pos);
        bool isCollision(const Collisionable& _object)const;
        sf::FloatRect getBounds() const;
        void update();
        void draw(sf::RenderWindow &w) override;
        sf::Sprite &getSprite();
    private:
        sf::Texture texbarrel;
        sf::Sprite spbarrel;

};

#endif // BARREL_H
