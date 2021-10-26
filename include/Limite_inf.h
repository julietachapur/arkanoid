#ifndef LIMITE_INF_H
#define LIMITE_INF_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <time.h>
#include "Player.h"
#include "Object.h"
#include "Ball.h"
#include "Collisionable.h"

class Limite_inf:public Object, public Collisionable
{
    public:
        Limite_inf(const sf::Vector2f &pos);

        //void update() override;
        bool isCollision(const Collisionable& _object)const;
        void draw(sf::RenderWindow &w) override;

        sf::FloatRect getBounds() const;
    private:

        sf::RectangleShape limit;
};

#endif // LIMITE_INF_H
