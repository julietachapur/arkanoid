#include "../include/Barrel.h"
#include <SFML/Window/Keyboard.hpp>

Barrel::Barrel(const sf::Vector2f &pos){
    texbarrel.loadFromFile("assets/images/barrel.png");
    spbarrel.setTexture(texbarrel);
    spbarrel.setPosition(pos);
}

void Barrel::update(){}

void Barrel::draw(sf::RenderWindow &w){
    w.draw(spbarrel);
}

sf::Sprite &Barrel::getSprite(){
    return spbarrel;}

bool Barrel::isCollision(const Collisionable& _object)const{
   return getBounds().intersects(_object.getBounds());
}

sf::FloatRect Barrel::getBounds()const{
    sf::FloatRect rect= spbarrel.getGlobalBounds();
    rect.left = spbarrel.getPosition().x;
    rect.top = spbarrel.getPosition().y;
    return rect;}

