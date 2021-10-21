#ifndef DEFENDER_R_H
#define DEFENDER_R_H
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Defender_R.h"
#include "Collisionable.h"

class Defender_R: public Object ,public Collisionable{
    public:
        Defender_R(const sf::Vector2f &pos);
        void update() override;
        bool isCollision(const Collisionable& _object)const;
        sf::FloatRect getBounds() const;
        void draw(sf::RenderWindow &w) override;
        sf::Sprite &getSprite();
    private:
        sf::Sprite spDefender_R;
        sf::Texture texDefender_R;
        float rotacion = 0;

};

#endif // DEFENDER_R_H
