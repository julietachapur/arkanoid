#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Object.h"
#include "Collisionable.h"

class Enemy: public Object, public Collisionable
{

public:
        Enemy(int x, int y);
        ~Enemy();
        void update() override;
        bool isCollision(const Collisionable& _object)const;
        void draw(sf::RenderWindow &w) override;
        sf::FloatRect getBounds() const;
        sf::Vector2f velocity;
        sf::Sprite &getSprite();
        void disapear();
private:
        sf::Sprite spEnemy;
        sf::Texture txtEnemy;

        bool slots_enemy;
};

#endif // ENEMY_H
