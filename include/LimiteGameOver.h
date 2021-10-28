#ifndef LIMITEGAMEOVER_H
#define LIMITEGAMEOVER_H
#define PLAYER_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Object.h"
#include "Collisionable.h"

class LimiteGameOver: public Object, public Collisionable
{
    public:
        LimiteGameOver();
        void update();
        bool isCollision(const Collisionable& _object)const;
        void draw(sf::RenderWindow &w) override;
        sf::FloatRect getBounds() const;

    private:
        sf::RectangleShape limit;
};

#endif // LIMITEGAMEOVER_H
