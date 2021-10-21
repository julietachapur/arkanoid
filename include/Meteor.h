#ifndef METEOR_H
#define METEOR_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <time.h>
#include "Object.h"
#include "Defender_L.h"
#include "Defender_R.h"
#include "Barrel.h"
#include "Spaceship.h"
#include "Meteor.h"
#include "Collisionable.h"

class Meteor: public Object ,public Collisionable{
    public:
        Meteor();
        void update() override;
        bool isCollision(const Collisionable& _object)const;
        void moveMeteor(const Collisionable& p);
        sf::FloatRect getBounds() const;
        void draw(sf::RenderWindow &w) override;
        const sf::Vector2f& getVelocity()const;
        sf::Sprite &getSprite();
        sf::Vector2f velMeteor;

    private:
        sf::Sprite spMeteor;
        sf::Texture texMeteor;

};

#endif // METEOR_H
