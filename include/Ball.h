#ifndef BALL_H
#define BALL_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <time.h>
#include "Player.h"
#include "Object.h"
#include "Ball.h"
#include "Collisionable.h"

class Ball: public Object ,public Collisionable{
    public:
        Ball();
        void update() override;
        bool isCollision(const Collisionable& _object)const;
        void moveBall(const Collisionable& p);
        void draw(sf::RenderWindow &w) override;
        const sf::Vector2f& getVelocity()const;
        sf::Vector2f velBall;
        sf::FloatRect getBounds() const;
        sf::CircleShape &getSprite();
        void dirChange();
        void dirChangeE();
        void reset();
        sf::Vector2f getPos();

    private:
        sf::CircleShape spBall;
        int toques=0;
};
#endif // BALL_H
