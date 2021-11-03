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
    spPlayer.move(velocity);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        if(getBounds().left<=0){
            velocity.x = playerVelocity;
        }
        else{
            velocity.x= -playerVelocity;
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        if(getBounds().left + 100>=400){//harcodeado hay que modificar esto
            velocity.x = -playerVelocity;
        }
        else{
            velocity.x= playerVelocity;
        }
    }
    else{
        velocity.x = 0;
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


sf::Vector2f Player::getPos(){
return spPlayer.getPosition();

}
