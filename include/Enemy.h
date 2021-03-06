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
        Enemy(int x, int y, int vidas);
        ~Enemy();
        void update() override;
        bool isCollision(const Collisionable& _object)const;
        void draw(sf::RenderWindow &w) override;
        sf::FloatRect getBounds() const;
        sf::Vector2f velocity;
        sf::Sprite &getSprite();
        void disapear();
        void changeColour();

        int getVidas();
        void disminuir();
        sf::Vector2f getPosition();
private:
        sf::Sprite spEnemy;
        sf::Texture txtEnemy;
        int _vidas;

        bool slots_enemy;
};

#endif // ENEMY_H
