#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Object.h"
#include "Ball.h"
#include "Player.h"
#include "Collisionable.h"
class Player:public Object ,public Collisionable{
    public:
        Player(const sf::Vector2f &pos);
        void update();
        bool isCollision(const Collisionable& _object)const;
        void draw(sf::RenderWindow &w) override;
        sf::FloatRect getBounds() const;
        sf::Vector2f velocity;
        sf::Sprite &getSprite();
         sf::Vector2f getPos();


    private:
        float playerVelocity = 5;
        sf::Sprite spPlayer;
        sf::Texture texPlayer;
};

#endif // PLAYER_H
