#include "../include/Spaceship.h"
#include <SFML/Window/Keyboard.hpp>
Spaceship::Spaceship(const sf::Vector2f &pos){
    texSpaceship.loadFromFile("assets/images/spaceship.png");
    spSpaceship.setTexture(texSpaceship);
    spSpaceship.setPosition(pos);
    spSpaceship.setScale(0.2,0.2);
}

void Spaceship::update(){}

void Spaceship::draw(sf::RenderWindow &w){
    w.draw(spSpaceship);
}
bool Spaceship::isCollision(const Collisionable& _object)const{
   return getBounds().intersects(_object.getBounds());
}

sf::Sprite &Spaceship::getSprite(){
    return spSpaceship;}

sf::FloatRect Spaceship::getBounds()const{
    sf::FloatRect rect= spSpaceship.getGlobalBounds();
    rect.left = spSpaceship.getPosition().x;
    rect.top = spSpaceship.getPosition().y;
    return rect;}
