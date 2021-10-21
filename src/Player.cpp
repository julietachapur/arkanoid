#include "Player.h"
#include <SFML/Window/Keyboard.hpp>

Player::Player(const sf::Vector2f &pos){
    texPlayer.loadFromFile("assets/images/nave.png");
    spPlayer.setTexture(texPlayer);
    spPlayer.setPosition(pos);
    spPlayer.setScale(0.2,0.08);
    spPlayer.setOrigin(20/2.f, 2/2.f);
}

void Player::update(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        spPlayer.move(2,0);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        spPlayer.move(-2,0);
    }
}

void Player::draw(sf::RenderWindow &w){
    w.draw(spPlayer);
}
bool Player::isCollision(const Collisionable& _object)const{
   return getBounds().intersects(_object.getBounds());
}

sf::Sprite &Player::getSprite(){
    return spPlayer;}

sf::FloatRect Player::getBounds()const{
    sf::FloatRect rect= spPlayer.getGlobalBounds();
    rect.left = spPlayer.getPosition().x;
    rect.top = spPlayer.getPosition().y;
    return rect;}
