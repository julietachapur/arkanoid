#ifndef DEFENDER_L_H
#define DEFENDER_L_H
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Defender_L.h"
#include "Collisionable.h"

class Defender_L: public Object ,public Collisionable{
    public:
        Defender_L(const sf::Vector2f &pos);
        void update() override;
        bool isCollision(const Collisionable& _object)const;
        sf::FloatRect getBounds() const;
        void draw(sf::RenderWindow &w) override;
        sf::Sprite &getSprite();

    private:
        sf::Sprite spDefender_L;
        sf::Texture texDefender_L;
        float rotacion = 0 ;
};

#endif // DEFENDER_L_H
